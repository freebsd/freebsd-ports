--- main.c.orig	2017-09-27 19:42:51 UTC
+++ main.c
@@ -20,7 +20,7 @@
 #include <sys/param.h>
 #if HAVE_CAPSICUM
 # include <sys/resource.h>
-# include <sys/capability.h>
+# include <sys/capsicum.h>
 #endif
 
 #if HAVE_ERR
