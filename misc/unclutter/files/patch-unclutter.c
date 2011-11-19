--- unclutter.c.orig	1994-04-11 17:40:47.000000000 +0200
+++ unclutter.c	2011-11-14 17:02:18.000000000 +0100
@@ -18,11 +18,13 @@
  * visibility events.)
  * Mark M Martin. cetia feb 1994  mmm@cetia.fr
  * keystroke code from Bill Trost trost@cloud.rain.com
+ * 11May2011 idlecommand added.
  */
 #include <X11/Xos.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xproto.h>
+#include <stdlib.h>
 #include <stdio.h>
 #include "vroot.h"
 
@@ -37,6 +39,7 @@
 	-idle <seconds>		time between polls to detect idleness.\n\
 	-keystroke		wait for keystroke before idling.\n\
 	-jitter <pixels>	pixels mouse can twitch without moving\n\
+	-exec <idlecommand>	execute idlecommand on idle.\n\
 	-grab			use grabpointer method not createwindow\n\
 	-reset			reset the timer whenever cursor becomes\n\
 					visible even if it hasn't moved\n\
@@ -126,6 +129,7 @@
     Window *realroot;
     Window root;
     char *displayname = 0;
+    char *idlecommand = 0;
     
     progname = *argv;
     argc--;
@@ -134,6 +138,10 @@
 	    argc--,argv++;
 	    if(argc<0)usage();
 	    idletime = atoi(*argv);
+	}else if(strcmp(*argv,"-exec")==0){
+	    argc--,argv++;
+	    if(argc<0)usage();
+	    idlecommand = *argv;
 	}else if(strcmp(*argv,"-keystroke")==0){
 	    idletime = -1;
 	}else if(strcmp(*argv,"-jitter")==0){
@@ -253,6 +261,8 @@
 	    if(idletime>=0)
 		sleep(idletime);
 	}
+	if(idlecommand!=0)
+	    system(idlecommand);
 	/* wait again next time */
 	if(waitagain)
 	    oldx = -1-jitter;
