
$FreeBSD$

--- channels/chan_oss.c
+++ channels/chan_oss.c
@@ -13,6 +13,8 @@
  *
  * This program is free software, distributed under the terms of
  * the GNU General Public License
+ *
+ * FreeBSD changes by Luigi Rizzo, 2005.04.18
  */
 
 #include <asterisk/lock.h>
@@ -54,21 +56,30 @@
 #endif
 
 /* Lets use 160 sample frames, just like GSM.  */
-#define FRAME_SIZE 160
+/* this corresponds to 20ms of audio. */
+#define FRAME_SIZE 160 // was 160
 
-/* When you set the frame size, you have to come up with
-   the right buffer format as well. */
+/*
+ * When you set the frame size, you have to come up with
+ * the right buffer format as well.
+ * OSS lets you define a 'block' size (which should be a power of 2,
+ * which power is specified in the lower 16 bits) and the number of
+ * blocks allowed in the buffer (to avoid that the queue grows too large).
+ * The latter is specified in the top 16 bits.
+ * We use a block of 64 bytes (0x6), 5 blocks make a frame each sample
+ * being 2 bytes, and we make room to store two buffers.
+ * XXX the '10' is magic
+ */
+
+#define N_BLOCKS	(buffersize * 5 * 2)
 /* 5 64-byte frames = one frame */
-#define BUFFER_FMT ((buffersize * 10) << 16) | (0x0006);
+#define BUFFER_FMT (N_BLOCKS << 16) | (0x0006);
 
 /* Don't switch between read/write modes faster than every 300 ms */
-#define MIN_SWITCH_TIME 600
+#define MIN_SWITCH_TIME 300
 
-static struct timeval lasttime;
 
 static int usecnt;
-static int silencesuppression = 0;
-static int silencethreshold = 1000;
 
 
 AST_MUTEX_DEFINE_STATIC(usecnt_lock);
@@ -78,16 +89,15 @@
 static char *tdesc = "OSS Console Channel Driver";
 static char *config = "oss.conf";
 
-static char context[AST_MAX_EXTENSION] = "default";
+static char default_context[AST_MAX_EXTENSION] = "default";
 static char language[MAX_LANGUAGE] = "";
-static char exten[AST_MAX_EXTENSION] = "s";
+static char oss_exten[AST_MAX_EXTENSION] = "s";
 
-static int hookstate=0;
 
-static short silence[FRAME_SIZE] = {0, };
 
 struct sound {
 	int ind;
+	char *desc;
 	short *data;
 	int datalen;
 	int samplen;
@@ -96,136 +106,178 @@
 };
 
 static struct sound sounds[] = {
-	{ AST_CONTROL_RINGING, ringtone, sizeof(ringtone)/2, 16000, 32000, 1 },
-	{ AST_CONTROL_BUSY, busy, sizeof(busy)/2, 4000, 4000, 1 },
-	{ AST_CONTROL_CONGESTION, busy, sizeof(busy)/2, 2000, 2000, 1 },
-	{ AST_CONTROL_RING, ring10, sizeof(ring10)/2, 16000, 32000, 1 },
-	{ AST_CONTROL_ANSWER, answer, sizeof(answer)/2, 2200, 0, 0 },
+	{ AST_CONTROL_RINGING, "RINGING", ringtone, sizeof(ringtone)/2, 16000, 32000, 1 },
+	{ AST_CONTROL_BUSY, "BUSY", busy, sizeof(busy)/2, 4000, 4000, 1 },
+	{ AST_CONTROL_CONGESTION, "CONGESTION", busy, sizeof(busy)/2, 2000, 2000, 1 },
+	{ AST_CONTROL_RING, "RING10", ring10, sizeof(ring10)/2, 16000, 32000, 1 },
+	{ AST_CONTROL_ANSWER, "ANSWER", answer, sizeof(answer)/2, 2200, 0, 0 },
+	{ -1, NULL, 0, 0, 0, 0 },	/* end marker */
 };
 
-/* Sound command pipe */
-static int sndcmd[2];
+
 
 static struct chan_oss_pvt {
 	/* We only have one OSS structure -- near sighted perhaps, but it
 	   keeps this driver as simple as possible -- as it should be. */
+    /*
+     * cursound indicates which in struct sound we play. -1 means nothing,
+     * any other value is a valid sound, in which case sampsent indicates
+     * the next sample to send in [0..samplen + silencelen]
+     * nosound is set to disable the audio data from the channel
+     * (so we can play the tones etc.).
+     */
+    int sndcmd[2]; /* Sound command pipe */
+    int cursound;	/* index of sound to send */
+    int sampsent;	/* # of sound samples sent	*/
+    int nosound;
+
+    int total_blocks;	/* total blocks in the output device */
+    int sounddev;
+    enum { M_UNSET, M_FULL, M_READ, M_WRITE } duplex;
+    int autoanswer;
+    int autohangup;
+    int hookstate;
+    struct timeval lasttime;	/* last setformat */
+
+    int silencesuppression;
+    int silencethreshold;
+	char device[64];	/* device to open */
+
+    pthread_t sthread;
+
 	struct ast_channel *owner;
 	char exten[AST_MAX_EXTENSION];
 	char context[AST_MAX_EXTENSION];
-} oss;
+} oss = {
+	.cursound = -1,
+	.sounddev = -1,
+	.duplex = M_UNSET, /* XXX check this */
+	.autoanswer = 1,
+	.autohangup = 1,
+	.silencethreshold = 1000,
+};
 
-static int time_has_passed(void)
+/*
+ * returns true if too early to switch
+ */
+static int too_early(struct chan_oss_pvt *o)
 {
 	struct timeval tv;
 	int ms;
 	gettimeofday(&tv, NULL);
-	ms = (tv.tv_sec - lasttime.tv_sec) * 1000 +
-			(tv.tv_usec - lasttime.tv_usec) / 1000;
-	if (ms > MIN_SWITCH_TIME)
+	ms = (tv.tv_sec - o->lasttime.tv_sec) * 1000 +
+			(tv.tv_usec - o->lasttime.tv_usec) / 1000;
+	if (ms < MIN_SWITCH_TIME)
 		return -1;
 	return 0;
 }
 
-/* Number of buffers...  Each is FRAMESIZE/8 ms long.  For example
-   with 160 sample frames, and a buffer size of 3, we have a 60ms buffer, 
-   usually plenty. */
-
-static pthread_t sthread;
-
-#define MAX_BUFFER_SIZE 100
-static int buffersize = 3;
-
-static int full_duplex = 0;
-
-/* Are we reading or writing (simulated full duplex) */
-static int readmode = 1;
-
-/* File descriptor for sound device */
-static int sounddev = -1;
-
-static int autoanswer = 1;
- 
-#if 0
-static int calc_loudness(short *frame)
+/*
+ * Returns the number of blocks used in the audio output channel
+ */
+static int
+used_blocks(struct chan_oss_pvt *o)
 {
-	int sum = 0;
-	int x;
-	for (x=0;x<FRAME_SIZE;x++) {
-		if (frame[x] < 0)
-			sum -= frame[x];
-		else
-			sum += frame[x];
+    struct audio_buf_info info;
+    static int warned=0;
+    if (ioctl(o->sounddev, SNDCTL_DSP_GETOSPACE, &info)) {
+	if (!warned) {
+	    ast_log(LOG_WARNING, "Error reading output space\n");
+	    warned++;
 	}
-	sum = sum/FRAME_SIZE;
-	return sum;
+	return 1;
+    }
+    if (o->total_blocks == 0) {
+	ast_log(LOG_WARNING, "fragtotal %d size %d avail %d\n",
+		info.fragstotal,
+		info.fragsize,
+		info.fragments);
+	o->total_blocks = info.fragments;
+    }
+    return o->total_blocks - info.fragments;
 }
-#endif
 
-static int cursound = -1;
-static int sampsent = 0;
-static int silencelen=0;
-static int offset=0;
-static int nosound=0;
+static int soundcard_writeframe(struct chan_oss_pvt *o, short *data)
+{	
+	/* Write an exactly FRAME_SIZE sized of frame */
+	int res;
+	static int errors = 0;
 
-static int send_sound(void)
+	/*
+	 * nothing spectacular.
+	 * If the buffer is full just drop the extra, otherwise write
+	 */
+	res = used_blocks(o);
+	if (res > 10) {	/* no room to write a block */
+	    errors ++;
+	    if (errors == 0)
+	    	ast_log(LOG_WARNING, "write: used %d blocks (%d)\n", res, errors);
+	    return 0;
+	}
+	errors = 0;
+	res = write(o->sounddev, ((void *)data), FRAME_SIZE * 2);
+	return res;
+}
+
+/*
+ * handler for 'sound writable' events from the sound thread.
+ * Builds a frame from the high level description of the sounds,
+ * (tone+silence) and passes it to the audio device.
+ */
+static int send_sound(struct chan_oss_pvt *o)
 {
 	short myframe[FRAME_SIZE];
-	int total = FRAME_SIZE;
-	short *frame = NULL;
-	int amt=0;
-	int res;
-	int myoff;
-	audio_buf_info abi;
-	if (cursound > -1) {
-		res = ioctl(sounddev, SNDCTL_DSP_GETOSPACE ,&abi);
-		if (res) {
-			ast_log(LOG_WARNING, "Unable to read output space\n");
-			return -1;
-		}
-		/* Calculate how many samples we can send, max */
-		if (total > (abi.fragments * abi.fragsize / 2)) 
-			total = abi.fragments * abi.fragsize / 2;
-		res = total;
-		if (sampsent < sounds[cursound].samplen) {
-			myoff=0;
-			while(total) {
-				amt = total;
-				if (amt > (sounds[cursound].datalen - offset)) 
-					amt = sounds[cursound].datalen - offset;
-				memcpy(myframe + myoff, sounds[cursound].data + offset, amt * 2);
-				total -= amt;
-				offset += amt;
-				sampsent += amt;
-				myoff += amt;
-				if (offset >= sounds[cursound].datalen)
-					offset = 0;
-			}
-			/* Set it up for silence */
-			if (sampsent >= sounds[cursound].samplen) 
-				silencelen = sounds[cursound].silencelen;
-			frame = myframe;
-		} else {
-			if (silencelen > 0) {
-				frame = silence;
-				silencelen -= res;
-			} else {
-				if (sounds[cursound].repeat) {
-					/* Start over */
-					sampsent = 0;
-					offset = 0;
-				} else {
-					cursound = -1;
-					nosound = 0;
-				}
-			}
+	int ofs = 0;
+	int l_sampsent = o->sampsent;
+	int l;
+	struct sound *s;
+
+	if (o->cursound < 0)	/* no sound to send */
+		return 0;
+	s = &sounds[o->cursound];
+	/*
+	 * prepare a frame
+	 */
+	
+	for (ofs = 0; ofs < FRAME_SIZE; ofs += l) {
+	    /* take chunks of sound and data until the buffer is full */
+	    l = s->samplen - l_sampsent;	/* sound available */
+	    if (l > 0) {
+		if (l > FRAME_SIZE - ofs)
+		    l = FRAME_SIZE - ofs;
+		if (0)
+		ast_log(LOG_WARNING, "send_sound sound %d/%d of %d into %d\n",
+			l_sampsent, l, s->samplen, ofs);
+		bcopy(s->data + l_sampsent, myframe + ofs, l*2);
+		l_sampsent += l;
+	    } else { /* no sound, maybe some silence */
+		static short silence[FRAME_SIZE] = {0, };
+
+	        l += s->silencelen;
+		if (l > 0) {
+		    if (l > FRAME_SIZE - ofs)
+			l = FRAME_SIZE - ofs;
+		    if (0)
+		    ast_log(LOG_WARNING, "send_sound silence %d/%d of %d into %d\n",
+			l_sampsent - s->samplen, l, s->silencelen, ofs);
+		    bcopy(silence, myframe + ofs, l*2);
+		    l_sampsent += l;
+		} else { /* silence is over, restart sound if loop */
+		    if (s->repeat == 0) {	/* last block */
+			ast_log(LOG_WARNING, "send_sound last block\n");
+			o->cursound = -1;
+			o->nosound = 0;	/* allow audio data */
+			if (ofs < FRAME_SIZE)	/* pad with silence */
+			    bcopy(silence, myframe + ofs, (FRAME_SIZE - ofs)*2);
+		    }
+		    l_sampsent = 0;
 		}
-		if (frame)
-			res = write(sounddev, frame, res * 2);
-		if (res > 0)
-			return 0;
-		return res;
+	    }
 	}
-	return 0;
+	l = soundcard_writeframe(o, myframe);
+	if (l > 0)
+	    o->sampsent = l_sampsent;	/* update status */
+	return 0;	/* fake success */
 }
 
 static void *sound_thread(void *unused)
@@ -235,41 +287,53 @@
 	int max;
 	int res;
 	char ign[4096];
-	if (read(sounddev, ign, sizeof(sounddev)) < 0)
+	if (read(oss.sounddev, ign, sizeof(ign)) < 0)
 		ast_log(LOG_WARNING, "Read error on sound device: %s\n", strerror(errno));
 	for(;;) {
 		FD_ZERO(&rfds);
 		FD_ZERO(&wfds);
-		max = sndcmd[0];
-		FD_SET(sndcmd[0], &rfds);
+		max = oss.sndcmd[0];
+		FD_SET(oss.sndcmd[0], &rfds);
 		if (!oss.owner) {
-			FD_SET(sounddev, &rfds);
-			if (sounddev > max)
-				max = sounddev;
+			FD_SET(oss.sounddev, &rfds);
+			if (oss.sounddev > max)
+				max = oss.sounddev;
 		}
-		if (cursound > -1) {
-			FD_SET(sounddev, &wfds);
-			if (sounddev > max)
-				max = sounddev;
+		if (oss.cursound > -1) {
+			FD_SET(oss.sounddev, &wfds);
+			if (oss.sounddev > max)
+				max = oss.sounddev;
 		}
 		res = ast_select(max + 1, &rfds, &wfds, NULL, NULL);
 		if (res < 1) {
 			ast_log(LOG_WARNING, "select failed: %s\n", strerror(errno));
 			continue;
 		}
-		if (FD_ISSET(sndcmd[0], &rfds)) {
-			read(sndcmd[0], &cursound, sizeof(cursound));
-			silencelen = 0;
-			offset = 0;
-			sampsent = 0;
+		if (FD_ISSET(oss.sndcmd[0], &rfds)) { /* read which sound to play from the pipe */
+			int i, what;
+
+			read(oss.sndcmd[0], &what, sizeof(what));
+			for (i = 0; sounds[i].ind != -1; i++)
+				if (sounds[i].ind == what) {
+					oss.cursound = i;
+					oss.sampsent = 0;
+					oss.nosound = 1; /* block other audio */
+					ast_log(LOG_WARNING, "play %s\n", sounds[i].desc);
+					break;
+				}
+			if (sounds[i].ind == -1)
+				oss.cursound = -1;
+			ast_log(LOG_WARNING, "cursound %d samplen %d silencelen %d\n",
+				oss.cursound, oss.cursound >=0 ? sounds[oss.cursound].samplen : -1,
+				oss.cursound >=0 ?  sounds[oss.cursound].silencelen : -1);
 		}
-		if (FD_ISSET(sounddev, &rfds)) {
+		if (FD_ISSET(oss.sounddev, &rfds)) {
 			/* Ignore read */
-			if (read(sounddev, ign, sizeof(ign)) < 0)
+			if (read(oss.sounddev, ign, sizeof(ign)) < 0)
 				ast_log(LOG_WARNING, "Read error on sound device: %s\n", strerror(errno));
 		}
-		if (FD_ISSET(sounddev, &wfds))
-			if (send_sound())
+		if (FD_ISSET(oss.sounddev, &wfds))
+			if (send_sound(&oss) < 0)
 				ast_log(LOG_WARNING, "Failed to write sound\n");
 	}
 	/* Never reached */
@@ -277,6 +341,20 @@
 }
 
 #if 0
+static int calc_loudness(short *frame)
+{
+	int sum = 0;
+	int x;
+	for (x=0;x<FRAME_SIZE;x++) {
+		if (frame[x] < 0)
+			sum -= frame[x];
+		else
+			sum += frame[x];
+	}
+	sum = sum/FRAME_SIZE;
+	return sum;
+}
+
 static int silence_suppress(short *buf)
 {
 #define SILBUF 3
@@ -284,7 +362,7 @@
 	static int silentframes = 0;
 	static char silbuf[FRAME_SIZE * 2 * SILBUF];
 	static int silbufcnt=0;
-	if (!silencesuppression)
+	if (!oss.silencesuppression)
 		return 0;
 	loudness = calc_loudness((short *)(buf));
 	if (option_debug)
@@ -309,7 +387,7 @@
 		/* Write any buffered silence we have, it may have something
 		   important */
 		if (silbufcnt) {
-			write(sounddev, silbuf, silbufcnt * FRAME_SIZE);
+			write(oss.sounddev, silbuf, silbufcnt * FRAME_SIZE);
 			silbufcnt = 0;
 		}
 	}
@@ -317,27 +395,55 @@
 }
 #endif
 
-static int setformat(void)
+/*
+ * reset and close the device if opened,
+ * then open and initialize it in the desired mode,
+ * trigger reads and writes so we can start using it.
+ */
+static int setformat(struct chan_oss_pvt *o, int mode)
 {
-	int fmt, desired, res, fd = sounddev;
+	int fmt, desired, res, fd;
 	static int warnedalready = 0;
 	static int warnedalready2 = 0;
+
+	if (o->sounddev >= 0) {
+		ioctl(o->sounddev, SNDCTL_DSP_RESET, 0);
+		close(o->sounddev);
+		o->duplex = M_UNSET;
+	}
+	fd = o->sounddev = open(o->device, mode |O_NONBLOCK);
+	if (o->sounddev < 0) {
+		ast_log(LOG_WARNING, "Unable to re-open DSP device: %s\n",
+			strerror(errno));
+		return -1;
+	}
+
+	gettimeofday(&o->lasttime, NULL);
 	fmt = AFMT_S16_LE;
 	res = ioctl(fd, SNDCTL_DSP_SETFMT, &fmt);
 	if (res < 0) {
 		ast_log(LOG_WARNING, "Unable to set format to 16-bit signed\n");
 		return -1;
 	}
-	res = ioctl(fd, SNDCTL_DSP_SETDUPLEX, 0);
-	
-	/* Check to see if duplex set (FreeBSD Bug)*/
-	res = ioctl(fd, SNDCTL_DSP_GETCAPS, &fmt);
-	
-	if ((fmt & DSP_CAP_DUPLEX) && !res) {
-		if (option_verbose > 1) 
+	switch (mode) {
+	case O_RDWR:
+	    res = ioctl(fd, SNDCTL_DSP_SETDUPLEX, 0);
+	    /* Check to see if duplex set (FreeBSD Bug)*/
+	    res = ioctl(fd, SNDCTL_DSP_GETCAPS, &fmt);
+	    if (res == 0 && (fmt & DSP_CAP_DUPLEX)) {
+		    if (option_verbose > 1) 
 			ast_verbose(VERBOSE_PREFIX_2 "Console is full duplex\n");
-		full_duplex = -1;
+		    o->duplex = M_FULL;
+	    };
+	    break;
+	case O_WRONLY:
+	    o->duplex = M_WRITE;
+	    break;
+	case O_RDONLY:
+	    o->duplex = M_READ;
+	    break;
 	}
+
 	fmt = 0;
 	res = ioctl(fd, SNDCTL_DSP_STEREO, &fmt);
 	if (res < 0) {
@@ -348,6 +454,7 @@
 	desired = 8000;
 	fmt = desired;
 	res = ioctl(fd, SNDCTL_DSP_SPEED, &fmt);
+
 	if (res < 0) {
 		ast_log(LOG_WARNING, "Failed to set audio device to mono\n");
 		return -1;
@@ -357,89 +464,54 @@
 			ast_log(LOG_WARNING, "Requested %d Hz, got %d Hz -- sound may be choppy\n", desired, fmt);
 	}
 #if 1
-	fmt = BUFFER_FMT;
+	/*
+	 * on freebsd, SETFRAGMENT does not work very well on some cards.
+	 * Better leave it out
+	 */
+	 
+	// fmt = BUFFER_FMT;
+	fmt = 0x8;	// 256-bytes fragment
 	res = ioctl(fd, SNDCTL_DSP_SETFRAGMENT, &fmt);
 	if (res < 0) {
 		if (!warnedalready2++)
 			ast_log(LOG_WARNING, "Unable to set fragment size -- sound may be choppy\n");
 	}
 #endif
+	/* XXX on some cards, we need SNDCTL_DSP_SETTRIGGER to start outputting */
+	res = PCM_ENABLE_INPUT | PCM_ENABLE_OUTPUT;
+	res = ioctl(fd, SNDCTL_DSP_SETTRIGGER, &res);
+	/* it may fail if we are in half duplex, never mind */
 	return 0;
 }
 
+/*
+ * make sure output mode is available. Returns 0 if done,
+ * 1 if too early to switch, -1 if error
+ */
 static int soundcard_setoutput(int force)
 {
-	/* Make sure the soundcard is in output mode.  */
-	int fd = sounddev;
-	if (full_duplex || (!readmode && !force))
-		return 0;
-	readmode = 0;
-	if (force || time_has_passed()) {
-		ioctl(sounddev, SNDCTL_DSP_RESET, 0);
-		/* Keep the same fd reserved by closing the sound device and copying stdin at the same
-		   time. */
-		/* dup2(0, sound); */ 
-		close(sounddev);
-		fd = open(DEV_DSP, O_WRONLY |O_NONBLOCK);
-		if (fd < 0) {
-			ast_log(LOG_WARNING, "Unable to re-open DSP device: %s\n", strerror(errno));
-			return -1;
-		}
-		/* dup2 will close the original and make fd be sound */
-		if (dup2(fd, sounddev) < 0) {
-			ast_log(LOG_WARNING, "dup2() failed: %s\n", strerror(errno));
-			return -1;
-		}
-		if (setformat()) {
-			return -1;
-		}
+	if (oss.duplex == M_FULL || (oss.duplex == M_WRITE && !force))
 		return 0;
-	}
-	return 1;
+	if (!force && too_early(&oss))
+		return 1;
+	if (setformat(&oss, O_WRONLY))
+		return -1;
+	return 0;
 }
 
+/*
+ * make sure input mode is available. Returns 0 if done
+ * 1 if too early to switch, -1 if error
+ */
 static int soundcard_setinput(int force)
 {
-	int fd = sounddev;
-	if (full_duplex || (readmode && !force))
-		return 0;
-	readmode = -1;
-	if (force || time_has_passed()) {
-		ioctl(sounddev, SNDCTL_DSP_RESET, 0);
-		close(sounddev);
-		/* dup2(0, sound); */
-		fd = open(DEV_DSP, O_RDONLY | O_NONBLOCK);
-		if (fd < 0) {
-			ast_log(LOG_WARNING, "Unable to re-open DSP device: %s\n", strerror(errno));
-			return -1;
-		}
-		/* dup2 will close the original and make fd be sound */
-		if (dup2(fd, sounddev) < 0) {
-			ast_log(LOG_WARNING, "dup2() failed: %s\n", strerror(errno));
-			return -1;
-		}
-		if (setformat()) {
-			return -1;
-		}
+	if (oss.duplex == M_FULL || (oss.duplex == M_READ && !force))
 		return 0;
-	}
-	return 1;
-}
-
-static int soundcard_init(void)
-{
-	/* Assume it's full duplex for starters */
-	int fd = open(DEV_DSP, 	O_RDWR | O_NONBLOCK);
-	if (fd < 0) {
-		ast_log(LOG_WARNING, "Unable to open %s: %s\n", DEV_DSP, strerror(errno));
-		return fd;
-	}
-	gettimeofday(&lasttime, NULL);
-	sounddev = fd;
-	setformat();
-	if (!full_duplex) 
-		soundcard_setinput(1);
-	return sounddev;
+	if (!force && too_early(&oss))
+		return 1;
+	if (setformat(&oss, O_RDONLY))
+		return -1;
+	return 0;
 }
 
 static int oss_digit(struct ast_channel *c, char digit)
@@ -454,120 +526,81 @@
 	return 0;
 }
 
+/* request to play a sound on the speaker */
+#define	RING(x) { int what = x; write(oss.sndcmd[1], &what, sizeof(what)); }
+
 static int oss_call(struct ast_channel *c, char *dest, int timeout)
 {
-	int res = 3;
 	struct ast_frame f = { 0, };
 	ast_verbose( " << Call placed to '%s' on console >> \n", dest);
-	if (autoanswer) {
+	if (oss.autoanswer) {
 		ast_verbose( " << Auto-answered >> \n" );
 		f.frametype = AST_FRAME_CONTROL;
 		f.subclass = AST_CONTROL_ANSWER;
 		ast_queue_frame(c, &f);
 	} else {
-		nosound = 1;
 		ast_verbose( " << Type 'answer' to answer, or use 'autoanswer' for future calls >> \n");
 		f.frametype = AST_FRAME_CONTROL;
 		f.subclass = AST_CONTROL_RINGING;
 		ast_queue_frame(c, &f);
-		write(sndcmd[1], &res, sizeof(res));
+		RING(AST_CONTROL_RING);
 	}
 	return 0;
 }
 
 static void answer_sound(void)
 {
-	int res;
-	nosound = 1;
-	res = 4;
-	write(sndcmd[1], &res, sizeof(res));
-	
+	RING(AST_CONTROL_ANSWER);
 }
 
 static int oss_answer(struct ast_channel *c)
 {
 	ast_verbose( " << Console call has been answered >> \n");
-	answer_sound();
+	answer_sound();	/* XXX do we really need it ? considering we shut down immediately... */
 	ast_setstate(c, AST_STATE_UP);
-	cursound = -1;
-	nosound=0;
+	oss.cursound = -1;
+	oss.nosound=0;
 	return 0;
 }
 
 static int oss_hangup(struct ast_channel *c)
 {
-	int res = 0;
-	cursound = -1;
+	oss.cursound = -1;
 	c->pvt->pvt = NULL;
 	oss.owner = NULL;
 	ast_verbose( " << Hangup on console >> \n");
 	ast_mutex_lock(&usecnt_lock);
 	usecnt--;
 	ast_mutex_unlock(&usecnt_lock);
-	if (hookstate) {
-		if (autoanswer) {
+	if (oss.hookstate) {
+		if (oss.autoanswer || oss.autohangup) {
 			/* Assume auto-hangup too */
-			hookstate = 0;
+			oss.hookstate = 0;
 		} else {
 			/* Make congestion noise */
-			res = 2;
-			write(sndcmd[1], &res, sizeof(res));
+			RING(AST_CONTROL_CONGESTION);
 		}
 	}
 	return 0;
 }
 
-static int soundcard_writeframe(short *data)
-{	
-	/* Write an exactly FRAME_SIZE sized of frame */
-	static int bufcnt = 0;
-	static short buffer[FRAME_SIZE * MAX_BUFFER_SIZE * 5];
-	struct audio_buf_info info;
-	int res;
-	int fd = sounddev;
-	static int warned=0;
-	if (ioctl(fd, SNDCTL_DSP_GETOSPACE, &info)) {
-		if (!warned)
-			ast_log(LOG_WARNING, "Error reading output space\n");
-		bufcnt = buffersize;
-		warned++;
-	}
-	if ((info.fragments >= buffersize * 5) && (bufcnt == buffersize)) {
-		/* We've run out of stuff, buffer again */
-		bufcnt = 0;
-	}
-	if (bufcnt == buffersize) {
-		/* Write sample immediately */
-		res = write(fd, ((void *)data), FRAME_SIZE * 2);
-	} else {
-		/* Copy the data into our buffer */
-		res = FRAME_SIZE * 2;
-		memcpy(buffer + (bufcnt * FRAME_SIZE), data, FRAME_SIZE * 2);
-		bufcnt++;
-		if (bufcnt == buffersize) {
-			res = write(fd, ((void *)buffer), FRAME_SIZE * 2 * buffersize);
-		}
-	}
-	return res;
-}
-
-
+/* used for data coming from the network */
 static int oss_write(struct ast_channel *chan, struct ast_frame *f)
 {
 	int res;
-	static char sizbuf[8000];
-	static int sizpos = 0;
-	int len = sizpos;
-	int pos;
+	int src;
+
+	// ast_log(LOG_WARNING, "oss_write size %d\n", f->datalen);
 	/* Immediately return if no sound is enabled */
-	if (nosound)
+	if (oss.nosound)
 		return 0;
 	/* Stop any currently playing sound */
-	cursound = -1;
-	if (!full_duplex) {
+	oss.cursound = -1;
+	if (oss.duplex != M_FULL) {
+		/* XXX check this, looks weird! */
 		/* If we're half duplex, we have to switch to read mode
 		   to honor immediate needs if necessary */
-		res = soundcard_setinput(1);
+		res = soundcard_setinput(1); /* force set if not full_duplex */
 		if (res < 0) {
 			ast_log(LOG_WARNING, "Unable to set device to input mode\n");
 			return -1;
@@ -583,21 +616,30 @@
 		   so just pretend we wrote it */
 		return 0;
 	}
-	/* We have to digest the frame in 160-byte portions */
-	if (f->datalen > sizeof(sizbuf) - sizpos) {
-		ast_log(LOG_WARNING, "Frame too large\n");
-		return -1;
-	}
-	memcpy(sizbuf + sizpos, f->data, f->datalen);
-	len += f->datalen;
-	pos = 0;
-	while(len - pos > FRAME_SIZE * 2) {
-		soundcard_writeframe((short *)(sizbuf + pos));
-		pos += FRAME_SIZE * 2;
+	/*
+	 * we could receive a sample which is not a multiple of our FRAME_SIZE,
+	 * so we buffer it locally and write to the device in FRAME_SIZE
+	 * chunks, keeping the residue stored for future use.
+	 */
+
+	src = 0; /* read position into f->data */
+	while ( src < f->datalen ) {
+	    static char buf[FRAME_SIZE*2];
+	    static int dst = 0;
+	    int l = sizeof(buf) - dst; /* how much room in the buffer */
+
+	    if (f->datalen - src >= l) {	/* enough to fill a frame */
+		memcpy(buf + dst, f->data + src, l);
+		soundcard_writeframe(&oss, (short *)buf);
+		src += l;
+		dst = 0;
+	    } else { /* copy residue */
+		l = f->datalen - src;
+		memcpy(buf + dst, f->data + src, l);
+		src += l;	/* but really, we are done */
+		dst += l;
+	    }
 	}
-	if (len - pos) 
-		memmove(sizbuf, sizbuf + pos, len - pos);
-	sizpos = len - pos;
 	return 0;
 }
 
@@ -628,18 +670,15 @@
 		ast_log(LOG_WARNING, "Unable to set input mode\n");
 		return NULL;
 	}
-	if (res > 0) {
+	if (res > 0) {	/* too early to switch ? */
 		/* Theoretically shouldn't happen, but anyway, return a NULL frame */
 		return &f;
 	}
-	res = read(sounddev, buf + AST_FRIENDLY_OFFSET + readpos, FRAME_SIZE * 2 - readpos);
-	if (res < 0) {
-		ast_log(LOG_WARNING, "Error reading from sound device (If you're running 'artsd' then kill it): %s\n", strerror(errno));
-#if 0
-		CRASH;
-#endif		
-		return NULL;
-	}
+
+	res = read(oss.sounddev, buf + AST_FRIENDLY_OFFSET + readpos, FRAME_SIZE * 2 - readpos);
+	// ast_log(LOG_WARNING, "oss_read() fd %d got %d\n", oss.sounddev, res);
+	if (res < 0) /* audio data not ready, return a NULL frame */
+		return &f;
 	readpos += res;
 	
 	if (readpos >= FRAME_SIZE * 2) {
@@ -682,64 +721,66 @@
 	int res;
 	switch(cond) {
 	case AST_CONTROL_BUSY:
-		res = 1;
-		break;
 	case AST_CONTROL_CONGESTION:
-		res = 2;
-		break;
 	case AST_CONTROL_RINGING:
-		res = 0;
+		res = cond;
 		break;
 	case -1:
-		cursound = -1;
+		oss.cursound = -1;
 		return 0;
 	default:
 		ast_log(LOG_WARNING, "Don't know how to display condition %d on %s\n", cond, chan->name);
 		return -1;
 	}
 	if (res > -1) {
-		write(sndcmd[1], &res, sizeof(res));
+		RING(res);
 	}
 	return 0;	
 }
 
-static struct ast_channel *oss_new(struct chan_oss_pvt *p, int state)
+static struct ast_channel *oss_new(struct chan_oss_pvt *oss, int state)
 {
 	struct ast_channel *tmp;
+	struct ast_channel_pvt *pvt;
+
 	tmp = ast_channel_alloc(1);
-	if (tmp) {
-		snprintf(tmp->name, sizeof(tmp->name), "OSS/%s", DEV_DSP + 5);
-		tmp->type = type;
-		tmp->fds[0] = sounddev;
-		tmp->nativeformats = AST_FORMAT_SLINEAR;
-		tmp->pvt->pvt = p;
-		tmp->pvt->send_digit = oss_digit;
-		tmp->pvt->send_text = oss_text;
-		tmp->pvt->hangup = oss_hangup;
-		tmp->pvt->answer = oss_answer;
-		tmp->pvt->read = oss_read;
-		tmp->pvt->call = oss_call;
-		tmp->pvt->write = oss_write;
-		tmp->pvt->indicate = oss_indicate;
-		tmp->pvt->fixup = oss_fixup;
-		if (strlen(p->context))
-			strncpy(tmp->context, p->context, sizeof(tmp->context)-1);
-		if (strlen(p->exten))
-			strncpy(tmp->exten, p->exten, sizeof(tmp->exten)-1);
-		if (strlen(language))
-			strncpy(tmp->language, language, sizeof(tmp->language)-1);
-		p->owner = tmp;
-		ast_setstate(tmp, state);
-		ast_mutex_lock(&usecnt_lock);
-		usecnt++;
-		ast_mutex_unlock(&usecnt_lock);
-		ast_update_use_count();
-		if (state != AST_STATE_DOWN) {
-			if (ast_pbx_start(tmp)) {
-				ast_log(LOG_WARNING, "Unable to start PBX on %s\n", tmp->name);
-				ast_hangup(tmp);
-				tmp = NULL;
-			}
+	if (tmp == NULL)
+		return NULL;
+	snprintf(tmp->name, sizeof(tmp->name), "OSS/%s", oss->device + 5);
+	tmp->type = type;
+	tmp->fds[0] = oss->sounddev;
+	tmp->nativeformats = AST_FORMAT_SLINEAR;
+	pvt = tmp->pvt;
+	pvt->pvt = oss;
+#if 1
+	pvt->send_digit = oss_digit;
+	pvt->send_text = oss_text;
+	pvt->hangup = oss_hangup;
+	pvt->answer = oss_answer;
+	pvt->read = oss_read;
+	pvt->call = oss_call;
+	pvt->write = oss_write;
+	pvt->indicate = oss_indicate;
+	pvt->fixup = oss_fixup;
+#endif
+	if (strlen(oss->context))
+		strncpy(tmp->context, oss->context, sizeof(tmp->context)-1);
+	if (strlen(oss->exten))
+		strncpy(tmp->exten, oss->exten, sizeof(tmp->exten)-1);
+	if (strlen(language))
+		strncpy(tmp->language, language, sizeof(tmp->language)-1);
+	oss->owner = tmp;
+	ast_setstate(tmp, state);
+	ast_mutex_lock(&usecnt_lock);
+	usecnt++;
+	ast_mutex_unlock(&usecnt_lock);
+	ast_update_use_count();
+	if (state != AST_STATE_DOWN) {
+		if (ast_pbx_start(tmp)) {
+			ast_log(LOG_WARNING, "Unable to start PBX on %s\n", tmp->name);
+			ast_hangup(tmp);
+			tmp = NULL;
+			/* XXX what about oss->owner and the channel itself ? */
 		}
 	}
 	return tmp;
@@ -770,13 +811,13 @@
 	if ((argc != 1) && (argc != 2))
 		return RESULT_SHOWUSAGE;
 	if (argc == 1) {
-		ast_cli(fd, "Auto answer is %s.\n", autoanswer ? "on" : "off");
+		ast_cli(fd, "Auto answer is %s.\n", oss.autoanswer ? "on" : "off");
 		return RESULT_SUCCESS;
 	} else {
 		if (!strcasecmp(argv[1], "on"))
-			autoanswer = -1;
+			oss.autoanswer = -1;
 		else if (!strcasecmp(argv[1], "off"))
-			autoanswer = 0;
+			oss.autoanswer = 0;
 		else
 			return RESULT_SHOWUSAGE;
 	}
@@ -788,12 +829,14 @@
 #ifndef MIN
 #define MIN(a,b) ((a) < (b) ? (a) : (b))
 #endif
+	int l = strlen(word);
+
 	switch(state) {
 	case 0:
-		if (strlen(word) && !strncasecmp(word, "on", MIN(strlen(word), 2)))
+		if (l && !strncasecmp(word, "on", MIN(l, 2)))
 			return strdup("on");
 	case 1:
-		if (strlen(word) && !strncasecmp(word, "off", MIN(strlen(word), 3)))
+		if (l && !strncasecmp(word, "off", MIN(l, 3)))
 			return strdup("off");
 	default:
 		return NULL;
@@ -816,8 +859,8 @@
 		ast_cli(fd, "No one is calling us\n");
 		return RESULT_FAILURE;
 	}
-	hookstate = 1;
-	cursound = -1;
+	oss.hookstate = 1;
+	oss.cursound = -1;
 	ast_queue_frame(oss.owner, &f);
 	answer_sound();
 	return RESULT_SUCCESS;
@@ -863,12 +906,12 @@
 {
 	if (argc != 1)
 		return RESULT_SHOWUSAGE;
-	cursound = -1;
-	if (!oss.owner && !hookstate) {
+	oss.cursound = -1;
+	if (!oss.owner && !oss.hookstate) {
 		ast_cli(fd, "No call to hangup up\n");
 		return RESULT_FAILURE;
 	}
-	hookstate = 0;
+	oss.hookstate = 0;
 	if (oss.owner) {
 		ast_queue_hangup(oss.owner);
 	}
@@ -900,8 +943,8 @@
 		}
 		return RESULT_SUCCESS;
 	}
-	mye = exten;
-	myc = context;
+	mye = oss_exten;
+	myc = default_context;
 	if (argc == 2) {
 		char *stringp=NULL;
 		strncpy(tmp, argv[1], sizeof(tmp)-1);
@@ -916,7 +959,7 @@
 	if (ast_exists_extension(NULL, myc, mye, 1, NULL)) {
 		strncpy(oss.exten, mye, sizeof(oss.exten)-1);
 		strncpy(oss.context, myc, sizeof(oss.context)-1);
-		hookstate = 1;
+		oss.hookstate = 1;
 		oss_new(&oss, AST_STATE_RINGING);
 	} else
 		ast_cli(fd, "No such extension '%s' in context '%s'\n", mye, myc);
@@ -974,21 +1017,47 @@
 	int res;
 	int x;
 	struct ast_config *cfg;
-	struct ast_variable *v;
-	res = pipe(sndcmd);
+
+	res = pipe(oss.sndcmd);
 	if (res) {
 		ast_log(LOG_ERROR, "Unable to create pipe\n");
 		return -1;
 	}
-	res = soundcard_init();
-	if (res < 0) {
+	/* load config file */
+	if ((cfg = ast_load(config))) {
+		struct ast_variable *v = ast_variable_browse(cfg, "general");
+		while(v) {
+			if (!strcasecmp(v->name, "autoanswer"))
+				oss.autoanswer = ast_true(v->value);
+			else if (!strcasecmp(v->name, "autohangup"))
+				oss.autohangup = ast_true(v->value);
+			else if (!strcasecmp(v->name, "oss.silencesuppression"))
+				oss.silencesuppression = ast_true(v->value);
+			else if (!strcasecmp(v->name, "silencethreshold"))
+				oss.silencethreshold = atoi(v->value);
+			else if (!strcasecmp(v->name, "device"))
+				strncpy(oss.device, v->value, sizeof(oss.device)-1);
+			else if (!strcasecmp(v->name, "context"))
+				strncpy(default_context, v->value, sizeof(default_context)-1);
+			else if (!strcasecmp(v->name, "language"))
+				strncpy(language, v->value, sizeof(language)-1);
+			else if (!strcasecmp(v->name, "extension"))
+				strncpy(oss_exten, v->value, sizeof(oss_exten)-1);
+			v=v->next;
+		}
+		ast_destroy(cfg);
+	}
+	if (!strlen(oss.device))
+		strncpy(oss.device, DEV_DSP, sizeof(oss.device)-1);
+	if (setformat(&oss, O_RDWR) < 0) {	/* open device */
 		if (option_verbose > 1) {
 			ast_verbose(VERBOSE_PREFIX_2 "No sound card detected -- console channel will be unavailable\n");
 			ast_verbose(VERBOSE_PREFIX_2 "Turn off OSS support by adding 'noload=chan_oss.so' in /etc/asterisk/modules.conf\n");
 		}
 		return 0;
 	}
-	if (!full_duplex)
+	soundcard_setinput(1); /* force set if not full_duplex */
+	if (oss.duplex != M_FULL)
 		ast_log(LOG_WARNING, "XXX I don't work right with non-full duplex sound cards XXX\n");
 	res = ast_channel_register(type, tdesc, AST_FORMAT_SLINEAR, oss_request);
 	if (res < 0) {
@@ -997,26 +1066,7 @@
 	}
 	for (x=0;x<sizeof(myclis)/sizeof(struct ast_cli_entry); x++)
 		ast_cli_register(myclis + x);
-	if ((cfg = ast_load(config))) {
-		v = ast_variable_browse(cfg, "general");
-		while(v) {
-			if (!strcasecmp(v->name, "autoanswer"))
-				autoanswer = ast_true(v->value);
-			else if (!strcasecmp(v->name, "silencesuppression"))
-				silencesuppression = ast_true(v->value);
-			else if (!strcasecmp(v->name, "silencethreshold"))
-				silencethreshold = atoi(v->value);
-			else if (!strcasecmp(v->name, "context"))
-				strncpy(context, v->value, sizeof(context)-1);
-			else if (!strcasecmp(v->name, "language"))
-				strncpy(language, v->value, sizeof(language)-1);
-			else if (!strcasecmp(v->name, "extension"))
-				strncpy(exten, v->value, sizeof(exten)-1);
-			v=v->next;
-		}
-		ast_destroy(cfg);
-	}
-	ast_pthread_create(&sthread, NULL, sound_thread, NULL);
+	ast_pthread_create(&oss.sthread, NULL, sound_thread, NULL);
 	return 0;
 }
 
@@ -1027,15 +1077,16 @@
 	int x;
 	for (x=0;x<sizeof(myclis)/sizeof(struct ast_cli_entry); x++)
 		ast_cli_unregister(myclis + x);
-	close(sounddev);
-	if (sndcmd[0] > 0) {
-		close(sndcmd[0]);
-		close(sndcmd[1]);
+	close(oss.sounddev);
+	if (oss.sndcmd[0] > 0) {
+		close(oss.sndcmd[0]);
+		close(oss.sndcmd[1]);
 	}
 	if (oss.owner)
 		ast_softhangup(oss.owner, AST_SOFTHANGUP_APPUNLOAD);
 	if (oss.owner)
 		return -1;
+	/* XXX what about the thread ? */
 	return 0;
 }
 
