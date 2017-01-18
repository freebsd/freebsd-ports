--- screen.c.orig	2017-01-17 11:28:29.397404660 -0800
+++ screen.c	2017-01-18 04:54:50.874421000 -0800
@@ -2222,7 +2222,7 @@
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
