/*
 * FreeBSD video grab interface
 * Copyright (c) 2002 Steve O'Hara-Smith
 * based on
 *           Linux video grab interface
 *           Copyright (c) 2000,2001 Gerard Lantau.
 * and
 *           simple_grab.c Copyright (c) 1999 Roger Hardiman
 *
 * GPL virus inherited:
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */
#include "avformat.h"
#include <machine/ioctl_meteor.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/mman.h>
#include <sys/time.h>
#include <signal.h>

typedef struct {
	int fd;
	int tuner_fd;
	int frame_format; /* see VIDEO_PALETTE_xxx */
	int width, height;
	int frame_rate;
	int frame_size;
} VideoData;

const char *video_device = "/dev/bktr0";

#define GRABBER_SETTLE_TIME 3
#define PAL 1
#define NTSC 2
/* PAL is 768 x 576. NTSC is 640 x 480 */
#define PAL_HEIGHT 576
#define NTSC_HEIGHT 480

#ifndef VIDEO_FORMAT
#define VIDEO_FORMAT NTSC
#endif

#ifndef VIDEO_INPUT
#define VIDEO_INPUT METEOR_INPUT_DEV0;
#endif

static UINT8 *video_buf;

static int signal_expected = 0;
static int unexpected_signals = 0;

static void catchsignal(int signal)
{
	if (!signal_expected) unexpected_signals++;
	signal_expected = 0;
	return;
}

static int bktr_init(AVFormatContext *s1,  AVFormatParameters *ap)
{
	VideoData *s = s1->priv_data;
	int width, height;
	int video_fd;
	int format = VIDEO_FORMAT;
	struct meteor_geomet geo;
	int c;
	struct sigaction act,old;

	memset(&act,0,sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler  = catchsignal;
	sigaction(SIGUSR1,&act,&old);
	sigaction(SIGALRM,&act,&old);

	width = s->width;
	height = s->height;

	s->tuner_fd = open ("/dev/tuner0", O_RDWR);
	if (s->tuner_fd < 0) {
		perror("Warning: Tuner not opened continuing");
	}

	video_fd = open(video_device, O_RDWR);
	if (video_fd < 0) {
		perror(video_device);
		return -EIO;
	}
	s->fd=video_fd;
	geo.rows = height;
	geo.columns = width;
	geo.frames = 1;
	geo.oformat = METEOR_GEO_YUV_PACKED;

	if ((format == PAL) && (height <= (PAL_HEIGHT/2)))
		geo.oformat |= METEOR_GEO_EVEN_ONLY;
	if ((format == NTSC) && (height <= (NTSC_HEIGHT/2)))
		geo.oformat |= METEOR_GEO_EVEN_ONLY;

	if (ioctl(video_fd, METEORSETGEO, &geo) < 0) {
		perror ("METEORSETGEO");
		return -EIO;
	}

	switch (format) {
		case PAL:   c = METEOR_FMT_PAL; break;
		case NTSC:  c = METEOR_FMT_NTSC; break;
		default:    c = METEOR_FMT_PAL; break;
	}

	if (ioctl(video_fd, METEORSFMT, &c) < 0) {
		perror ("METEORSFMT");
		return -EIO;
	}

	c = VIDEO_INPUT;
	if (ioctl(video_fd, METEORSINPUT, &c) < 0) {
		perror ("METEORSINPUT");
		return -EIO;
	}
	video_buf = mmap((caddr_t)0, width*height*2, PROT_READ, MAP_SHARED,
	                 video_fd, (off_t) 0);
	if (video_buf == MAP_FAILED) {
		perror ("mmap");
		return -EIO;
	}
	c = METEOR_CAP_CONTINOUS;
	ioctl(s->fd, METEORCAPTUR, &c);
	c = SIGUSR1;
	signal_expected = 1;
	ioctl (s->fd, METEORSSIGNAL, &c);
	return 0;
}

static void bf_yuv422_to_yuv420p(UINT8 *lum, UINT8 *cb, UINT8 *cr,
                                 UINT8 *src, int width, int height)
{
	int x, y;
	UINT8 *p = src;
	for(y=0;y<height;y+=2) {
		for(x=0;x<width;x+=2) {
			lum[0] = p[1];
			cb[0] = p[0];
			lum[1] = p[3];
			cr[0] = p[2];
			p += 4;
			lum += 2;
			cb++;
			cr++;
		}
		for(x=0;x<width;x+=2) {
			lum[0] = p[1];
			lum[1] = p[3];
			p += 4;
			lum += 2;
		}
	}
}

/* note: we support only one picture read at a time */
static int grab_read_packet(AVFormatContext *s1, AVPacket *pkt)
{
	VideoData *s = s1->priv_data;
	int size, halfsize;
	sigset_t msig;
	UINT8 *lum, *cb, *cr;

	size = s->width * s->height;
	halfsize = size << 1;
	if (av_new_packet(pkt, size + halfsize) < 0)
		return -EIO;

	if (unexpected_signals > 0) {
		unexpected_signals--;
	} else {
		signal_expected = 1;
		sigemptyset (&msig);
		sigsuspend (&msig);
	}

	if (unexpected_signals & 1) {
		bzero (pkt->data,  size + halfsize);
	} else {
		lum = pkt->data;
		cb = lum + size;
		cr = cb + size/4;

		bf_yuv422_to_yuv420p (lum, cb, cr, video_buf, s->width, s->height);
	}
	return size + halfsize;
}

static int grab_read_header (AVFormatContext *s1,  AVFormatParameters *ap)
{
	VideoData *s = s1->priv_data;
	AVStream *st;
	int width, height;
	int frame_rate;

	if (!ap || ap->width <= 0 || ap->height <= 0 || ap->frame_rate <= 0)
		return -1;

	width = ap->width;
	height = ap->height;
	frame_rate = ap->frame_rate;
	st = av_new_stream(s1, 0);
	if (!st)
		return -ENOMEM;
	s1->priv_data = s;
	s1->nb_streams = 1;
	s1->streams[0] = st;

	s->width = width;
	s->height = height;
	s->frame_rate = frame_rate;
	s->frame_size = width*height*2;
	st->codec.pix_fmt = PIX_FMT_YUV420P;
	st->codec.codec_id = CODEC_ID_RAWVIDEO;
	st->codec.width = width;
	st->codec.height = height;
	st->codec.frame_rate = frame_rate;

	return bktr_init(s1, ap);
}

static int grab_read_close (AVFormatContext *s1)
{
	VideoData *s = s1->priv_data;

	int c = METEOR_CAP_STOP_CONT;
	ioctl(s->fd, METEORCAPTUR, &c);
	close(s->fd);
	close(s->tuner_fd);
	free(s);
	return 0;
}

AVInputFormat video_grab_device_format = {
	"video_grab_device",
	"video grab",
	 sizeof(VideoData),
	 NULL,
	grab_read_header,
	grab_read_packet,
	grab_read_close,
	flags: AVFMT_NOFILE,
};

int video_grab_init(void)
{
	av_register_input_format(&video_grab_device_format);
	return 0;
}
