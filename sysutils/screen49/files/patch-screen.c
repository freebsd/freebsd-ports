--- screen.c.orig	2017-07-10 12:26:25.000000000 -0700
+++ screen.c	2017-08-25 20:20:20.471073000 -0700
@@ -2214,7 +2214,7 @@
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
