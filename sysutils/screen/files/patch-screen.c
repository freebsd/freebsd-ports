--- screen.c.orig	2017-01-17 11:28:29.397404660 -0800
+++ screen.c	2017-01-24 17:31:24.342944000 -0800
@@ -674,11 +674,14 @@
               if (strlen(screenlogfile) > PATH_MAX)
                 Panic(0, "-L: logfile name too long. (max. %d char)", PATH_MAX);
 
+#if 0
+/* see https://lists.gnu.org/archive/html/screen-devel/2017-01/msg00025.html */
               FILE *w_check;
               if ((w_check = fopen(screenlogfile, "w")) == NULL)
                 Panic(0, "-L: logfile name access problem");
               else
                 fclose(w_check);
+#endif
             }
             nwin_options.Lflag = 1;
             break;
@@ -2222,7 +2225,7 @@
   pn2 = pn = p + padlen;
   r = winmsg_numrend;
   while (p >= buf) {
-    if (r && *p != 127 && p - buf == winmsg_rendpos[r - 1]) {
+    if (r && p - buf == winmsg_rendpos[r - 1]) {
       winmsg_rendpos[--r] = pn - buf;
       continue;
     }
