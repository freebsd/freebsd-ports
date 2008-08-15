--- wmwave.c.orig	2008-02-27 09:24:06.628732284 +1030
+++ wmwave.c	2008-02-27 09:32:07.088117765 +1030
@@ -29,6 +29,18 @@
  *
  * Revision 1.1  1999/08/15 15:39:18  carsten
  * Added wmwave project to repository
+ * 
+ * Authors (in reverse chronological order):
+ * Benjamin Close <benjsc@freebsd.org>
+ * Hendrik Scholz <hscholz@raisdorf.net>
+ * Bruce M. Simpson <bms@spc.org>
+ * Carsten Schuermann <carsten@schuermann.org>
+ * Dan Piponi <dan@tanelorn.demon.co.uk>
+ * Dave Clark <clarkd@skynet.ca>
+ * 
+ * The FreeBSD version of this software is released under the GNU GPL, and
+ * forms part of the Consume Project <URL: http://www.consume.net/>.
+ * 
  *
  */
 
@@ -57,6 +69,23 @@
 #include <X11/xpm.h>
 #include <X11/extensions/shape.h>
 
+#include <sys/socket.h>
+#include <sys/sockio.h>
+#include <netdb.h>
+#include <net/if.h>
+#include <net/if_var.h>
+#include <net/route.h>
+#include <net/ethernet.h>
+#include <netinet/in.h>
+#include <netinet/in_systm.h>
+#include <netinet/in_var.h>
+#include <netinet/ip.h>
+#include <netinet/ip_var.h>
+#include <arpa/inet.h>
+#include <net80211/_ieee80211.h>
+#include <net80211/ieee80211.h>
+#include <net80211/ieee80211_crypto.h>
+#include <net80211/ieee80211_ioctl.h>
 
 #include "wmgeneral.h"
 
@@ -66,7 +94,9 @@
 int wmwave_mask_width = 64;
 int wmwave_mask_height = 64;
 
-#define WMWAVE_VERSION "0.4"
+#define WMWAVE_VERSION			"0.4_FreeBSD-2"
+#define WMWAVE_DEFAULT_INTERFACE	"wi0"
+char			*iface = WMWAVE_DEFAULT_INTERFACE;
 
 int update_rate=100000;
 
@@ -125,65 +155,100 @@
 }
 
 /*
- * Find CPU times for all processes
+ * XXX: Fetch OS-specific wireless statistics.
+ * 
+ * These are: quality, signal, noise. On NetBSD, the
+ * statistics kept on an AP-basis for the driver are valid.
+ * On FreeBSD, we make use of the net80211 layer to display the
+ * required stats.
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
+void DisplayWireless(void)
+{
+    struct ifreq             ifr;
+    struct ieee80211req      ireq;
+    union {
+	struct ieee80211req_sta_req stareq;
+	uint8_t buf[24*1024];
+    } u;
+    int                      s, mode, err;
+    float	                 link, level, noise;
+    enum {
+	MODE_NO_CARD = 0,
+	MODE_HAVE_CARD = 1
+    };
+
+    s = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
+    if (s == -1)
+	errx(errno, "socket");
+    bzero(&ifr, sizeof(ifr));
+    strncpy(ifr.ifr_name, iface, strlen(iface));
+
+    memset(&ireq, 0, sizeof(ireq));
+    strncpy(ireq.i_name, iface, sizeof(ireq.i_name));
+
+    // Get the currently associated ap
+    ireq.i_type = IEEE80211_IOC_BSSID;
+    ireq.i_data = u.stareq.is_u.macaddr;
+    ireq.i_len = IEEE80211_ADDR_LEN;
+    err = ioctl(s, SIOCG80211, &ireq);
+    if ( err >= 0 ){
+
+	// Get the station info for the ap
+	memset(&ireq, 0, sizeof(ireq));
+	strncpy(ireq.i_name, iface, sizeof(ireq.i_name));
+	ireq.i_type = IEEE80211_IOC_STA_INFO;
+	ireq.i_data = &u;
+	ireq.i_len  = sizeof(u);
+	err = ioctl(s, SIOCG80211, &ireq);
+	if ( err >= 0 ){
+	    const struct ieee80211req_sta_info *si = u.stareq.info;
+	    mode = MODE_HAVE_CARD;
+	    // net80211 doesn't have a link quality field so we base it on the
+	    // noise/signal level
+	    link = (si->isi_rssi-si->isi_noise)/2;
+	    level = si->isi_rssi/2;
+	    noise = abs(si->isi_noise);
+	}
     }
-  else {
-    printf ("Wirless device /proc/net/wireless not found\nEnable radio networking and recompile your kernel\n");
-    exit (0);
-  }
+
+    if (err < 0) {
+	mode = MODE_NO_CARD;
+    }
+
+draw:
+    /*
+     * Print channel information, and signal ratio
+     */
+    switch (mode) {
+	case MODE_HAVE_CARD:
+	    BlitString("Quality", 4, 4);
+	    if (link <= 10) {
+		DrawRedDot();
+	    } else if (link <= 20) {
+		DrawYellowDot();
+	    } else {
+		DrawGreenDot();
+	    };
+	    BlitString("Quality  ", 4, 18);
+	    DrawBar(min((int)(link * 1.8), 100.0), 4, 27);
+	    BlitString("Signal   ", 4, 32);
+	    DrawGreenBar(min((int)(level * 0.3), 100.0), 4, 41);
+	    BlitString("Noise    ", 4, 46);
+	    DrawGreenBar(min((int)(noise * 0.3), 100.0), 4, 55);
+	    break;
+	case MODE_NO_CARD:
+	default:
+	    BlitString("NO CARD", 4, 4);
+	    DrawEmptyDot();
+	    BlitString("         ", 4, 18);
+	    DrawBar(0.0, 4, 27);
+	    BlitString("         ", 4, 32);
+	    DrawGreenBar(0.0, 4, 41);
+	    BlitString("         ", 4, 46);
+	    DrawGreenBar(0.0, 4, 55);
+	    break;
+    };
+    close(s);
 }
 
 /* SIGCHLD handler */
@@ -208,6 +273,11 @@
     
     if (*arg=='-') {
       switch (arg[1]) {
+      case 'i':
+	  if (argc > (i + 1)) {
+	      iface = argv[i+1];
+	  }
+	  break;
       case 'd' :
 	if (strcmp(arg+1, "display")) {
 	  usage();
@@ -345,6 +415,7 @@
   fprintf(stderr, "\nWmwave - Carsten Schuermann <carsten@schuermann.org>  http://www.schuermann.org/~dockapps\n\n");
   fprintf(stderr, "usage:\n");
   fprintf(stderr, "    -display <display name>\n");
+  fprintf(stderr, "    -i        		 interface to use (default to wi0)\n");
   fprintf(stderr, "    -r                        update rate in milliseconds (default:100)\n");
   fprintf(stderr, "\n");
 }
