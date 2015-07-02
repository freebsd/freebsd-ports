--- screen.c.orig	2014-04-26 09:22:09.000000000 -0700
+++ screen.c	2014-04-30 23:34:47.613803805 -0700
@@ -2257,7 +2257,7 @@
   r = winmsg_numrend;
   while (p >= buf)
     {
-      if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1])
+      if (r && p - buf == winmsg_rendpos[r - 1])
 	{
 	  winmsg_rendpos[--r] = pn - buf;
 	  continue;
