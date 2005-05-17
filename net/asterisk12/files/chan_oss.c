/*
 * Asterisk -- A telephony toolkit for Linux.
 *
 * Copyright (C) 1999, Mark Spencer
 *
 * Mark Spencer <markster@linux-support.net>
 *
 * This program is free software, distributed under the terms of
 * the GNU General Public License
 *
 * FreeBSD changes and multiple device support by Luigi Rizzo, 2005.05.02
 * note-this code best seen with ts=8 (8-spaces tabs) in the editor
 */

#include <asterisk/lock.h>
#include <asterisk/frame.h>
#include <asterisk/logger.h>
#include <asterisk/channel.h>
#include <asterisk/module.h>
#include <asterisk/channel_pvt.h>
#include <asterisk/options.h>
#include <asterisk/pbx.h>
#include <asterisk/config.h>
#include <asterisk/cli.h>
#include <asterisk/utils.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/ioctl.h>
#include <sys/time.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>	/* for isalnum */
#ifdef __linux
#include <linux/soundcard.h>
#elif defined(__FreeBSD__)
#include <sys/soundcard.h>
#else
#include <soundcard.h>
#endif
#include "busy.h"
#include "ringtone.h"
#include "ring10.h"
#include "answer.h"

/*
 * Helper macros to parse config arguments. They will go in a common
 * header file if their usage is globally accepted. In the meantime,
 * we define them here. Typical usage is as below, WITHOUT ; on each line.
 *
 *      {
 *              M_START(v->name, v->value)
 *
 *              M_BOOL("dothis", x->flag1)
 *              M_STR("name", x->somestring)
 *              M_F("bar", some_c_code)
 *              M_END(some_final_statement)
 */
#define M_START(var, val) \
        char *__s = var; char *__val = val;
#define M_END(x)   x;
#define M_F(tag, f)             if (!strcasecmp((__s), tag)) { f; } else
#define M_BOOL(tag, dst)        M_F(tag, (dst) = ast_true(__val) )
#define M_UINT(tag, dst)        M_F(tag, (dst) = strtoul(__val, NULL, 0) )
#define M_STR(tag, dst)         M_F(tag, strncpy(dst, __val, sizeof(dst) - 1) )


/* Which device to use */
#if defined( __OpenBSD__ ) || defined( __NetBSD__ )
#define DEV_DSP "/dev/audio"
#else
#define DEV_DSP "/dev/dsp"
#endif

/*
 * Basic mode of operation:
 *
 * we have one keyboard (which receives commands from the keyboard)
 * and multiple headset's connected to audio cards. Headsets are named as
 * the sections of oss.conf
 *
 * At any time, the keyboard is attached to one headset, and you
 * can switch among them using the 'console' command.
 *
 * The following parameters are important for the configuration of
 * the device:
 *
 *  FRAME_SIZE	the size of an audio frame, in samples.
 *		160 is used almost universally, so you should not change it.
 *
 *  FRAGS	the argument for the SETFRAGMENT ioctl.
 *		Overridden by the 'frags' parameter in oss.conf
 *
 *		Bits 0-7 are the base-2 log of the device's block size,
 *		bits 16-31 are the number of blocks in the driver's queue.
 *		There are a lot of differences in the way this parameter
 *		is supported by different drivers, so you may need to
 *		experiment a bit with the value.
 *		A good default for linux is 30 blocks of 64 bytes, which
 *		results in 6 frames of 320 bytes (160 samples).
 *		FreeBSD works decently with blocks of 256 or 512 bytes,
 *		leaving the number unspecified.
 *		Note that this only refers to the device buffer size,
 *		this module will then try to keep the lenght of audio
 *		buffered within small constraints.
 *
 *  QUEUE_SIZE	The max number of blocks actually allowed in the device
 *		driver's buffer, irrespective of the available number.
 *		Overridden by the 'queuesize' parameter in oss.conf
 *
 *		Should be >=2, and at most as large as the hw queue above
 *		(otherwise it will never be full).
 */

#define FRAME_SIZE	160
#define	QUEUE_SIZE	10

#if defined(__FreeBSD__)
#define	FRAGS	0x8
#else
#define	FRAGS	( ( (6 * 5) << 16 ) | 0x6 )
#endif


/* Don't switch between read/write modes faster than every 300 ms */
#define MIN_SWITCH_TIME 300


static int usecnt;
AST_MUTEX_DEFINE_STATIC(usecnt_lock);

static char *desc = "OSS Console Channel Driver";
static char *tdesc = "OSS Console Channel Driver";
static char *config = "oss.conf";	/* default config file */

static int oss_debug;

/*
 * Each sound is made of 'datalen' samples of sound, repeated as needed to
 * generate 'samplen' samples of data, then followed by 'silencelen' samples
 * of silence. The loop is repeated if 'repeat' is set.
 */
struct sound {
	int ind;
	char *desc;
	short *data;
	int datalen;
	int samplen;
	int silencelen;
	int repeat;
};

static struct sound sounds[] = {
    { AST_CONTROL_RINGING, "RINGING", ringtone, sizeof(ringtone)/2, 16000, 32000, 1 },
    { AST_CONTROL_BUSY, "BUSY", busy, sizeof(busy)/2, 4000, 4000, 1 },
    { AST_CONTROL_CONGESTION, "CONGESTION", busy, sizeof(busy)/2, 2000, 2000, 1 },
    { AST_CONTROL_RING, "RING10", ring10, sizeof(ring10)/2, 16000, 32000, 1 },
    { AST_CONTROL_ANSWER, "ANSWER", answer, sizeof(answer)/2, 2200, 0, 0 },
    { -1, NULL, 0, 0, 0, 0 },	/* end marker */
};


/*
 * descriptor for one of our channels.
 * There is one used for 'default' values (from the [general] entry in
 * the configuration file, and then one instance for each device
 * (the default is cloned from [general], others are only created
 * if the relevant section exists.
 */
struct chan_oss_pvt {
    struct chan_oss_pvt *next;

    char *type;
    char *name;
    /*
     * cursound indicates which in struct sound we play. -1 means nothing,
     * any other value is a valid sound, in which case sampsent indicates
     * the next sample to send in [0..samplen + silencelen]
     * nosound is set to disable the audio data from the channel
     * (so we can play the tones etc.).
     */
    int sndcmd[2]; /* Sound command pipe */
    int cursound;	/* index of sound to send */
    int sampsent;	/* # of sound samples sent	*/
    int nosound;	/* set to block audio from the PBX */

    int total_blocks;	/* total blocks in the output device */
    int sounddev;
    enum { M_UNSET, M_FULL, M_READ, M_WRITE } duplex;
    int autoanswer;
    int autohangup;
    int hookstate;
    struct timeval lasttime;	/* last setformat */
    char *mixer_cmd;		/* initial command to issue to the mixer */
    unsigned int	queuesize;	/* max fragments in queue */
    unsigned int	frags;		/* parameter for SETFRAGMENT */

    int warned;		/* various flags used for warnings */
#define WARN_used_blocks	1
#define WARN_speed		2
#define WARN_frag		4
    int w_errors;	/* overfull in the write path */

    int silencesuppression;
    int silencethreshold;
    int playbackonly;
    char device[64];	/* device to open */

    pthread_t sthread;

    struct ast_channel *owner;
    char ext[AST_MAX_EXTENSION];
    char ctx[AST_MAX_EXTENSION];
    char language[MAX_LANGUAGE];

    /* buffers used in oss_write */
    char oss_write_buf[FRAME_SIZE*2];
    int oss_write_dst;
    /* buffers used in oss_read - AST_FRIENDLY_OFFSET space for headers
     * plus enough room for a full frame
     */
    char oss_read_buf[FRAME_SIZE * 2 + AST_FRIENDLY_OFFSET];
    int readpos; /* read position above */
    struct ast_frame read_f;	/* returned by oss_read */
};

static struct chan_oss_pvt oss_default = {
	.type = "Console",
	.cursound = -1,
	.sounddev = -1,
	.duplex = M_UNSET, /* XXX check this */
	.autoanswer = 1,
	.autohangup = 1,
	.queuesize = QUEUE_SIZE,
	.frags = FRAGS,
	.silencethreshold = 1000,	/* currently unused */
	.ext = "s",
	.ctx = "default",
	.readpos = AST_FRIENDLY_OFFSET,	/* start here on reads */
};

static char *oss_active;	 /* the active device */

/*
 * returns true if too early to switch
 */
static int too_early(struct chan_oss_pvt *o)
{
	struct timeval tv;
	int ms;
	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec - o->lasttime.tv_sec) * 1000 +
			(tv.tv_usec - o->lasttime.tv_usec) / 1000;
	if (ms < MIN_SWITCH_TIME)
		return -1;
	return 0;
}

/*
 * Returns the number of blocks used in the audio output channel
 */
static int used_blocks(struct chan_oss_pvt *o)
{
    struct audio_buf_info info;

    if (ioctl(o->sounddev, SNDCTL_DSP_GETOSPACE, &info)) {
	if (! (o->warned & WARN_used_blocks)) {
	    ast_log(LOG_WARNING, "Error reading output space\n");
	    o->warned |= WARN_used_blocks;
	}
	return 1;
    }
    if (o->total_blocks == 0) {
	if (0) /* debugging */
	    ast_log(LOG_WARNING, "fragtotal %d size %d avail %d\n",
			info.fragstotal,
			info.fragsize,
			info.fragments);
		o->total_blocks = info.fragments;
    }
    return o->total_blocks - info.fragments;
}

static int soundcard_writeframe(struct chan_oss_pvt *o, short *data)
{	
    /* Write an exactly FRAME_SIZE sized frame */
    int res;

    /*
     * Nothing complex to manage the audio device queue.
     * If the buffer is full just drop the extra, otherwise write.
     * XXX in some cases it might be useful to write anyways after
     * a number of failures, to restart the output chain.
     */
    res = used_blocks(o);
    if (res > o->queuesize) {	/* no room to write a block */
	if (o->w_errors++ == 0 && (oss_debug & 0x4))
	    ast_log(LOG_WARNING, "write: used %d blocks (%d)\n",
		res, o->w_errors);
	return 0;
    }
    o->w_errors = 0;
    res = write(o->sounddev, ((void *)data), FRAME_SIZE * 2);
    return res;
}

/*
 * handler for 'sound writable' events from the sound thread.
 * Builds a frame from the high level description of the sounds,
 * and passes it to the audio device.
 * The actual sound is made of 1 or more sequences of sound samples
 * (s->datalen, repeated to make s->samplen samples) followed by
 * s->silencelen samples of silence. The position in the sequence is stored
 * in o->sampsent, which goes between 0 .. s->samplen+s->silencelen.
 * In case we fail to write a frame, don't update o->sampsent.
 */
static void send_sound(struct chan_oss_pvt *o)
{
	short myframe[FRAME_SIZE];
	int ofs, l, start;
	int l_sampsent = o->sampsent;
	struct sound *s;

	if (o->cursound < 0)	/* no sound to send */
		return;
	s = &sounds[o->cursound];
	for (ofs = 0; ofs < FRAME_SIZE; ofs += l) {
	    l = s->samplen - l_sampsent;	/* sound available */
	    if (l > 0) {
		start = l_sampsent % s->datalen; /* source offset */
		if (l > FRAME_SIZE - ofs)	/* don't overflow the frame */
		    l = FRAME_SIZE - ofs;
		if (l > s->datalen - start)	/* don't overflow the source */
		    l = s->datalen - start;
		bcopy(s->data + start, myframe + ofs, l*2);
		if (0)
		ast_log(LOG_WARNING, "send_sound sound %d/%d of %d into %d\n",
			l_sampsent, l, s->samplen, ofs);
		l_sampsent += l;
	    } else { /* no sound, maybe some silence */
		static short silence[FRAME_SIZE] = {0, };

	        l += s->silencelen;
		if (l > 0) {
		    if (l > FRAME_SIZE - ofs)
			l = FRAME_SIZE - ofs;
		    bcopy(silence, myframe + ofs, l*2);
		    l_sampsent += l;
		} else { /* silence is over, restart sound if loop */
		    if (s->repeat == 0) {	/* last block */
			o->cursound = -1;
			o->nosound = 0;	/* allow audio data */
			if (ofs < FRAME_SIZE)	/* pad with silence */
			    bcopy(silence, myframe + ofs, (FRAME_SIZE - ofs)*2);
		    }
		    l_sampsent = 0;
		}
	    }
	}
	l = soundcard_writeframe(o, myframe);
	if (l > 0)
	    o->sampsent = l_sampsent;	/* update status */
}

static void *sound_thread(void *arg)
{
    char ign[4096];
    struct chan_oss_pvt *o = (struct chan_oss_pvt *)arg;

    /* kick the driver by trying to read from it. Ignore errors */
    read(o->sounddev, ign, sizeof(ign));
    for(;;) {
	fd_set rfds, wfds;
	int maxfd, res;

	FD_ZERO(&rfds);
	FD_ZERO(&wfds);
	maxfd = o->sndcmd[0];	/* pipe from the main process */
	FD_SET(o->sndcmd[0], &rfds);
	if (!o->owner) { /* no one owns the audio, so we must drain it */
	    FD_SET(o->sounddev, &rfds);
	    if (o->sounddev > maxfd)
		maxfd = o->sounddev;
	}
	if (o->cursound > -1) {
	    FD_SET(o->sounddev, &wfds);
	    if (o->sounddev > maxfd)
		maxfd = o->sounddev;
	}
	/* ast_select emulates linux behaviour in terms of timeout handling */
	res = ast_select(maxfd + 1, &rfds, &wfds, NULL, NULL);
	if (res < 1) {
	    ast_log(LOG_WARNING, "select failed: %s\n",
				strerror(errno));
	    continue;
	}
	if (FD_ISSET(o->sndcmd[0], &rfds)) {
	    /* read which sound to play from the pipe */
	    int i, what = -1;

	    read(o->sndcmd[0], &what, sizeof(what));
	    for (i = 0; sounds[i].ind != -1; i++) {
		if (sounds[i].ind == what) {
		    o->cursound = i;
		    o->sampsent = 0;
		    o->nosound = 1; /* block audio from pbx */
		    break;
		}
	    }
	    if (sounds[i].ind == -1)
		ast_log(LOG_WARNING, "invalid sound index: %d\n", what);
	}
	if (FD_ISSET(o->sounddev, &rfds)) { /* read and ignore errors */
	    read(o->sounddev, ign, sizeof(ign));
	}
	if (FD_ISSET(o->sounddev, &wfds))
	    send_sound(o);
    }
    /* Never reached */
    return NULL;
}

/*
 * reset and close the device if opened,
 * then open and initialize it in the desired mode,
 * trigger reads and writes so we can start using it.
 */
static int setformat(struct chan_oss_pvt *o, int mode)
{
    int fmt, desired, res, fd;

    if (o->sounddev >= 0) {
	ioctl(o->sounddev, SNDCTL_DSP_RESET, 0);
	close(o->sounddev);
	o->duplex = M_UNSET;
    }
    fd = o->sounddev = open(o->device, mode |O_NONBLOCK);
    if (o->sounddev < 0) {
	ast_log(LOG_WARNING, "Unable to re-open DSP device: %s\n",
		strerror(errno));
	return -1;
    }

    gettimeofday(&o->lasttime, NULL);
    fmt = AFMT_S16_LE;
    res = ioctl(fd, SNDCTL_DSP_SETFMT, &fmt);
    if (res < 0) {
	ast_log(LOG_WARNING, "Unable to set format to 16-bit signed\n");
	return -1;
    }
    switch (mode) {
    case O_RDWR:
	res = ioctl(fd, SNDCTL_DSP_SETDUPLEX, 0);
	/* Check to see if duplex set (FreeBSD Bug)*/
	res = ioctl(fd, SNDCTL_DSP_GETCAPS, &fmt);
	if (res == 0 && (fmt & DSP_CAP_DUPLEX)) {
	    if (option_verbose > 1) 
		ast_verbose(VERBOSE_PREFIX_2 "Console is full duplex\n");
	    o->duplex = M_FULL;
	};
	break;
    case O_WRONLY:
	o->duplex = M_WRITE;
	break;
    case O_RDONLY:
	o->duplex = M_READ;
	break;
    }

    fmt = 0;
    res = ioctl(fd, SNDCTL_DSP_STEREO, &fmt);
    if (res < 0) {
	ast_log(LOG_WARNING, "Failed to set audio device to mono\n");
	return -1;
    }
    /* 8000 Hz desired */
    desired = 8000;
    fmt = desired;
    res = ioctl(fd, SNDCTL_DSP_SPEED, &fmt);

    if (res < 0) {
	ast_log(LOG_WARNING, "Failed to set audio device to mono\n");
	return -1;
    }
    if (fmt != desired) {
	if (!(o->warned & WARN_speed)) {
	    ast_log(LOG_WARNING,
		"Requested %d Hz, got %d Hz -- sound may be choppy\n",
		desired, fmt);
	    o->warned |= WARN_speed;
	}
    }
    /*
     * on Freebsd, SETFRAGMENT does not work very well on some cards.
     * Default to use 256 bytes, let the user override
     */
    if (o->frags) {
	fmt = o->frags;
	res = ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &fmt);
	if (res < 0) {
	    if (!(o->warned & WARN_frag)) {
		ast_log(LOG_WARNING,
		    "Unable to set fragment size -- sound may be choppy\n");
		o->warned |= WARN_frag;
	    }
	}
    }
    /* XXX on some cards, we need SNDCTL_DSP_SETTRIGGER to start outputting */
    res = PCM_ENABLE_INPUT | PCM_ENABLE_OUTPUT;
    res = ioctl(fd, SNDCTL_DSP_SETTRIGGER, &res);
    /* it may fail if we are in half duplex, never mind */
    return 0;
}

/*
 * make sure output mode is available. Returns 0 if done,
 * 1 if too early to switch, -1 if error
 */
static int soundcard_setoutput(struct chan_oss_pvt *o, int force)
{
    if (o->duplex == M_FULL || (o->duplex == M_WRITE && !force))
	return 0;
    if (!force && too_early(o))
	return 1;
    if (setformat(o, O_WRONLY))
	return -1;
    return 0;
}

/*
 * make sure input mode is available. Returns 0 if done
 * 1 if too early to switch, -1 if error
 */
static int soundcard_setinput(struct chan_oss_pvt *o, int force)
{
    if (o->duplex == M_FULL || (o->duplex == M_READ && !force))
	return 0;
    if (!force && too_early(o))
	return 1;
    if (setformat(o, O_RDONLY))
	return -1;
    return 0;
}

/*
 * some of the standard methods supported by channels.
 */
static int oss_digit(struct ast_channel *c, char digit)
{
    /* no better use for received digits than print them */
    ast_verbose( " << Console Received digit %c >> \n", digit);
    return 0;
}

static int oss_text(struct ast_channel *c, char *text)
{
    /* print received messages */
    ast_verbose( " << Console Received text %s >> \n", text);
    return 0;
}

/* Play ringtone 'x' on device 'o' */
#define	RING(o, x) { int what = x; write((o)->sndcmd[1], &what, sizeof(what)); }

/*
 * handler for incoming calls. Either autoanswer, or start ringing
 */
static int oss_call(struct ast_channel *c, char *dest, int timeout)
{
    struct chan_oss_pvt *o = c->pvt->pvt;
    struct ast_frame f = { 0, };

    ast_verbose( " << Call placed to '%s' on console >> \n", dest);
    if (o->autoanswer) {
	ast_verbose( " << Auto-answered >> \n" );
	f.frametype = AST_FRAME_CONTROL;
	f.subclass = AST_CONTROL_ANSWER;
	ast_queue_frame(c, &f);
    } else {
	ast_verbose(" << Type 'answer' to answer, or use 'autoanswer' for future calls >> \n");
	f.frametype = AST_FRAME_CONTROL;
	f.subclass = AST_CONTROL_RINGING;
	ast_queue_frame(c, &f);
	RING(o, AST_CONTROL_RING);
    }
    return 0;
}

/*
 * remote side answered the phone
 */
static int oss_answer(struct ast_channel *c)
{
    struct chan_oss_pvt *o = c->pvt->pvt;

    ast_verbose( " << Console call has been answered >> \n");
#if 0
    /* play an answer tone (XXX do we really need it ?) */
    RING(o, AST_CONTROL_ANSWER);
#endif
    ast_setstate(c, AST_STATE_UP);
    o->cursound = -1;
    o->nosound=0;
    return 0;
}

static int oss_hangup(struct ast_channel *c)
{
    struct chan_oss_pvt *o = c->pvt->pvt;

    o->cursound = -1;
    c->pvt->pvt = NULL;
    o->owner = NULL;
    ast_verbose( " << Hangup on console >> \n");
    ast_mutex_lock(&usecnt_lock);	/* XXX not sure why */
    usecnt--;
    ast_mutex_unlock(&usecnt_lock);
    if (o->hookstate) {
	if (o->autoanswer || o->autohangup) {
	    /* Assume auto-hangup too */
	    o->hookstate = 0;
	} else {
	    /* Make congestion noise */
	    RING(o, AST_CONTROL_CONGESTION);
	}
    }
    return 0;
}

/* used for data coming from the network */
static int oss_write(struct ast_channel *c, struct ast_frame *f)
{
    int res;
    int src;
    struct chan_oss_pvt *o = c->pvt->pvt;

    /* Immediately return if no sound is enabled */
    if (o->nosound)
	return 0;
    /* Stop any currently playing sound */
    o->cursound = -1;
    if (o->duplex != M_FULL && !o->playbackonly) {
	/* XXX check this, looks weird! */
	/* If we're half duplex, we have to switch to read mode
	   to honor immediate needs if necessary */
	res = soundcard_setinput(o, 1); /* force set if not full_duplex */
	if (res < 0) {
	    ast_log(LOG_WARNING, "Unable to set device to input mode\n");
	    return -1;
	}
	return 0;
    }
    res = soundcard_setoutput(o, 0);
    if (res < 0) {
	ast_log(LOG_WARNING, "Unable to set output device\n");
	return -1;
    } else if (res > 0) {
	/* The device is still in read mode, and it's too soon to change it,
	   so just pretend we wrote it */
	return 0;
    }
    /*
     * we could receive a sample which is not a multiple of our FRAME_SIZE,
     * so we buffer it locally and write to the device in FRAME_SIZE
     * chunks, keeping the residue stored for future use.
     */
    src = 0; /* read position into f->data */
    while ( src < f->datalen ) {
	/* Compute spare room in the buffer */
	int l = sizeof(o->oss_write_buf) - o->oss_write_dst;

	if (f->datalen - src >= l) {	/* enough to fill a frame */
	    memcpy(o->oss_write_buf + o->oss_write_dst,
		    f->data + src, l);
	    soundcard_writeframe(o, (short *)o->oss_write_buf);
	    src += l;
	    o->oss_write_dst = 0;
	} else { /* copy residue */
	    l = f->datalen - src;
	    memcpy(o->oss_write_buf + o->oss_write_dst,
		    f->data + src, l);
	    src += l;	/* but really, we are done */
	    o->oss_write_dst += l;
	}
    }
    return 0;
}

static struct ast_frame *oss_read(struct ast_channel *c)
{
    int res;
    struct chan_oss_pvt *o = c->pvt->pvt;
    struct ast_frame *f = &o->read_f;

    /* prepare a NULL frame in case we don't have enough data to return */
    bzero(f, sizeof(struct ast_frame));
    f->frametype = AST_FRAME_NULL;
    f->src = o->type;

    res = soundcard_setinput(o, 0);
    if (res < 0) {
	ast_log(LOG_WARNING, "Unable to set input mode\n");
	return NULL;
    } else if (res > 0) {	/* too early to switch ? */
	/* Theoretically shouldn't happen, but anyway, return a NULL frame */
	return f;
    }

    res = read(o->sounddev, o->oss_read_buf + o->readpos,
		sizeof(o->oss_read_buf) - o->readpos);
    if (res < 0)	/* audio data not ready, return a NULL frame */
	return f;

    o->readpos += res;
    if (o->readpos < sizeof(o->oss_read_buf))	/* not enough samples */
	return f;

    o->readpos = AST_FRIENDLY_OFFSET;	/* reset read pointer for next frame */
    if (c->_state != AST_STATE_UP)	/* drop data if frame is not up */
	return f;
    /* ok we can build and deliver the frame to the caller */
    f->frametype = AST_FRAME_VOICE;
    f->subclass = AST_FORMAT_SLINEAR;
    f->samples = FRAME_SIZE;
    f->datalen = FRAME_SIZE * 2;
    f->data = o->oss_read_buf + AST_FRIENDLY_OFFSET;
    f->offset = AST_FRIENDLY_OFFSET;
    return f;
}

static int oss_fixup(struct ast_channel *oldchan, struct ast_channel *newchan)
{
	struct chan_oss_pvt *o = newchan->pvt->pvt;
	o->owner = newchan;
	return 0;
}

static int oss_indicate(struct ast_channel *c, int cond)
{
    struct chan_oss_pvt *o = c->pvt->pvt;
    int res;

    switch(cond) {
    case AST_CONTROL_BUSY:
    case AST_CONTROL_CONGESTION:
    case AST_CONTROL_RINGING:
	res = cond;
	break;
    case -1:
	o->cursound = -1;
	return 0;
    default:
	ast_log(LOG_WARNING,
		"Don't know how to display condition %d on %s\n",
		cond, c->name);
	return -1;
    }
    if (res > -1)
	RING(o, res);
    return 0;	
}

static struct ast_channel *oss_new(struct chan_oss_pvt *o,
	char *ext, char *ctx, int state)
{
    struct ast_channel *c;
    struct ast_channel_pvt *pvt;

    c = ast_channel_alloc(1);
    if (c == NULL)
	return NULL;
    snprintf(c->name, sizeof(c->name), "OSS/%s", o->device + 5);
    c->type = o->type;
    c->fds[0] = o->sounddev;
    c->nativeformats = AST_FORMAT_SLINEAR;
    pvt = c->pvt;
    pvt->pvt = o;

    /* relevant callbacks */
    pvt->send_digit = oss_digit;
    pvt->send_text = oss_text;
    pvt->hangup = oss_hangup;
    pvt->answer = oss_answer;
    pvt->read = oss_read;
    pvt->call = oss_call;
    pvt->write = oss_write;
    pvt->indicate = oss_indicate;
    pvt->fixup = oss_fixup;

#define S_OVERRIDE(dst, src) \
	{ if (src && src[0] != '\0')  /* non-empty string */ \
		strncpy((dst), src, sizeof(dst)-1); }
    S_OVERRIDE(c->context, ctx);
    S_OVERRIDE(c->exten, ext);
    S_OVERRIDE(c->language, o->language);
    o->owner = c;
    ast_setstate(c, state);
    ast_mutex_lock(&usecnt_lock);
    usecnt++;
    ast_mutex_unlock(&usecnt_lock);
    ast_update_use_count();
    if (state != AST_STATE_DOWN) {
	if (ast_pbx_start(c)) {
	    ast_log(LOG_WARNING, "Unable to start PBX on %s\n", c->name);
	    ast_hangup(c);
	    o->owner = c = NULL;
	    /* XXX what about the channel itself ? */
	    /* XXX what about usecnt ? */
	}
    }
    return c;
}

/*
 * returns a pointer to the descriptor with the given name
 */
static struct chan_oss_pvt *find_desc(char *dev)
{
    struct chan_oss_pvt *o;

    for (o = oss_default.next; o && strcmp(o->name, dev) != 0; o = o->next)
	;
    if (o == NULL)
	ast_log(LOG_WARNING, "%s could not find <%s>\n", __func__, dev);
    return o;
}

static struct ast_channel *oss_request(char *type, int format, void *data)
{
    struct ast_channel *c;
    struct chan_oss_pvt *o = find_desc(data);

    ast_log(LOG_WARNING, "oss_request ty <%s> data 0x%p <%s>\n",
		type, data, (char *)data);
    if (o == NULL) {
	ast_log(LOG_NOTICE, "Device %s not found\n", (char *)data);
	/* XXX we could default to 'dsp' perhaps ? */
	return NULL;
    }
    if ((format & AST_FORMAT_SLINEAR) == 0) {
	ast_log(LOG_NOTICE, "Format 0x%x unsupported\n", format);
	return NULL;
    }
    if (o->owner) {
	ast_log(LOG_NOTICE, "Already have a call on the OSS channel\n");
	return NULL;
    }
    c= oss_new(o, NULL, NULL, AST_STATE_DOWN);
    if (c == NULL) {
	ast_log(LOG_WARNING, "Unable to create new OSS channel\n");
	return NULL;
    }
    return c;
}

static int console_autoanswer(int fd, int argc, char *argv[])
{
    struct chan_oss_pvt *o = find_desc(oss_active);

    if ((argc != 1) && (argc != 2))
	return RESULT_SHOWUSAGE;
    if (o == NULL) {
	ast_log(LOG_WARNING, "Cannot find device %s (should not happen!)\n",
			oss_active);
	return RESULT_FAILURE;
    }
    if (argc == 1) {
	ast_cli(fd, "Auto answer is %s.\n", o->autoanswer ? "on" : "off");
	return RESULT_SUCCESS;
    }
    if (!strcasecmp(argv[1], "on"))
	o->autoanswer = -1;
    else if (!strcasecmp(argv[1], "off"))
	o->autoanswer = 0;
    else
	return RESULT_SHOWUSAGE;
    return RESULT_SUCCESS;
}

static char *autoanswer_complete(char *line, char *word, int pos, int state)
{
#ifndef MIN
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#endif
	int l = strlen(word);

	switch(state) {
	case 0:
		if (l && !strncasecmp(word, "on", MIN(l, 2)))
			return strdup("on");
	case 1:
		if (l && !strncasecmp(word, "off", MIN(l, 3)))
			return strdup("off");
	default:
		return NULL;
	}
	return NULL;
}

static char autoanswer_usage[] =
"Usage: autoanswer [on|off]\n"
"       Enables or disables autoanswer feature.  If used without\n"
"       argument, displays the current on/off status of autoanswer.\n"
"       The default value of autoanswer is in 'oss.conf'.\n";

/*
 * answer command from the console
 */
static int console_answer(int fd, int argc, char *argv[])
{
	struct ast_frame f = { AST_FRAME_CONTROL, AST_CONTROL_ANSWER };
	struct chan_oss_pvt *o = find_desc(oss_active);

	if (argc != 1)
		return RESULT_SHOWUSAGE;
	if (!o->owner) {
		ast_cli(fd, "No one is calling us\n");
		return RESULT_FAILURE;
	}
	o->hookstate = 1;
	o->cursound = -1;
	ast_queue_frame(o->owner, &f);
    	RING(o, AST_CONTROL_ANSWER);
	return RESULT_SUCCESS;
}

static char sendtext_usage[] =
"Usage: send text <message>\n"
"       Sends a text message for display on the remote terminal.\n";

static int console_sendtext(int fd, int argc, char *argv[])
{
	struct chan_oss_pvt *o = find_desc(oss_active);
	int tmparg = 2;
	char text2send[256] = "";
	struct ast_frame f = { 0, };

	if (argc < 2)
		return RESULT_SHOWUSAGE;
	if (!o->owner) {
		ast_cli(fd, "No one is calling us\n");
		return RESULT_FAILURE;
	}
	if (strlen(text2send))
		ast_cli(fd, "Warning: message already waiting to be sent, overwriting\n");
	text2send[0] = '\0';
	while(tmparg < argc) {
		strncat(text2send, argv[tmparg++], sizeof(text2send) - strlen(text2send) - 1);
		strncat(text2send, " ", sizeof(text2send) - strlen(text2send) - 1);
	}
	if (strlen(text2send)) {
		f.frametype = AST_FRAME_TEXT;
		f.subclass = 0;
		f.data = text2send;
		f.datalen = strlen(text2send);
		ast_queue_frame(o->owner, &f);
	}
	return RESULT_SUCCESS;
}

static char answer_usage[] =
"Usage: answer\n"
"       Answers an incoming call on the console (OSS) channel.\n";

static int console_hangup(int fd, int argc, char *argv[])
{
	struct chan_oss_pvt *o = find_desc(oss_active);

	if (argc != 1)
		return RESULT_SHOWUSAGE;
	o->cursound = -1;
	if (!o->owner && !o->hookstate) {
		ast_cli(fd, "No call to hangup up\n");
		return RESULT_FAILURE;
	}
	o->hookstate = 0;
	if (o->owner) {
		ast_queue_hangup(o->owner);
	}
	return RESULT_SUCCESS;
}

static char hangup_usage[] =
"Usage: hangup\n"
"       Hangs up any call currently placed on the console.\n";


static int console_flash(int fd, int argc, char *argv[])
{
	struct ast_frame f = { AST_FRAME_CONTROL, AST_CONTROL_FLASH };
	struct chan_oss_pvt *o = find_desc(oss_active);

	if (argc != 1)
		return RESULT_SHOWUSAGE;
	o->cursound = -1;
	if (!o->owner) { /* XXX maybe !o->hookstate too ? */
		ast_cli(fd, "No call to flash\n");
		return RESULT_FAILURE;
	}
	o->hookstate = 0;
	if (o->owner) { /* XXX must be true, right ? */
		ast_queue_frame(o->owner, &f);
	}
	return RESULT_SUCCESS;
}


static char flash_usage[] =
"Usage: flash\n"
"       Flashes the call currently placed on the console.\n";



static int console_dial(int fd, int argc, char *argv[])
{
    char *tmp = NULL, *mye = NULL, *myc = NULL;
    int i;
    struct ast_frame f = { AST_FRAME_DTMF, 0 };
    struct chan_oss_pvt *o = find_desc(oss_active);

    if ((argc != 1) && (argc != 2))
	return RESULT_SHOWUSAGE;
    if (o->owner) {	/* already in a call */
	if (argc == 1) {	/* argument is mandatory here */
	    ast_cli(fd, "Already in a call. You can only dial digits until you hangup.\n");
	    return RESULT_FAILURE;
	}
	mye = argv[1];
	/* send the string one char at a time */
	for (i=0; i<strlen(mye); i++) {
	    f.subclass = mye[i];
	    ast_queue_frame(o->owner, &f);
	}
	return RESULT_SUCCESS;
    }
    /* if we have an argument split it into extension and context */

    if (argc == 2) {
	tmp = myc = strdup(argv[1]); /* make a writable copy */
	mye = strsep(&myc, "@");	/* set exten, advance to context */
	myc = strsep(&myc, "@");	/* set context */
    }
    /* supply default values if needed */
    if (mye == NULL)
	mye = o->ext;
    if (myc == NULL)
	myc = o->ctx;
    if (ast_exists_extension(NULL, myc, mye, 1, NULL)) {
	o->hookstate = 1;
	oss_new(o, mye, myc, AST_STATE_RINGING);
    } else
	ast_cli(fd, "No such extension '%s' in context '%s'\n", mye, myc);
    return RESULT_SUCCESS;
}

static char dial_usage[] =
"Usage: dial [extension[@context]]\n"
"       Dials a given extensison (and context if specified)\n";

static int console_transfer(int fd, int argc, char *argv[])
{
    struct chan_oss_pvt *o = find_desc(oss_active);
    struct ast_channel *b = NULL;
    char *ext, *ctx;

    if (argc != 2)
	return RESULT_SHOWUSAGE;
    if (o == NULL)
	return RESULT_FAILURE;
    if (o->owner == NULL || (b = o->owner->bridge) == NULL) {
	ast_cli(fd, "There is no call to transfer\n");
	return RESULT_SUCCESS;
    }

    ext = ctx = strdup(argv[1]);	/* make a writable copy */
    strsep(&ctx, "@");			/* set exten, advance to context */
    ctx = strsep(&ctx, "@");		/* strip trailing @ and the rest */

    if (ctx == NULL)			/* supply default context if needed */
	ctx = o->owner->context;
    if (!ast_exists_extension(b, ctx, ext, 1, b->callerid)) {
	ast_cli(fd, "No such extension exists\n");
    } else {
	ast_cli(fd, "Whee, transferring %s to %s@%s.\n", b->name, ext, ctx);
	if (ast_async_goto(b, ctx, ext, 1))
	    ast_cli(fd, "Failed to transfer :(\n");
    }
    free(ext);
    return RESULT_SUCCESS;
}

static char transfer_usage[] =
"Usage: transfer <extension>[@context]\n"
"       Transfers the currently connected call to the given extension (and\n"
"context if specified)\n";

static int console_active(int fd, int argc, char *argv[])
{
    if (argc == 1) {
	ast_cli(fd, "active console is [%s]\n", oss_active);
    } else if (argc != 2) {
	return RESULT_SHOWUSAGE;
    } else {
	struct chan_oss_pvt *o;
	if (strcmp(argv[1], "show") == 0) {
	    for (o = oss_default.next; o ; o = o->next)
		ast_cli(fd, "device [%s] exists\n", o->name);
	    return RESULT_SUCCESS;
	}
	o = find_desc(argv[1]);
	if (o == NULL)
	    ast_cli(fd, "No device [%s] exists\n", argv[1]);
	else
	    oss_active = o->name;
    }
    return RESULT_SUCCESS;
}

static struct ast_cli_entry myclis[] = {
	{ { "answer", NULL }, console_answer, "Answer an incoming console call", answer_usage },
	{ { "hangup", NULL }, console_hangup, "Hangup a call on the console", hangup_usage },
	{ { "flash", NULL }, console_flash, "Flash a call on the console", flash_usage },
	{ { "dial", NULL }, console_dial, "Dial an extension on the console", dial_usage },
	{ { "transfer", NULL }, console_transfer, "Transfer a call to a different extension", transfer_usage },
	{ { "send", "text", NULL }, console_sendtext, "Send text to the remote device", sendtext_usage },
	{ { "autoanswer", NULL }, console_autoanswer, "Sets/displays autoanswer", autoanswer_usage, autoanswer_complete },
	{ { "console", NULL }, console_active, "Sets/displays active console",
		"console foo sets foo as the console"}
};

/*
 * store the mixer argument from the config file, filtering possibly
 * invalid or dangerous values (the string is used as argument for
 * system("mixer %s")
 */
static void store_mixer(struct chan_oss_pvt *o, char *s)
{
    int i;

    for (i=0; i < strlen(s); i++) {
	if (!isalnum(s[i]) && index(" \t-/", s[i]) == NULL) {
	    ast_log(LOG_WARNING,
		"Suspect char %c in mixer cmd, ignoring:\n\t%s\n", s[i], s);
	    return;
	}
    }
    if (o->mixer_cmd)
	free(o->mixer_cmd);
    o->mixer_cmd = strdup(s);
    ast_log(LOG_WARNING, "setting mixer %s\n", s);
}

/*
 * grab fields from the config file, init the descriptor and open the device.
 */
static struct chan_oss_pvt * store_config(struct ast_config *cfg,
		char *ctg)
{
    struct ast_variable *v;
    struct chan_oss_pvt *o;

    if (ctg == NULL) {
	o = &oss_default;
	o->next = NULL; /* XXX needed ? */
	ctg = "general";
    } else {
	o = (struct chan_oss_pvt *)malloc(sizeof *o);
	if (o == NULL)		/* fail */
	    return NULL;
	*o = oss_default;
	/* "general" is also the default thing */
	if (strcmp(ctg, "general") == 0) {
	    o->name = strdup("dsp");
	    oss_active = o->name;
	    goto openit;
	}
	o->name = strdup(ctg);
    }
    ast_log(LOG_WARNING, "found category [%s]\n", ctg);

    /* fill other fields from configuration */
    v = ast_variable_browse(cfg, ctg);
    while(v) {
	M_START(v->name, v->value);

	M_BOOL("autoanswer", o->autoanswer)
	M_BOOL("autohangup", o->autohangup)
	M_BOOL("playbackonly", o->playbackonly)
	M_BOOL("silencesuppression", o->silencesuppression)
	M_UINT("silencethreshold", o->silencethreshold )
	M_STR("device", o->device)
	M_UINT("frags", o->frags)
	M_UINT("debug", oss_debug)
	M_UINT("queuesize", o->queuesize)
	M_STR("context", o->ctx)
	M_STR("language", o->language)
	M_STR("extension", o->ext)
	M_F("mixer", store_mixer(o, v->value))
	M_END(;);
	v=v->next;
    }
    if (!strlen(o->device))
	strncpy(o->device, DEV_DSP, sizeof(o->device)-1);
    if (o->mixer_cmd) {
	char *cmd;

	asprintf(&cmd, "mixer %s", o->mixer_cmd);
	ast_log(LOG_WARNING, "running [%s]\n", cmd);
	system(cmd);
	free(cmd);
    }
    if (o == &oss_default)	/* we are done with the default */
	return NULL;

openit:
    if (setformat(o, O_RDWR) < 0) {	/* open device */
	if (option_verbose > 0) {
	    ast_verbose(VERBOSE_PREFIX_2 "Device %s not detected\n", ctg);
	    ast_verbose(VERBOSE_PREFIX_2 "Turn off OSS support by adding "
		"'noload=chan_oss.so' in /etc/asterisk/modules.conf\n");
	}
	goto error;
    }
    soundcard_setinput(o, 1); /* force set if not full_duplex */
    if (o->duplex != M_FULL)
	ast_log(LOG_WARNING, "XXX I don't work right with non "
		"full-duplex sound cards XXX\n");
    if ( pipe(o->sndcmd) != 0 ) {
	ast_log(LOG_ERROR, "Unable to create pipe\n");
	goto error;
    }
    ast_pthread_create(&o->sthread, NULL, sound_thread, o);
    /* link into list of devices */
    if (o != &oss_default) {
	o->next = oss_default.next;
	oss_default.next = o;
    }
    return o;

error:
    if (o != &oss_default)
	free(o);
    return NULL;
}

int load_module()
{
    int i;
    struct ast_config *cfg;

    /* load config file */
    cfg = ast_load(config);
    if (cfg != NULL) {
	char *ctg;

	store_config(cfg, NULL);	/* init general category */
	ctg = ast_category_browse(cfg, NULL); /* initial category */
	while (ctg != NULL) {
	    store_config(cfg, ctg);
	    ctg = ast_category_browse(cfg, ctg);
	}
	ast_destroy(cfg);
    }
    if (find_desc(oss_active) == NULL) {
	ast_log(LOG_NOTICE, "Device %s not found\n", oss_active);
	/* XXX we could default to 'dsp' perhaps ? */
	/* XXX should cleanup allocated memory etc. */
	return -1;
    }
    i = ast_channel_register(oss_default.type, tdesc,
		AST_FORMAT_SLINEAR, oss_request);
    if (i < 0) {
	ast_log(LOG_ERROR, "Unable to register channel class '%s'\n",
		oss_default.type);
	 /* XXX should cleanup allocated memory etc. */
	return -1;
    }
    for (i=0; i<sizeof(myclis)/sizeof(struct ast_cli_entry); i++)
	    ast_cli_register(myclis + i);
    return 0;
}


int unload_module()
{
    int x;
    struct chan_oss_pvt *o;

    /* XXX do we need a ast_channel_unregister oss_request ? */
    for (x=0;x<sizeof(myclis)/sizeof(struct ast_cli_entry); x++)
	ast_cli_unregister(myclis + x);

    for (o = oss_default.next; o ; o = o->next) {
	close(o->sounddev);
	if (o->sndcmd[0] > 0) {
	    close(o->sndcmd[0]);
	    close(o->sndcmd[1]);
	}
	if (o->owner)
	    ast_softhangup(o->owner, AST_SOFTHANGUP_APPUNLOAD);
	if (o->owner) /* XXX how ??? */
	    return -1;
	/* XXX what about the thread ? */
	/* XXX what about the memory allocated ? */
    }
    return 0;
}

char *description()
{
	return desc;
}

int usecount()	/* XXX is this per-device or global for the module ? */
{
	int res;
	ast_mutex_lock(&usecnt_lock);
	res = usecnt;
	ast_mutex_unlock(&usecnt_lock);
	return res;
}

char *key()
{
	return ASTERISK_GPL_KEY;
}
