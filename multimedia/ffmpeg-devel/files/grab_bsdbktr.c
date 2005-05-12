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
#if __FreeBSD__ >= 502100
#include <dev/bktr/ioctl_meteor.h>
#include <dev/bktr/ioctl_bt848.h>
#else
#include <machine/ioctl_meteor.h>
#include <machine/ioctl_bt848.h>
#endif
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
	int frame_rate_base;
	int64_t per_frame;
} VideoData;

const char *video_device = "/dev/bktr0";

#define PAL 1
#define PALBDGHI 1
#define NTSC 2
#define NTSCM 2
#define SECAM 3
#define PALN 4
#define PALM 5
#define NTSCJ 6

/* PAL is 768 x 576. NTSC is 640 x 480 */
#define PAL_HEIGHT 576
#define SECAM_HEIGHT 576
#define NTSC_HEIGHT 480

#ifndef VIDEO_FORMAT
#define VIDEO_FORMAT NTSC
#endif

static int bktr_dev[] = { METEOR_DEV0, METEOR_DEV1, METEOR_DEV2,
                   METEOR_DEV3, METEOR_DEV_SVIDEO };

static u_int8_t *video_buf;
static int nsignals = 0;
static void catchsignal(int signal)
{
	nsignals++;
	return;
}

static int bktr_init (const char *video_device, int width, int height,
	int format, u_int8_t **video_buf_local, int *video_fd, int *tuner_fd,
	int idev, double frequency)
{
	struct meteor_geomet geo;
	int h_max;
	long ioctl_frequency;
	char *arg;
	int c;
	struct sigaction act,old;

	if (idev < 0 || idev > 4)
	{
		arg = getenv ("BKTR_DEV");
		if (arg)
			idev = atoi (arg);
		if (idev < 0 || idev > 4)
			idev = 0;
	}

	if (format < 1 || format > 6)
	{
		arg = getenv ("BKTR_FORMAT");
		if (arg)
			format = atoi (arg);
		if (format < 1 || format > 6)
			format = VIDEO_FORMAT;
	}

	if (frequency <= 0)
	{
		arg = getenv ("BKTR_FREQUENCY");
		if (arg)
			frequency = atof (arg);
		if (frequency <= 0)
			frequency = 0.0;
	}

	memset(&act,0,sizeof(act));
	sigemptyset(&act.sa_mask);
	act.sa_handler  = catchsignal;
	sigaction(SIGUSR1,&act,&old);

	*tuner_fd = open ("/dev/tuner0", O_RDONLY);
	if (*tuner_fd < 0) {
		perror("Warning: Tuner not opened continuing");
	}

//	*video_fd = open (video_device, O_RDONLY);
	*video_fd = open (video_device, O_RDWR);
	if (*video_fd < 0) {
		perror (video_device);
		return AVERROR_IO;
	}

	geo.rows = height;
	geo.columns = width;
	geo.frames = 1;
//	geo.oformat = METEOR_GEO_YUV_422 | METEOR_GEO_YUV_12;
	geo.oformat = METEOR_GEO_YUV_PACKED;

	switch (format) {
	case PAL:   h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALBDGHI; break;
	case PALN:  h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALN;     break;
	case PALM:  h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALM;     break;
	case SECAM: h_max = SECAM_HEIGHT; c = BT848_IFORM_F_SECAM;    break;
	case NTSC:  h_max = NTSC_HEIGHT;  c = BT848_IFORM_F_NTSCM;    break;
	case NTSCJ: h_max = NTSC_HEIGHT;  c = BT848_IFORM_F_NTSCJ;    break;
	default:    h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALBDGHI; break;
	}
	if (height <= h_max/2) {
		geo.oformat |= METEOR_GEO_EVEN_ONLY;
	}

	if (ioctl(*video_fd, METEORSETGEO, &geo) < 0) {
		perror ("METEORSETGEO");
		return -1;
	}

	if (ioctl(*video_fd, BT848SFMT, &c) < 0) {
		perror ("BT848SFMT");
		return -1;
	}

	c = bktr_dev[idev];
	if (ioctl(*video_fd, METEORSINPUT, &c) < 0) {
		perror ("METEORSINPUT");
		return -1;
	}
	*video_buf_local = (u_int8_t *) mmap((void *)0, width*height*2,
		PROT_READ, MAP_SHARED, *video_fd, (off_t) 0);
	if (*video_buf_local == MAP_FAILED) {
		perror ("mmap");
		return -1;
	}
	if (frequency != 0.0) {
		ioctl_frequency  = (unsigned long)(frequency*16); 
		if (ioctl(*tuner_fd, TVTUNER_SETFREQ, &ioctl_frequency)<0)
			perror("TVTUNER_SETFREQ");
	}
	c = METEOR_CAP_CONTINOUS;
	ioctl(*video_fd, METEORCAPTUR, &c);
	c = SIGUSR1;
	ioctl (*video_fd, METEORSSIGNAL, &c);
	return 0;
}

static void bktr_getframe(VideoData *s)
{
	int64_t curtime, delay;
	struct timespec ts;

	/* Calculate the time of the next frame */
	s->per_frame += int64_t_C(1000000);

	/* wait based on the frame rate */
	for(;;) {
		curtime = av_gettime();
		delay = s->per_frame  * s->frame_rate_base / s->frame_rate - curtime;
		if (delay <= 0) {
			if (delay < int64_t_C(-1000000) * s->frame_rate_base / s->frame_rate) {
				/* printf("grabbing is %d frames late (dropping)\n", (int) -(delay / 16666)); */
				s->per_frame += int64_t_C(1000000);
			}
			break;
		}
		ts.tv_sec = delay / 1000000;
		ts.tv_nsec = (delay % 1000000) * 1000;
		nanosleep(&ts, NULL);
	}
}

void bf_memcpy (char *dest, char *src, int size)
{
	while (size -= 2)
	{
		dest[0] = src[1];
		dest[1] = src[0];
		dest += 2;
		src += 2;
	}
}

/* note: we support only one picture read at a time */
static int grab_read_packet(AVFormatContext *s1, AVPacket *pkt)
{
	VideoData *s = s1->priv_data;
	int size, halfsize;

	size = s->width * s->height;
	halfsize = size << 1;

//	if (av_new_packet(pkt, size + halfsize) < 0)
	if (av_new_packet(pkt, size + size) < 0)
		return AVERROR_IO;

	bktr_getframe (s);
//	pkt->pts = av_gettime() & ((1LL << 48) - 1);
	pkt->pts = av_gettime() * s->frame_rate / s->frame_rate_base;

	bf_memcpy (pkt->data, video_buf, size + size);
//	bf_memcpy (pkt->data, video_buf, size + halfsize);

//	return size + halfsize;
	return size + size;
}

static int grab_read_header (AVFormatContext *s1,  AVFormatParameters *ap)
{
	VideoData *s = s1->priv_data;
	AVStream *st;
	int width, height;
	int frame_rate;
	int frame_rate_base;
	int format = -1;

	if (!ap || ap->width <= 0 || ap->height <= 0 || ap->time_base.den <= 0)
		return -1;

	width = ap->width;
	height = ap->height;
	frame_rate = ap->time_base.den;
	frame_rate_base = ap->time_base.num;

	if((unsigned)width > 32767 || (unsigned)height > 32767)
		return -1;

	st = av_new_stream(s1, 0);
	if (!st)
		return -ENOMEM;

	av_set_pts_info(st, 48, 1, 1000000); /* 48 bits pts in us */

	s->width = width;
	s->height = height;
	s->frame_rate = frame_rate;
	s->frame_rate_base = frame_rate_base;
	s->per_frame = ((int64_t)1000000 * s->frame_rate_base) / s->frame_rate;

	st->codec.codec_type = CODEC_TYPE_VIDEO;
//	st->codec.pix_fmt = PIX_FMT_YUV420P;
	st->codec.pix_fmt = PIX_FMT_YUV422;
	st->codec.codec_id = CODEC_ID_RAWVIDEO;
	st->codec.width = width;
	st->codec.height = height;
	st->codec.time_base.den = frame_rate;
	st->codec.time_base.num = frame_rate_base;

   if (ap->standard) {
		if (!strcasecmp(ap->standard, "pal"))
		    format = PAL;
		if (!strcasecmp(ap->standard, "secam"))
		    format = SECAM;
		if (!strcasecmp(ap->standard, "ntsc"))
		    format = NTSC;
	}

	if (bktr_init (video_device, width, height, format, &video_buf,
		       &(s->fd), &(s->tuner_fd), -1, 0.0) < 0)
		return AVERROR_IO;
	return 0;
}

static int grab_read_close (AVFormatContext *s1)
{
	VideoData *s = s1->priv_data;

	int c = METEOR_CAP_STOP_CONT;
	ioctl(s->fd, METEORCAPTUR, &c);
	close(s->fd);
	close(s->tuner_fd);
	munmap((void *)video_buf, sizeof(video_buf));
	return 0;
}

AVInputFormat video_grab_device_format = {
	"video4linux",
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
