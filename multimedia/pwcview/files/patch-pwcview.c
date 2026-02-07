--- pwcview.c.orig	2007-10-09 09:23:58.000000000 +0200
+++ pwcview.c	2010-09-09 16:42:31.000000000 +0200
@@ -37,11 +37,8 @@
 #ifndef NOGUI
 #include <SDL.h>
 #endif
-#ifdef __FreeBSD__
-#include "videodev.h"
-#else
+#include <libv4l1.h>
 #include <linux/videodev.h>
-#endif
 #include "pwc-ioctl.h"
 #include "pixels.h"
 
@@ -80,7 +77,7 @@
 	int fps;
 	struct video_window vw;
 
-	if(ioctl(fd,VIDIOCGWIN,&vw) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGWIN,&vw) == -1) {
 		perror("Failed to get current framerate");
 		return -1;
 	}
@@ -90,9 +87,9 @@
 	if((dir == -1 && fps >= 9) ||(dir == 1 && fps <= 25)) {
 		fps += dir == -1 ? -5 : 5;
 		vw.flags = fps << PWC_FPS_SHIFT;
-		if(ioctl(fd,VIDIOCSWIN,&vw) == -1)
+		if(v4l1_ioctl(fd,VIDIOCSWIN,&vw) == -1)
 			fprintf(stderr,"Failed to set framerate to %d fps: %s\n",fps,strerror(errno));
-		if(ioctl(fd,VIDIOCGWIN,&vw) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCGWIN,&vw) == -1) {
 			perror("Failed to get new framerate");
 			return -1;
 		}
@@ -106,16 +103,16 @@
 {
 	int qual;
 
-	if(ioctl(fd,VIDIOCPWCGCQUAL,&qual) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGCQUAL,&qual) == -1) {
 		perror("Failed to get current compression");
 		return -1;
 	}
 
 	if((dir == -1 && qual > 0) || (dir == 1 && qual < 3)) {
 		qual += dir == -1 ? -1 : 1;
-		if(ioctl(fd,VIDIOCPWCSCQUAL,&qual) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSCQUAL,&qual) == -1)
 			perror("Failed to set compression");
-		if(ioctl(fd,VIDIOCPWCGCQUAL,&qual) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGCQUAL,&qual) == -1) {
 			perror("Failed to get new compression");
 			return -1;
 		}
@@ -128,16 +125,16 @@
 {
 	struct video_picture pict;
 	
-	if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 		perror("Failed to get current brightness");
 		return -1;
 	}
 
 	if((dir == -1) || (dir == 1)) {
 		pict.brightness += dir == -1 ? -512 : 512;
-		if(ioctl(fd,VIDIOCSPICT,&pict) == -1)
+		if(v4l1_ioctl(fd,VIDIOCSPICT,&pict) == -1)
 			perror("Failed to set brightness");
-		if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 			perror("Failed to get new brightness");
 			return -1;
 		}
@@ -150,16 +147,16 @@
 {
 	struct video_picture pict;
 	
-	if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 		perror("Failed to get current contrast");
 		return -1;
 	}
 
 	if((dir == -1) || (dir == 1)) {
 		pict.contrast += dir == -1 ? -1024 : 1024;
-		if(ioctl(fd,VIDIOCSPICT,&pict) == -1)
+		if(v4l1_ioctl(fd,VIDIOCSPICT,&pict) == -1)
 			perror("Failed to set contrast");
-		if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 			perror("Failed to get new contrast");
 			return -1;
 		}
@@ -172,16 +169,16 @@
 {
 	struct video_picture pict;
 	
-	if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 		perror("Failed to get current saturation");
 		return -1;
 	}
 
 	if((dir == -1) || (dir == 1)) {
 		pict.colour += dir == -1 ? -327 : 327;
-		if(ioctl(fd,VIDIOCSPICT,&pict) == -1)
+		if(v4l1_ioctl(fd,VIDIOCSPICT,&pict) == -1)
 			perror("Failed to set saturation");
-		if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 			perror("Failed to get new saturation");
 			return -1;
 		}
@@ -194,16 +191,16 @@
 {
 	struct video_picture pict;
 	
-	if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 		perror("Failed to get current gamma");
 		return -1;
 	}
 
 	if((dir == -1) ||(dir == 1)) {
 		pict.whiteness += dir == -1 ? -2048 : 2048;
-		if(ioctl(fd,VIDIOCSPICT,&pict) == -1)
+		if(v4l1_ioctl(fd,VIDIOCSPICT,&pict) == -1)
 			perror("Failed to set gamma");
-		if(ioctl(fd,VIDIOCGPICT,&pict) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCGPICT,&pict) == -1) {
 			perror("Failed to get new gamma");
 			return -1;
 		}
@@ -236,7 +233,7 @@
 		snprintf(buf,80,"gain control: %d",agc >> 10);
 	}
 	
-	ioctl(fd,VIDIOCPWCSAGC,&val);
+	v4l1_ioctl(fd,VIDIOCPWCSAGC,&val);
 	return 0;
 }
 
@@ -263,7 +260,7 @@
 		val = shutter;
 		snprintf(buf,80,"shutter speed: %d",shutter >> 8);
 	}
-	ioctl(fd,VIDIOCPWCSSHUTTER,&val);
+	v4l1_ioctl(fd,VIDIOCPWCSSHUTTER,&val);
 	return 0;
 }
 
@@ -274,7 +271,7 @@
 	char *names[] = { "indoor", "outdoor", "fluorescent","manual","auto" };
 	int *val = NULL;
 	
-	if(ioctl(fd,VIDIOCPWCGAWB,&wb) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGAWB,&wb) == -1) {
 		perror("Failed to get white balance");
 		return -1;
 	}
@@ -298,10 +295,10 @@
 			*val += 256;
 	}
 	
-	if(ioctl(fd,VIDIOCPWCSAWB,&wb) == -1)
+	if(v4l1_ioctl(fd,VIDIOCPWCSAWB,&wb) == -1)
 		perror("Failed to set white balance");
 	
-	if(ioctl(fd,VIDIOCPWCGAWB,&wb) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGAWB,&wb) == -1) {
 		perror("Failed to get white balance");
 		return -1;
 	}
@@ -317,16 +314,16 @@
 {
 	struct pwc_wb_speed speed;
 
-	if(ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
 		perror("Failed to get current awb speed");
 		return -1;
 	}
 
 	if((dir == -1) || (dir == 1)) {
 		speed.control_speed += dir == -1 ? -2032 : 2032;
-		if(ioctl(fd,VIDIOCPWCSAWBSPEED,&speed) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSAWBSPEED,&speed) == -1)
 			perror("Failed to set awb speed");
-		if(ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
 			perror("Failed to get new awb speed");
 			return -1;
 		}
@@ -339,16 +336,16 @@
 {
 	struct pwc_wb_speed speed;
 
-	if(ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
 		perror("Failed to get current awb delay");
 		return -1;
 	}
 
 	if((dir == -1) || (dir == 1)) {
 		speed.control_delay += dir == -1 ? -1024 : 1024;
-		if(ioctl(fd,VIDIOCPWCSAWBSPEED,&speed) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSAWBSPEED,&speed) == -1)
 			perror("Failed to set awb delay");
-		if(ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGAWBSPEED,&speed) == -1) {
 			perror("Failed to get new awb delay");
 			return -1;
 		}
@@ -377,13 +374,13 @@
 	else 
 		val = contour;
 	
-	if(ioctl(fd,VIDIOCPWCSCONTOUR,&val) == -1)
+	if(v4l1_ioctl(fd,VIDIOCPWCSCONTOUR,&val) == -1)
 		perror("Failed to set contour");
 	
 	if(contourmode == 1)
 		snprintf(buf,80,"contour: auto");
 	else {
-		if(ioctl(fd,VIDIOCPWCGCONTOUR,&contour) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGCONTOUR,&contour) == -1) {
 			perror("Failed to get contour");
 			return -1;
 		}
@@ -396,17 +393,17 @@
 {
 	int dynnoise;
 	 
-	if(ioctl(fd,VIDIOCPWCGDYNNOISE,&dynnoise) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGDYNNOISE,&dynnoise) == -1) {
 		perror("Failed to get current dynamic noise reduction mode");
 		return -1;
 	}
 	if(dir == 2) {
 		if(++dynnoise == 4)
 			dynnoise = 0;
-		if(ioctl(fd,VIDIOCPWCSDYNNOISE,&dynnoise) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSDYNNOISE,&dynnoise) == -1)
 			perror("Failed to set dynamic noise reduction mode");
 		 
-		if(ioctl(fd,VIDIOCPWCGDYNNOISE,&dynnoise) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGDYNNOISE,&dynnoise) == -1) {
 			perror("Failed to get new dynamic noise reduction mode");
 			return -1;
 		 }
@@ -419,16 +416,16 @@
 {
 	int backlight;
 
-	if(ioctl(fd,VIDIOCPWCGBACKLIGHT,&backlight) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGBACKLIGHT,&backlight) == -1) {
 		perror("Failed to get backlight mode");
 		return -1;
 	}
 	if(dir == 2) {
 		backlight = !backlight;
-		if(ioctl(fd,VIDIOCPWCSBACKLIGHT,&backlight) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSBACKLIGHT,&backlight) == -1)
 			perror("Failed to set backlight mode");
 		
-		if(ioctl(fd,VIDIOCPWCGBACKLIGHT,&backlight) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGBACKLIGHT,&backlight) == -1) {
 			perror("Failed to get new backlight mode");
 			return -1;
 		}
@@ -441,16 +438,16 @@
 {
 	int flicker;
 
-	if(ioctl(fd,VIDIOCPWCGFLICKER,&flicker) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGFLICKER,&flicker) == -1) {
 		perror("Failed to get flicker mode");
 		return -1;
 	}
 	if(dir == 2) {
 		flicker = !flicker;
-		if(ioctl(fd,VIDIOCPWCSFLICKER,&flicker) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSFLICKER,&flicker) == -1)
 			perror("Failed to set flicker mode");
 		
-		if(ioctl(fd,VIDIOCPWCGFLICKER,&flicker) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGFLICKER,&flicker) == -1) {
 			perror("Failed to get new flicker mode");
 			return -1;
 		}
@@ -463,16 +460,16 @@
 {
 	int colour;
 
-	if(ioctl(fd,VIDIOCPWCGCOLOUR,&colour) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCPWCGCOLOUR,&colour) == -1) {
 		perror("Failed to get colour mode");
 		return -1;
 	}
 	if(dir == 2) {
 		colour = !colour;
-		if(ioctl(fd,VIDIOCPWCSCOLOUR,&colour) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSCOLOUR,&colour) == -1)
 			perror("Failed to set colour mode");
 		
-		if(ioctl(fd,VIDIOCPWCGCOLOUR,&colour) == -1) {
+		if(v4l1_ioctl(fd,VIDIOCPWCGCOLOUR,&colour) == -1) {
 			perror("Failed to get new colour mode");
 			return -1;
 		}
@@ -487,7 +484,7 @@
 		snprintf(buf,80,"save user settings");
 	}
 	else if(dir == 2) {
-		if(ioctl(fd,VIDIOCPWCSUSER) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSUSER) == -1)
 			snprintf(buf,80,"Error: %s",strerror(errno));
 		else 
 			snprintf(buf,80,"User settings saved");
@@ -506,7 +503,7 @@
 		snprintf(buf,80,"restore user settings");
 	}
 	else if(dir == 2) {
-		if(ioctl(fd,VIDIOCPWCRUSER) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCRUSER) == -1)
 			snprintf(buf,80,"Error: %s",strerror(errno));
 		else
 			snprintf(buf,80,"User settings restored");
@@ -523,7 +520,7 @@
 		snprintf(buf,80,"restore factory settings");
 	}
 	else if(dir == 2) {
-		if(ioctl(fd,VIDIOCPWCFACTORY) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCFACTORY) == -1)
 			snprintf(buf,80,"Error: %s",strerror(errno));
 		else
 			snprintf(buf,80,"Factory settings restored");
@@ -537,12 +534,12 @@
 struct pwc_leds led;
 int ledon_handler(int fd, int dir, char *buf)
 {
-	ioctl(fd,VIDIOCPWCGLED,&led);
+	v4l1_ioctl(fd,VIDIOCPWCGLED,&led);
 	if((dir == -1) || (dir == 1)) {
 		led.led_on += (dir == -1) ? -100 : 100;
 		if(led.led_on < 0)
 			led.led_on = 0;
-		if(ioctl(fd,VIDIOCPWCSLED,&led) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSLED,&led) == -1)
 			perror("Failed to set leds");
 	}
 	snprintf(buf,80,"led on: %d", led.led_on);
@@ -551,12 +548,12 @@
 
 int ledoff_handler(int fd, int dir, char *buf)
 {
-	ioctl(fd,VIDIOCPWCGLED,&led);
+	v4l1_ioctl(fd,VIDIOCPWCGLED,&led);
 	if((dir == -1) || (dir == 1)) {
 		led.led_off += (dir == -1) ? -100 : 100;
 		if(led.led_off < 0)
 			led.led_off = 0;
-		if(ioctl(fd,VIDIOCPWCSLED,&led) == -1)
+		if(v4l1_ioctl(fd,VIDIOCPWCSLED,&led) == -1)
 			perror("Failed to set leds");
 	}
 	snprintf(buf,80,"led off: %d", led.led_off);
@@ -837,6 +834,8 @@
 	jdata[1] = jimage[1];
 	jdata[2] = jimage[2];
 	
+	cinfo->raw_data_in = TRUE;
+	cinfo->do_fancy_downsampling = FALSE;
 	jpeg_stdio_dest(cinfo, outfile);
 	jpeg_start_compress(cinfo, TRUE);
 
@@ -871,7 +870,7 @@
 {
 	static int newbuf;
 	static int skip = 5;
-	static uint32_t motionbuf[2][60][80];
+	static uint32_t motionbuf[2][150][200];
 	static int rectime;
 	uint32_t diff;
 	int line, col, motiondetected = 0;
@@ -888,7 +887,7 @@
 		}
 	}
 	
-	memset(motionbuf[newbuf],0,60*80*sizeof(uint32_t));
+	memset(motionbuf[newbuf],0,150*200*sizeof(uint32_t));
 
 	for(line = 0; line < height; ++line) {
 		int y = line / 8; tp = pt;
@@ -1041,7 +1040,10 @@
 }
 #endif
 
-#define PSZ_MAX 6
+#ifdef PSZ_MAX
+#undef PSZ_MAX
+#endif
+#define PSZ_MAX 10
 struct {
 	char *name;
 	int width;
@@ -1052,7 +1054,11 @@
 	{ "qcif", 176, 144 },
 	{ "sif", 320, 240 },
 	{ "cif", 352, 288 },
-	{ "vga", 640, 480 }
+	{ "vga", 640, 480 },
+	{ "svga", 800, 600 },
+	{ "xga", 1024, 768 },
+	{ "sxga", 1280, 1024 },
+	{ "uxga", 1600, 1200 }
 };
 	
 int usage()
@@ -1184,7 +1190,7 @@
 					  break;
 
 			if(i == PSZ_MAX) {
-				fprintf(stderr,"Invalid size, valid sizes: sqcif, qsif, qcif, sif, cif, vga\n");
+				fprintf(stderr,"Invalid size, valid sizes: sqcif, qsif, qcif, sif, cif, vga, svga, xga, sxga, uxga\n");
 				return 1;
 			}
 			break;
@@ -1216,9 +1222,8 @@
 	vw.width = sizes[i].width;
 	vw.height= sizes[i].height;
 	vw.flags = fps << PWC_FPS_SHIFT;
-	imgsize = (vw.width * vw.height * 3)/2;
 
-	if((fd = open(device, O_RDONLY)) < 0) {
+	if((fd = v4l1_open(device, O_RDONLY)) < 0) {
 		if(errno == EBUSY)
 			fprintf(stderr,"Failed to access webcam: Device in use\n");
 		else {
@@ -1236,30 +1241,31 @@
     	}
 	fcntl(fd,F_SETFD,FD_CLOEXEC);
 
-	if(ioctl(fd,VIDIOCGPICT,&vp) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCGPICT,&vp) == -1) {
 		perror("Failed to get current picture info");
 		exit(1);
 	}
 	vp.palette = VIDEO_PALETTE_YUV420P;
-	if(ioctl(fd,VIDIOCSPICT,&vp) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCSPICT,&vp) == -1) {
 		perror("Failed to set palette to YUV420P");
 		exit(1);
 	}
 	
-	if(ioctl(fd,VIDIOCSWIN,&vw) == -1) {
+	if(v4l1_ioctl(fd,VIDIOCSWIN,&vw) == -1) {
 		fprintf(stderr,"Failed to set webcam to: %dx%d (%s) at %d fps (%s)\n",
 				vw.width,vw.height,sizes[i].name,fps,strerror(errno));
 		exit(1);
 	}
 	fprintf(stderr,"Webcam set to: %dx%d (%s) at %d fps\n",vw.width,vw.height,sizes[i].name,fps);
+	imgsize = (vw.width * vw.height * 3)/2;
 
 	if(headless && snapcnt == 0 && motionrecord == 0) { /* Done */
-		close(fd);
+		v4l1_close(fd);
 		exit(0);
 	}
 	if(snapbtn) {
 		snapbtn = 0;
-		if(ioctl(fd,VIDIOCPWCPROBE,&probe) != -1 &&
+		if(v4l1_ioctl(fd,VIDIOCPWCPROBE,&probe) != -1 &&
 		   probe.type >= 720 && probe.type <= 740)
 				snapbtn = 1;
 	}
@@ -1327,7 +1333,7 @@
 			timerid = SDL_AddTimer(interval,cbtimer,NULL);
 	}
 #endif
-	while (frozen || ((size = read(fd,y,imgsize)) > 0) || (size == -1 && errno == EINTR)) {
+	while (frozen || ((size = v4l1_read(fd,y,imgsize)) > 0) || (size == -1 && errno == EINTR)) {
 		int snap = y[0] & 0x01;
 		if(!frozen && size != imgsize) {
 			if(size != -1) {
@@ -1498,7 +1504,7 @@
 	if(size != 0)
 		perror("Error reading from webcam");
 
-	close(fd);
+	v4l1_close(fd);
 	jpeg_destroy_compress(&cinfo);
 	return 0;
 }
