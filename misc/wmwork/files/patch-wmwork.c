$FreeBSD$

--- wmwork.c.orig	Thu May 16 09:48:59 2002
+++ wmwork.c	Thu May 16 09:46:29 2002
@@ -11,10 +11,9 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
-#include <time.h>
 #include <unistd.h>
 #include <sys/stat.h>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include <X11/xpm.h>

 #include "wmgeneral.h"
@@ -43,7 +43,8 @@
 
 char wmwork_mask_bits[64*64];
 char logname[MAX_STRING];
-struct timeb now;
+struct timeval now;
+struct timezone tz;
 struct Project
 	*current = NULL,
 	*first   = NULL;
@@ -54,9 +55,9 @@
 	int n,
 		show_days = 0,
 		but_stat  = 0,
-		millitm   = 0,
 		running   = 0;
 	long
+		microtm   = 0,
 		last_time = 0;
 	static int signals[] =
 		{SIGALRM, SIGHUP, SIGINT, SIGPIPE, SIGPOLL, SIGTERM, SIGUSR1, SIGUSR2, 0};
@@ -89,17 +90,17 @@
 	AddMouseRegion(BUT_STOP,  41, 48, 58, 58);
 	AddMouseRegion(BUT_PREV,   5, 33, 16, 43);
 	AddMouseRegion(BUT_NEXT,  47, 33, 58, 43);
-	drawTime(current->time, sess_time, millitm, show_days);
+	drawTime(current->time, sess_time, microtm, show_days);
 	drawProject(current->name);
 
 	while (1) {
-		last_time = now.time;
-		ftime(&now);
+		last_time = now.tv_sec;
+		gettimeofday(&now, &tz);
 		if (running) {
-			current->time += now.time - last_time;
-			sess_time     += now.time - last_time;
-			millitm        = now.millitm;
-			drawTime(current->time, sess_time, millitm, show_days);
+			current->time += now.tv_sec - last_time;
+			sess_time     += now.tv_sec - last_time;
+			microtm        = now.tv_usec;
+			drawTime(current->time, sess_time, microtm, show_days);
 			RedrawWindow();
 		}
 		while (XPending(display)) {
@@ -159,7 +160,7 @@
 							current = current->next;
 						break;
 					}
-					drawTime(current->time, sess_time, millitm, show_days);
+					drawTime(current->time, sess_time, microtm, show_days);
 					drawProject(current->name);
 				}
 				RedrawWindow();
@@ -272,7 +273,7 @@
 	}
 }
 
-void drawTime(long time1, long time2, int millitm, int show_days)
+void drawTime(long time1, long time2, int microtm, int show_days)
 {
 	long  d1 = 0, d2 = 0, h1 = 0, h2 = 0;
 	short m1 = 0, m2 = 0, s1 = 0, s2 = 0;
@@ -337,7 +338,7 @@
 		copyXPMArea(TIMER_SRC_X(s2 %  10), TIMER_SRC_Y, 5, 7, 52, 20);
 	}
 
-	if (millitm < 500) {
+	if (microtm < 500000) {
 		copyXPMArea(161, CHAR_SRC_Y1, 1, 7, 27,  6);
 		copyXPMArea(161, CHAR_SRC_Y1, 1, 7, 27, 20);
 		copyXPMArea(161, CHAR_SRC_Y1, 1, 7, 43,  6);
@@ -502,7 +503,7 @@
 		perror("fopen");
 		return;
 	}
-	strftime(t_buffer, 64, "%a %b %d %H:%M:%S %Z %Y", localtime(&now.time));
+	strftime(t_buffer, 64, "%a %b %d %H:%M:%S %Z %Y", localtime(&now.tv_sec));
 	fprintf(F, "%s %s %03li:%02li:%02li\n", t_buffer, current->name, sess_time / 3600, sess_time / 60 % 60, sess_time % 60);
 	fclose(F);
 }
