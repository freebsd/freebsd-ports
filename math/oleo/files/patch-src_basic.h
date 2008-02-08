--- src/basic.h.orig	2008-02-08 16:40:42.000000000 +0100
+++ src/basic.h	2008-02-08 16:40:48.000000000 +0100
@@ -36,9 +36,6 @@
 
 extern const int colmagic[9];
 extern  const int rowmagic[9];
-extern char * motion_name[9];
-extern enum motion_magic complementary_motion[9];
-extern enum motion_magic opposite_motion[9];
 
 extern int run_load_hooks;
 
