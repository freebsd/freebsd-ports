--- wmwave.c.orig	Fri Aug 29 23:52:38 2003
+++ wmwave.c	Fri Aug 29 23:52:43 2003
@@ -1,38 +1,23 @@
 /*
- * wmtop.c -- WindowMaker process view dock app
- * Derived by Carsten Schuermann   carsten@schuermann.org
- * http://www.schuermann.org/~carsten
- * from
- * Dan Piponi dan@tanelorn.demon.co.uk
- * http://www.tanelorn.demon.co.uk
- * who derived it 
- * from code originally contained in wmsysmon by Dave Clark (clarkd@skynet.ca)
+ * $Id$
+ * 
+ * wmwave.c -- WindowMaker IEEE802.11 status dock app
+ *             based on wmtop.c from Dan Piponi
+ * 
  * This software is licensed through the GNU General Public License.
- * $Log: wmwave.c,v $
- * Revision 1.7  1999/08/20 13:44:21  carsten
- * version 0.4 complete
- *
- * Revision 1.6  1999/08/19 17:58:52  carsten
- * Almost final version
- *
- * Revision 1.5  1999/08/19 13:54:30  carsten
- * done
- *
- * Revision 1.4  1999/08/19 11:14:50  carsten
- * hookup to /proc/net/wirless complete
- *
- * Revision 1.3  1999/08/19 02:39:07  carsten
- * improved design and hooked it up
- *
- * Revision 1.2  1999/08/16 03:45:34  carsten
- * Added dots
- *
- * Revision 1.1  1999/08/15 15:39:18  carsten
- * Added wmwave project to repository
- *
+ * 
+ * Authors (in reverse chronological order):
+ * Hendrik Scholz <hscholz@raisdorf.net>
+ * Bruce M. Simpson <bms@spc.org>
+ * Carsten Schuermann <carsten@schuermann.org>
+ * Dan Piponi <dan@tanelorn.demon.co.uk>
+ * Dave Clark <clarkd@skynet.ca>
+ * 
+ * The FreeBSD version of this software is released under the GNU GPL, and
+ * forms part of the Consume Project <URL: http://www.consume.net/>.
+ * 
  */
 
-
 #include <stdlib.h>
 #include <stdio.h>
 #include <time.h>
@@ -45,313 +30,384 @@
 #include <limits.h>
 #include <errno.h>
 #include <signal.h>
+#include <sysexits.h>
 
+#include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
 #include <sys/param.h>
-#include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/time.h>
+#include <sys/socket.h>
+#include <sys/sockio.h>
+
+#include <netdb.h>
+#include <net/if.h>
+#include <net/if_var.h>
+#include <net/route.h>
+#include <net/ethernet.h>
+
+#include <netinet/in.h>
+#include <netinet/in_systm.h>
+#include <netinet/in_var.h>
+#include <netinet/ip.h>
+#include <netinet/ip_var.h>
+#include <arpa/inet.h>
+
+#include <dev/wi/if_wavelan_ieee.h>
 
 #include <X11/Xlib.h>
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
 
-
 #include "wmgeneral.h"
-
 #include "wmwave-master.xpm"
 
-char wmwave_mask_bits[64*64];
-int wmwave_mask_width = 64;
-int wmwave_mask_height = 64;
-
-#define WMWAVE_VERSION "0.4"
+char            wmwave_mask_bits[64 * 64];
+int             wmwave_mask_width = 64;
+int             wmwave_mask_height = 64;
+
+#define WMWAVE_DEFAULT_INTERFACE	"wi0"
+#define WMWAVE_VERSION			"0.4_FreeBSD-2"
+
+int             update_rate = 100000;
+char            *ProgName;
+char			*iface = WMWAVE_DEFAULT_INTERFACE;
+time_t          curtime;
+time_t          prevtime;
+int             mode = 0;	/* default: no card detected */
+int             screen = 0;	/* default: Quality screen is displayed */
+
+void            usage(void);
+void            printversion(void);
+void            BlitString(char *name, int x, int y);
+void            BlitNum(int num, int x, int y);
+void            wmwave_routine(int, char **);
+void            DrawBar(float percent, int dx, int dy);
+void            DrawGreenBar(float percent, int dx, int dy);
 
-int update_rate=100000;
-
-char *ProgName;
-
-time_t curtime;
-time_t prevtime;
-
-int mode = 0;    // default: no card detected
-int screen = 0;  // default: Quality screen is displayed
-
-void usage(void);
-void printversion(void);
-void BlitString(char *name, int x, int y);
-void BlitNum(int num, int x, int y);
-void wmwave_routine(int, char **);
-void DrawBar(float percent, int dx, int dy);
-void DrawGreenBar(float percent, int dx, int dy);
+inline void
+DrawBar(float percent, int dx, int dy)
+{
+	int             tx;
 
-inline void DrawBar(float percent, int dx, int dy) {
-  int tx;
-  
-  tx = (float)((float)54 * ((float)percent / (float)100.0));
-  copyXPMArea(67, 36, tx, 4, dx, dy);
-  copyXPMArea(67, 43, 54-tx, 4, dx+tx, dy); 
+	tx = (float)((float)54 * ((float)percent / (float)100.0));
+	copyXPMArea(67, 36, tx, 4, dx, dy);
+	copyXPMArea(67, 43, 54 - tx, 4, dx + tx, dy);
 }
 
 
-inline void DrawGreenBar(float percent, int dx, int dy) {
-  int tx;
-  
-  tx = (float)((float)54 * ((float)percent / (float)100.0));
-  copyXPMArea(67, 58, tx, 4, dx, dy);
-  copyXPMArea(67, 43, 54-tx, 4, dx+tx, dy); 
+inline void
+DrawGreenBar(float percent, int dx, int dy)
+{
+	int             tx;
+
+	tx = (float)((float)54 * ((float)percent / (float)100.0));
+	copyXPMArea(67, 58, tx, 4, dx, dy);
+	copyXPMArea(67, 43, 54 - tx, 4, dx + tx, dy);
 }
 
-inline void DrawRedDot() {
-  copyXPMArea(80, 65, 6, 6, 52, 5);
+inline void
+DrawRedDot()
+{
+	copyXPMArea(80, 65, 6, 6, 52, 5);
 }
 
-inline void DrawYellowDot() {
-  copyXPMArea(86, 65, 6, 6, 52, 5);
+inline void
+DrawYellowDot()
+{
+	copyXPMArea(86, 65, 6, 6, 52, 5);
 }
 
-inline void DrawGreenDot() {
-  copyXPMArea(92, 65, 6, 6, 52, 5);
+inline void
+DrawGreenDot()
+{
+	copyXPMArea(92, 65, 6, 6, 52, 5);
 }
 
-inline void DrawEmptyDot() {
-  copyXPMArea(98, 65, 6, 6, 52, 5);
+inline void
+DrawEmptyDot()
+{
+	copyXPMArea(98, 65, 6, 6, 52, 5);
 }
 
-float min (float x, float y) {
-  if (x < y) {return x;}
-  else {return y;}
+/*
+ * XXX: redefining min() to operate on floats is a bad idea;
+ * changed to _fmin().
+ */
+float
+_fmin(float x, float y)
+{
+	if (x < y) {
+		return x;
+	} else {
+		return y;
+	}
 }
 
 /*
- * Find CPU times for all processes
+ * XXX: Fetch OS-specific wireless statistics.
+ * 
+ * These are: quality, signal, noise. On NetBSD, the 
+ * statistics kept on an AP-basis for the driver are valid.
+ * On FreeBSD, it is necessary to interrogate the WICACHE.
+ * For the purposes of keeping things simple, this code will only
+ * look at the first slot in the WICACHE table.
  */
-void DisplayWireless(void) {
-  FILE *wireless;   // File handle for /proc/net/wireless
-					      
-  char line[255];
-  char iface[5];
-  char status [3];
-  float link = 0;
-  float level = 0;
-  float noise = 0;
-  int nwid = 0;
-  int crypt = 0;
-  int misc = 0;
-  
-  if ((wireless = fopen ("/proc/net/wireless", "r")) != NULL)
-    {
-      fgets(line,sizeof(line),wireless);
-      fgets(line,sizeof(line),wireless);
-      if (fgets(line,sizeof(line),wireless) == NULL) {
-	mode = 0;
-      }
-      else {
-	sscanf(line,"%s %s %f %f %f %d %d %d",
-	       iface,status,&link,&level,&noise,&nwid,&crypt,&misc);
-	mode = 1;
-      }
-      fclose(wireless);
-      
-      
-      /* Print channel information, and signal ratio */
-      
-      switch (mode) {
-      case 1: BlitString("Quality",4,4);
-	if (link<=10) {DrawRedDot ();}
-	else if (link<=20) {DrawYellowDot ();}
-	else {DrawGreenDot();};
-	BlitString("Link     ", 4,18);	
-	DrawBar(min ((int)(link * 1.8), 100.0), 4, 27);
-	BlitString("Level    ", 4,32);
-	DrawGreenBar(min ((int)(level * 0.3), 100.0), 4, 41);
-	BlitString("Noise    ", 4,46);
-	DrawGreenBar(min ((int)(noise * 0.3), 100.0), 4, 55);
-	break;
-      case 0: BlitString("NO CARD",4,4);
-	DrawEmptyDot();
-	BlitString("         ", 4,18);
-	DrawBar(0.0, 4, 27);
-	BlitString("         ", 4,32);
-	DrawGreenBar(0.0, 4, 41);
-	BlitString("         ", 4,46);
-	DrawGreenBar(0.0, 4, 55);
-	break;
-      };
+void
+DisplayWireless(void)
+{
+        struct ifreq             ifr;
+        struct wi_req            wireq;
+        struct wi_sigcache      *wisigsp;
+        int                     *wisigsnp, s, mode, err;
+	float  	                 link, level, noise;
+	enum {
+		MODE_NO_CARD = 0,
+		MODE_HAVE_CARD = 1
+	};
+
+    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
+    if (s == -1) 
+    	errx(errno, "socket");
+    bzero(&ifr, sizeof(ifr));
+    strncpy(ifr.ifr_name, iface, strlen(iface));
+    bzero(&wireq, sizeof(wireq));
+    wireq.wi_type = WI_RID_COMMS_QUALITY;
+    wireq.wi_len = WI_MAX_DATALEN;
+    ifr.ifr_data = (void *) &wireq;
+
+    err = ioctl(s, SIOCGWAVELAN, (caddr_t)&ifr);
+    if (err < 0) {
+		mode = MODE_NO_CARD;
+		goto draw;
     }
-  else {
-    printf ("Wirless device /proc/net/wireless not found\nEnable radio networking and recompile your kernel\n");
-    exit (0);
-  }
-}
-
-/* SIGCHLD handler */
-void sig_chld(int signo)
-{
-  waitpid((pid_t) -1, NULL, WNOHANG);
-  signal(SIGCHLD, sig_chld);
-}
-
-int main(int argc, char *argv[]) {
-  int i;
-  
-  /* Parse Command Line */
-  
-  signal(SIGCHLD, sig_chld);
-  ProgName = argv[0];
-  if (strlen(ProgName) >= 5)
-    ProgName += (strlen(ProgName) - 5);
-  
-  for (i=1; i<argc; i++) {
-    char *arg = argv[i];
-    
-    if (*arg=='-') {
-      switch (arg[1]) {
-      case 'd' :
-	if (strcmp(arg+1, "display")) {
-	  usage();
-	  exit(1);
-	}
-	break;
-      case 'g' :
-	if (strcmp(arg+1, "geometry")) {
-	  usage();
-	  exit(1);
-	}
-	break;
-      case 'v' :
-	printversion();
-	exit(0);
-	break;
-      case 'r':
-	if (argc > (i+1)) {
-	  update_rate = (atoi(argv[i+1]) * 1000);
-	  i++;
+
+	mode = MODE_HAVE_CARD;
+	link = wireq.wi_val[0];
+	level = wireq.wi_val[1];
+	noise = wireq.wi_val[2];
+
+draw:
+	/*
+	 * Print channel information, and signal ratio
+	 */
+	switch (mode) {
+	case MODE_HAVE_CARD:
+		BlitString("Quality", 4, 4);
+		if (link <= 10) {
+			DrawRedDot();
+		} else if (link <= 20) {
+			DrawYellowDot();
+		} else {
+			DrawGreenDot();
+		};
+		BlitString("Quality  ", 4, 18);
+		DrawBar(_fmin((int)(link * 1.8), 100.0), 4, 27);
+		BlitString("Signal   ", 4, 32);
+		DrawGreenBar(_fmin((int)(level * 0.3), 100.0), 4, 41);
+		BlitString("Noise    ", 4, 46);
+		DrawGreenBar(_fmin((int)(noise * 0.3), 100.0), 4, 55);
+		break;
+	case MODE_NO_CARD:
+	default:
+		BlitString("NO CARD", 4, 4);
+		DrawEmptyDot();
+		BlitString("         ", 4, 18);
+		DrawBar(0.0, 4, 27);
+		BlitString("         ", 4, 32);
+		DrawGreenBar(0.0, 4, 41);
+		BlitString("         ", 4, 46);
+		DrawGreenBar(0.0, 4, 55);
+		break;
+	};
+	close(s);
+}
+
+void
+sig_chld(int signo)
+{
+	waitpid((pid_t) - 1, NULL, WNOHANG);
+	signal(SIGCHLD, sig_chld);
+}
+
+int
+main(int argc, char *argv[])
+{
+	int             i;
+
+
+	signal(SIGCHLD, sig_chld);
+
+	ProgName = argv[0];
+	if (strlen(ProgName) >= 5)
+		ProgName += (strlen(ProgName) - 5);
+
+	for (i = 1; i < argc; i++) {
+		char           *arg = argv[i];
+
+		if (*arg == '-') {
+			switch (arg[1]) {
+			case 'i':
+				if (argc > (i + 1)) {
+					iface = argv[i+1];
+					if (strncmp("wi", iface, 2) != 0) {
+						fprintf(stderr, "error: you "
+					"must specify a wiX interface.\n");
+						usage();
+						exit(EX_USAGE);
+					}
+				}
+				break;
+			case 'd':
+				if (strcmp(arg + 1, "display")) {
+					usage();
+					exit(EX_USAGE);
+				}
+				break;
+			case 'g':
+				if (strcmp(arg + 1, "geometry")) {
+					usage();
+					exit(EX_USAGE);
+				}
+				break;
+			case 'v':
+				printversion();
+				exit(EX_OK);
+				break;
+			case 'r':
+				if (argc > (i + 1)) {
+					update_rate = (atoi(argv[i+1]) * 1000);
+					i++;
+				}
+				break;
+			default:
+				usage();
+				exit(EX_USAGE);
+				break;
+			}
+		}
 	}
-	break;
-      default:
-	usage();
-	exit(0);
-	break;
-      }
-    }
-  }
-  
-  wmwave_routine(argc, argv);
-  
-  return 0;
+
+	wmwave_routine(argc, argv);
+
+	exit(EX_OK);
 }
 
 /*
  * Main loop
  */
-void wmwave_routine(int argc, char **argv) {
-  XEvent Event;
-  struct timeval tv={0,0};
-  struct timeval last={0,0};
-  
-  createXBMfromXPM(wmwave_mask_bits, wmwave_master_xpm, wmwave_mask_width, wmwave_mask_height);
-  
-  openXwindow(argc, argv, wmwave_master_xpm, wmwave_mask_bits, wmwave_mask_width, wmwave_mask_height);
-  
-  RedrawWindow();
-  
-  
-  while (1) {
-    
-    curtime = time(0);
-    
-    if (1) {
-      memcpy(&last, &tv, sizeof(tv));
-      
-      /*
-       * Update display
-       */
-      DisplayWireless();
-      
-      RedrawWindow();
-    }
-    
-    /*
-     * X Events
-     */
-    while (XPending(display)) {
-      XNextEvent(display, &Event);
-      switch (Event.type) {
-      case Expose:
+void
+wmwave_routine(int argc, char **argv)
+{
+	XEvent          Event;
+	struct timeval  tv = {0, 0};
+	struct timeval  last = {0, 0};
+
+	createXBMfromXPM(wmwave_mask_bits, wmwave_master_xpm, wmwave_mask_width, wmwave_mask_height);
+
+	openXwindow(argc, argv, wmwave_master_xpm, wmwave_mask_bits, wmwave_mask_width, wmwave_mask_height);
+
 	RedrawWindow();
-	break;
-      case DestroyNotify:
-	XCloseDisplay(display);
-	exit(0);
-      case ButtonPress:
-	switch (screen) {
-	case 0: screen=1; break;
-	case 1: screen=0; break;
-	};
-	break;
-      }
-    }
-    
-    usleep(update_rate);
-  }
+
+	for (;;) {
+		curtime = time(0);
+		memcpy(&last, &tv, sizeof(tv));
+
+		/*
+		 * Update display
+		 */
+		DisplayWireless();
+		RedrawWindow();
+
+		/*
+		 * X Events
+		 */
+		while (XPending(display)) {
+			XNextEvent(display, &Event);
+			switch (Event.type) {
+			case Expose:
+				RedrawWindow();
+				break;
+			case DestroyNotify:
+				XCloseDisplay(display);
+				exit(EX_OK);
+			case ButtonPress:
+				switch (screen) {
+				case 0:
+					screen = 1;
+					break;
+				case 1:
+					screen = 0;
+					break;
+				};
+				break;
+			}
+		}
+		usleep(update_rate);
+	}
 }
 
 /*
  * Blits a string at given co-ordinates
  */
-void BlitString(char *name, int x, int y) {
-  int	i;
-  int	c;
-  int	k;
-  
-  k = x;
-  for (i=0; name[i]; i++)
-    {
-      
-      c = toupper(name[i]); 
-      if (c >= 'A' && c <= 'Z')
-        {   // its a letter
-		 c -= 'A';
-	copyXPMArea(c * 6, 74, 6, 8, k, y);
-	k += 6;
-	} else
-	  if (c>='0' && c<='9') {   // its a number or symbol
-					 c -= '0';
-	  copyXPMArea(c * 6, 64, 6, 8, k, y);
-	  k += 6;
-	  } else {
-	    copyXPMArea(5, 84, 6, 8, k, y);
-	    k += 6;
-	    
-	  }
-    }
+void
+BlitString(char *name, int x, int y)
+{
+	int             i;
+	int             c;
+	int             k;
+
+	k = x;
+	for (i = 0; name[i]; i++) {
+
+		c = toupper(name[i]);
+		if (c >= 'A' && c <= 'Z') {	/* its a letter */
+			c -= 'A';
+			copyXPMArea(c * 6, 74, 6, 8, k, y);
+			k += 6;
+		} else if (c >= '0' && c <= '9') {
+			/* its a number or symbol */
+			c -= '0';
+			copyXPMArea(c * 6, 64, 6, 8, k, y);
+			k += 6;
+		} else {
+			copyXPMArea(5, 84, 6, 8, k, y);
+			k += 6;
+
+		}
+	}
 }
 
-void BlitNum(int num, int x, int y) {
-  char buf[1024];
-  int newx=x;
-  
-  sprintf(buf, "%03i", num);
-  
-  BlitString(buf, newx, y);
+void
+BlitNum(int num, int x, int y)
+{
+	char            buf[1024];
+	int             newx = x;
+
+	sprintf(buf, "%03i", num);
+	BlitString(buf, newx, y);
 }
 
 /*
  * Usage
  */
-void usage(void) {
-  fprintf(stderr, "\nWmwave - Carsten Schuermann <carsten@schuermann.org>  http://www.schuermann.org/~dockapps\n\n");
-  fprintf(stderr, "usage:\n");
-  fprintf(stderr, "    -display <display name>\n");
-  fprintf(stderr, "    -r                        update rate in milliseconds (default:100)\n");
-  fprintf(stderr, "\n");
+void
+usage(void)
+{
+	fprintf(stderr, "\rwmwave 0.4 - by Bruce M Simpson <bms@spc.org> et al. \n");
+	fprintf(stderr, "usage:\n");
+	fprintf(stderr, "    -display  <display name>\n");
+	fprintf(stderr, "    -i        interface to use (default to wi0)\n");
+	fprintf(stderr, "    -r        update rate in milliseconds (default:100)\n");
+	fprintf(stderr, "\n");
 }
 
 /*
  * printversion
  */
-void printversion(void) {
-  fprintf(stderr, "wmwave v%s\n", WMWAVE_VERSION);
+void
+printversion(void)
+{
+	fprintf(stderr, "wmwave v%s\n", WMWAVE_VERSION);
 }
