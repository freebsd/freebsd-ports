--- main.c.orig	2022-11-06 13:00:37 UTC
+++ main.c
@@ -12,6 +12,8 @@
 #include "screen.h"
 #include "misc.h"
 
+WINDOW *mainw, *logw;
+
 struct dest_new dest;
 
 int use_color = 0;
