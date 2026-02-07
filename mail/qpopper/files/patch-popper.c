--- popper/popper.c.orig	2011-05-31 02:13:40.000000000 +0700
+++ popper/popper.c	2020-08-20 16:22:31.645139000 +0700
@@ -430,7 +430,7 @@ DEBUG_LOG1 ( &p,"(v%s) Intro", VERSION )
 }
 
 
-jmp_buf env;
+static jmp_buf env;
 
 
 /*
