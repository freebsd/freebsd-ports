--- nuvrec.c.orig	Wed Jul  4 23:59:58 2001
+++ nuvrec.c	Sun Feb  1 17:31:10 2004
@@ -27,14 +27,28 @@
 #include <sys/stat.h>
 #include <sys/time.h>
 #include <sys/resource.h>
+#include <sys/param.h>
+#if __FreeBSD_version >= 502100
+#include <dev/bktr/ioctl_meteor.h>
+#include <dev/bktr/ioctl_bt848.h>
+#else
+#include <machine/ioctl_meteor.h>
+#include <machine/ioctl_bt848.h>
+#endif
 #include <sys/soundcard.h>
-#include <linux/videodev.h>
-#include <linux/wait.h>
+#include <sys/wait.h>
 #include <errno.h>
 #include "minilzo.h"
 #include "RTjpegN.h"
 #include "nuppelvideo.h"
 
+typedef unsigned char UINT8;
+typedef unsigned int UINT32;
+typedef unsigned long long UINT64;
+typedef signed char INT8;
+typedef signed int INT32;
+typedef signed long long INT64;
+
 // #define TESTINPUT 1
 // #define TESTSPLIT 1
 #define KEYFRAMEDIST 30
@@ -47,11 +61,28 @@
   #define MAXBYTESFORCE  2100000000
 #endif
 
-// we need the BTTV_FIELDNR, so we really know how many frames we lose
-#define BTTV_FIELDNR            _IOR('v' , BASE_VIDIOCPRIVATE+2, unsigned int)
+#define PAL 1
+#define NTSC 2
+#define SECAM 3
+#define PALN 4
+#define PALM 5
+#define PALBDGHI PAL
+#define NTSCJ 6
+#define NTSCM NTSC
+
+/* PAL is 768 x 576. NTSC is 640 x 480 */
+#define PAL_HEIGHT 576
+#define SECAM_HEIGHT 576
+#define NTSC_HEIGHT 480
+
+#include <sys/mman.h>
+#include <sys/time.h>
+#include <signal.h>
 
 /* Globals */
 
+int bktr_dev[] = { METEOR_DEV0, METEOR_DEV1, METEOR_DEV2,
+                   METEOR_DEV3, METEOR_DEV_SVIDEO };
 int fd;     // output file haendle
 int ostr=0;
 __s8 *strm;
@@ -71,10 +102,10 @@
 unsigned long long audiobytes;
 int effectivedsp;
 int ntsc=0; // default to PAL, this info is only for the video header
+int secam=0;
 int quiet;
 int rawmode=0;
-int usebttv=1;
-struct video_audio origaudio;
+int usebttv=0;
 
 //#define DP(DSTRING) fprintf(stderr, "%s\n", DSTRING);
 #define DP(DSTRING)
@@ -173,9 +204,6 @@
   kill(pid,  9);
   if (recordaudio) kill(pid2, 9);
 
-  // reset audio settings
-  if (ioctl(fd, VIDIOCSAUDIO, &origaudio)<0) perror("VIDIOCSAUDIO");
- 
   if (!quiet) fprintf(stderr, "\n"); // preserve status line
   exit(i);
 }
@@ -201,24 +229,25 @@
     unsigned char *startaudio;
 
     if (init_shm) {
-      shmid = shmget(IPC_PRIVATE, video_buffer_size*video_buffer_count +
+      shmid = shmget(0xdeadbeef, video_buffer_size*video_buffer_count +
                                   audio_buffer_size*audio_buffer_count +
                                   video_buffer_count*sizeof(vidbuffertyp) +
                                   audio_buffer_count*sizeof(audbuffertyp),
-  	             IPC_EXCL | IPC_CREAT | 0600);
+  	             IPC_CREAT | SHM_R | SHM_W);
       if (shmid == -1)
   	  ERROR("shmget");
     } 
-    sharedbuffer = shmat(shmid, IPC_RMID, SHM_RND);
+    sharedbuffer = shmat(shmid, (char *) 0, 0);
     if (sharedbuffer == (char*)-1)
     {
+	fprintf (stderr, "shmid %d\n", shmid);
   	perror("shmat");
 	if(shmctl(shmid, IPC_RMID, NULL))
 		perror("shmctl");
 	exit(-1);
     }
-    if(shmctl(shmid, IPC_RMID, NULL))
-	ERROR("shmctl");
+//    if(shmctl(shmid, IPC_RMID, NULL))
+//	ERROR("shmctl");
 
     videobuffer    = (struct vidbuffertype *)sharedbuffer;
     startaudiodesc = (char *)(sharedbuffer + video_buffer_count*sizeof(vidbuffertyp));
@@ -899,24 +928,6 @@
 #ifdef TESTINPUT
   tf+=2; // when reading from files we won't lose frames ;)
 #else
- if (usebttv) {
-   // i hate it when interfaces changes and a non existent ioctl doesn't make an error
-   // and doesn't return -1, returning 0 instead and making no error is really weird
-   if (ioctl(fd, BTTV_FIELDNR, &tf)) {
-     perror("BTTV_FIELDNR");
-     usebttv = 0;
-     fprintf(stderr, "\nbttv_fieldnr not supported by bttv-driver" 
-                     "\nuse insmod/modprobe bttv card=YOURCARD field_nr=1 to activate f.n."
-                     "\nfalling back to timecode routine to determine lost frames\n");
-   }
-   if (tf==0) {
-     usebttv = 0;
-     fprintf(stderr, "\nbttv_fieldnr not supported by bttv-driver" 
-                     "\nuse insmod/modprobe bttv card=YOURCARD field_nr=1 to activate f.n."
-                     "\nfalling back to timecode routine to determine lost frames\n");
-   }
- }
-
  // here is the non preferable timecode - drop algorithm - fallback
  if (!usebttv) {
 
@@ -1073,21 +1084,125 @@
    exit(-1);
 }
 
+INT64 av_gettime(void)
+{
+	struct timeval tv;
+	gettimeofday(&tv,NULL);
+	return (INT64)tv.tv_sec * 1000000 + tv.tv_usec;
+}
+
+static int nsignals = 0;
+static void catchsignal(int signal)
+{
+	nsignals++;
+	return;
+}
+
+static int bktr_init(int video_fd, int width, int height, UINT8 **video_buf, int channel)
+{
+	int format = PAL;
+	struct meteor_geomet geo;
+	int c;
+	int h_max;
+	struct sigaction act,old;
+
+	if (channel < 0 || channel > 4)
+		channel = 1;
+   if (ntsc) {
+		format = NTSC;
+	} else if (secam) {
+		format = SECAM;
+	}
+
+	memset(&act,0,sizeof(act));
+	sigemptyset(&act.sa_mask);
+	act.sa_handler  = catchsignal;
+	sigaction(SIGUSR1,&act,&old);
+
+	geo.rows = height;
+	geo.columns = width;
+	geo.frames = 1;
+	geo.oformat = METEOR_GEO_YUV_422 | METEOR_GEO_YUV_12;
+
+   switch (format) {
+   case PAL:   h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALBDGHI; break;
+   case PALN:  h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALN;     break;
+   case PALM:  h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALM;     break;
+   case SECAM: h_max = SECAM_HEIGHT; c = BT848_IFORM_F_SECAM;    break;
+   case NTSC:  h_max = NTSC_HEIGHT;  c = BT848_IFORM_F_NTSCM;    break;
+   case NTSCJ: h_max = NTSC_HEIGHT;  c = BT848_IFORM_F_NTSCJ;    break;
+   default:    h_max = PAL_HEIGHT;   c = BT848_IFORM_F_PALBDGHI; break;
+   }
+   if (height <= h_max/2) {
+      geo.oformat |= METEOR_GEO_EVEN_ONLY;
+   }
+
+	if (ioctl(video_fd, METEORSETGEO, &geo) < 0) {
+		perror ("METEORSETGEO");
+		return -EIO;
+	}
+
+	if (ioctl(video_fd, BT848SFMT, &c) < 0) {
+		perror ("BT848SFMT");
+		return -EIO;
+	}
+
+	c = bktr_dev[channel];
+	if (ioctl(video_fd, METEORSINPUT, &c) < 0) {
+		perror ("METEORSINPUT");
+		return -EIO;
+	}
+	*video_buf = (UINT8 *) mmap((caddr_t)0, width*height*3,
+	                            PROT_READ, MAP_SHARED, video_fd, (off_t) 0);
+	if (*video_buf == MAP_FAILED) {
+		perror ("mmap");
+		return -EIO;
+	}
+	c = METEOR_CAP_CONTINOUS;
+	ioctl(video_fd, METEORCAPTUR, &c);
+	c = SIGUSR1;
+	ioctl (video_fd, METEORSSIGNAL, &c);
+	return 0;
+}
+
+/* note: we support only one picture read at a time */
+static void bktr_getframe(int width, int height, UINT64 per_frame)
+{
+	int size, halfsize;
+	UINT64 curtime;
+	static UINT64 last_frame_time = 0;
+
+	size = width * height;
+	halfsize = size << 1;
+
+	curtime = av_gettime();
+	if (!last_frame_time
+	    || ((last_frame_time + per_frame) > curtime)) {
+		if (!usleep (last_frame_time + per_frame + per_frame/8 - curtime)) {
+			if (!nsignals)
+				printf ("\nSLEPT NO signals - %d microseconds late\n",
+				        av_gettime() - last_frame_time - per_frame);
+		}
+	}
+	nsignals = 0;
+
+	last_frame_time = curtime;
+}
+
+
 // ----------------------------------------------------------
 // -- MAIN --------------------------------------------------
 
 int main(int argc, char** argv)
 {
-  struct video_mmap mm;
-  struct video_mbuf vm;
-  struct video_channel vchan;
-  struct video_audio va;
-  struct video_tuner vt;
+  int tuner_fd;
+  int video_frame_rate = 25;
+  UINT64 per_frame = (UINT64) (((UINT64)1000000 * (UINT64)10000) / (UINT64)video_frame_rate);
+  UINT8 *video_buf = NULL;
 
-  char *videodevice = "/dev/video0";
+  char *videodevice = "/dev/bktr0";
   char c;
-  int secam;
-  int channel=0;
+  int channel=1;
   double  frequency=0.0;
   long v4lfrequency=0;
   int volume = -1;
@@ -1277,109 +1392,28 @@
   testinput();
 #else
 
-  fd = open(videodevice, O_RDWR|O_CREAT);
+  fd = open(videodevice, O_RDONLY);
   if(fd<=0){
     perror("open");
     fatherhandler(-1);
   }
-    
-  if(ioctl(fd, VIDIOCGMBUF, &vm)<0)
-  {
-  	perror("VIDIOCMCAPTUREi0");
-  	fatherhandler(-1);
-  }
-  if(vm.frames<2)
-  {
-  	fprintf(stderr, "stoopid prog want min 2 cap buffs!\n");
-  	fatherhandler(-1);
+  tuner_fd = open ("/dev/tuner0", O_RDWR);
+  if (tuner_fd < 0) {
+  	 perror("Warning: Tuner not opened continuing");
   }
-
-  // fprintf(stderr, "We have vm.frames=%d\n", vm.frames);
-    
-  buf = (unsigned char*)mmap(0, vm.size, PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
-  if (buf<=0)
-  {
-   perror("mmap");
-   fatherhandler(-1);
-  }	
-
-
-  vchan.channel = channel;
-  if(ioctl(fd, VIDIOCGCHAN, &vchan)<0) perror("VIDIOCGCHAN");
-
-  // choose the right input
-  if(ioctl(fd, VIDIOCSCHAN, &vchan)<0) perror("VIDIOCSCHAN");
-  
-  // if channel has a audio then activate it
-  if ((vchan.flags & VIDEO_VC_AUDIO)==VIDEO_VC_AUDIO) {
-    // we assume only a channel with audio can have a tuner therefore
-    // we only tune here if we are supposed to
-    if (frequency != 0.0) {
-      v4lfrequency  = ((unsigned long)frequency)*16; 
-      v4lfrequency |= ((unsigned long)( (frequency-(v4lfrequency/16))*100 )*16)/100; // ??????
-      if (ioctl(fd, VIDIOCSFREQ, &v4lfrequency)<0) perror("VIDIOCSFREQ");
-      if (!quiet) fprintf(stderr, "tuner frequency set to '%5.4f' MHz.\n", frequency);
-    }
-    if (!quiet) fprintf(stderr, "%s\n", "unmuting tv-audio");
-    // audio hack, to enable audio from tvcard, in case we use a tuner
-    va.audio = 0; // use audio channel 0
-    if (ioctl(fd, VIDIOCGAUDIO, &va)<0) perror("VIDIOCGAUDIO"); 
-    origaudio = va;
-    if (!quiet) fprintf(stderr, "audio volume was '%d'\n", va.volume);
-    va.audio = 0;
-    va.flags &= ~VIDEO_AUDIO_MUTE; // now this really has to work
-
-    if ((volume==-1 && va.volume<32768) || volume!=-1) {
-      if (volume==-1) {
-        va.volume = 32768;            // no more silence 8-)
-      } else {
-        va.volume = volume;
-      }
-      if (!quiet) fprintf(stderr, "audio volume set to '%d'\n", va.volume);
-    }
-    if (ioctl(fd, VIDIOCSAUDIO, &va)<0) perror("VIDIOCSAUDIO");
-  } else {
-    if (!quiet) fprintf(stderr, "channel '%d' has no tuner (composite)\n", channel);
+ 
+  bktr_init (fd, w, h, &video_buf, channel);
+  if (frequency != 0.0) {
+    v4lfrequency  = (unsigned long)(frequency*16); 
+    if (ioctl(tuner_fd, TVTUNER_SETFREQ, &v4lfrequency)<0)
+	   perror("TVTUNER_SETFREQ");
+    if (!quiet)
+	   fprintf(stderr, "tuner frequency set to '%5.4f' MHz.\n", frequency);
   }
 
-  // setting video mode
-  vt.tuner = 0;
-  if(ioctl(fd, VIDIOCGTUNER, &vt)<0) perror("VIDIOCGTUNER");
-  if (ntsc)         { vt.flags |= VIDEO_TUNER_NTSC;  vt.mode |= VIDEO_MODE_NTSC; }
-    else if (secam) { vt.flags |= VIDEO_TUNER_SECAM; vt.mode |= VIDEO_MODE_SECAM; }
-      else          { vt.flags |= VIDEO_TUNER_PAL;   vt.mode |= VIDEO_MODE_PAL; }
-  vt.tuner = 0;
-  if(ioctl(fd, VIDIOCSTUNER, &vt)<0) perror("VIDIOCSTUNER");
-
-  // make sure we use the right input
-  if(ioctl(fd, VIDIOCSCHAN, &vchan)<0) perror("VIDIOCSCHAN");
-
-  mm.height = h;
-  mm.width  = w;
-  mm.format = VIDEO_PALETTE_YUV420P    ; /* YCrCb422 */
-
-  mm.frame  = 0;
-  if(ioctl(fd, VIDIOCMCAPTURE, &mm)<0) perror("VIDIOCMCAPTUREi0");
-  mm.frame  = 1;
-  if(ioctl(fd, VIDIOCMCAPTURE, &mm)<0) perror("VIDIOCMCAPTUREi1");
-
   while(1) {
-    frame=0;
-    mm.frame  = 0;
-    if(ioctl(fd, VIDIOCSYNC, &frame)<0) perror("VIDIOCSYNC0");
-    else {
-      if(ioctl(fd, VIDIOCMCAPTURE, &mm)<0) perror("VIDIOCMCAPTURE0");
-      DP("Captured 0er");
-      bufferit(buf+vm.offsets[0]);
-    }
-    frame=1;
-    mm.frame  = 1;
-    if(ioctl(fd, VIDIOCSYNC, &frame)<0) perror("VIDIOCSYNC1");
-    else {
-      if(ioctl(fd, VIDIOCMCAPTURE, &mm)<0) perror("VIDIOCMCAPTURE1");
-      DP("Captured 1er");
-      bufferit(buf+vm.offsets[1]);
-    }
+     bktr_getframe (w, h, per_frame);
+	  bufferit(video_buf);
   }
 #endif
 
