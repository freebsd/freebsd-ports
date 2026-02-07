--- tclock.c.orig	1992-12-21 19:56:29 UTC
+++ tclock.c
@@ -22,7 +22,10 @@
  */ 
 
 #include <stdio.h>
+#include <stdlib.h>
+#include <unistd.h>
 #include <math.h>
+#include <time.h>
 #include <X11/Xlib.h>
 #include <X11/Xutil.h>
 #include <X11/Xos.h>
@@ -51,7 +54,7 @@ Display *display;
 int     screen_number;
 Window  rootWindow, mainWindow;
 int     ShapeEventNumber, ShapeErrorNumber;
-long    clock;
+time_t  lclock;
 struct tm lastTimes, times;
 Pixmap  border, clip;
 GC      clearGC, drawGC;
@@ -113,6 +116,8 @@ initHand(h, s)
 
   hand[h].radius[i] = hand[h].radius[0];
   hand[h].offset[i] = hand[h].offset[0];
+
+  hand[h].position = -1;
 }
 
 void
@@ -212,7 +217,7 @@ reshape()
   XShapeCombineMask(display, mainWindow, ShapeBounding, 0, 0, border, ShapeSet);
   XShapeCombineMask(display, mainWindow, ShapeClip, 0, 0, clip, ShapeSet);
 
-  XFlush(display, 1);
+  XFlush(display);
 
   /* This call to XPending ensures that if the window gets closed, we die */
   XPending(display);
@@ -222,8 +227,6 @@ XTextProperty *
 strToTP(s)
   char *s;
 {
-  extern
-  char *malloc();
 
   XTextProperty *tp = (XTextProperty *)malloc(sizeof *tp);
   XStringListToTextProperty(&s, 1, tp);
@@ -233,11 +236,11 @@ strToTP(s)
 int
 sigalrm()
 {
-  clock = time(0);
-  times = *localtime(&clock);
+  lclock = time(0);
+  times = *localtime(&lclock);
   times.tm_hour = times.tm_hour * 5 + times.tm_min / 12;
   reshape();
-  signal(SIGALRM, sigalrm);		/* For SysV lusers */
+  signal(SIGALRM, (void *)sigalrm);		/* For SysV lusers */
 }
 
 unsigned long
@@ -294,7 +297,7 @@ makeAppName(r)
   strcpy(appClass, "Tclock");
 }
 
-void
+int
 main(ac, av)
   int ac;
   char **av;
@@ -309,6 +312,7 @@ main(ac, av)
   extern
   char		*getenv();
   char		*displayName, fn[1000];
+  char		*sdb;
   int		parseReturn, rc;
 
   XrmParseCommand(&db, option, numOptions, "tclock", &ac, av);
@@ -330,7 +334,7 @@ main(ac, av)
   display = XOpenDisplay(displayName);
   if(display == 0)
   {
-    fprintf("Couldn't open display %s\n", displayName);
+    fprintf(stderr, "Couldn't open display %s\n", displayName);
     exit(-1);
   }
 
@@ -341,13 +345,14 @@ main(ac, av)
     exit(1);
 
   db = XrmGetStringDatabase(tclockDefaults);
-  XrmMergeDatabases(XrmGetStringDatabase(XResourceManagerString(display)), &db);
+  if(sdb = XResourceManagerString(display))
+    XrmMergeDatabases(XrmGetStringDatabase(sdb), &db);
   
   sprintf(fn, "%s/.Xdefaults", getenv("HOME"));
   if(access(fn, R_OK) == 0)
     XrmMergeDatabases(XrmGetFileDatabase(fn), &db);
 
-  if(getenv("XENVIRONMENT") && access(getenv("XENVIRONMENT")) == 0)
+  if(getenv("XENVIRONMENT") && access(getenv("XENVIRONMENT"), R_OK) == 0)
     XrmMergeDatabases(XrmGetFileDatabase(getenv("XENVIRONMENT")), &db);
 
   XrmMergeDatabases(cmdDB, &db);
@@ -410,7 +415,7 @@ main(ac, av)
   XMapRaised(display, mainWindow);
   XFlush(display);
 
-  signal(SIGALRM, sigalrm);
+  signal(SIGALRM, (void *)sigalrm);
   new.it_interval.tv_sec = 1;
   new.it_value.tv_sec = 1;
   new.it_interval.tv_usec = 0;
@@ -420,4 +425,3 @@ main(ac, av)
   for(;;)
     sigpause(0);
 }
-
