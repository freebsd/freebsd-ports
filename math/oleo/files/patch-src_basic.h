--- src/basic.h.orig	2000-08-10 21:02:49 UTC
+++ src/basic.h
@@ -36,9 +36,6 @@ enum motion_magic
 
 extern const int colmagic[9];
 extern  const int rowmagic[9];
-extern char * motion_name[9];
-extern enum motion_magic complementary_motion[9];
-extern enum motion_magic opposite_motion[9];
 
 extern int run_load_hooks;
 
