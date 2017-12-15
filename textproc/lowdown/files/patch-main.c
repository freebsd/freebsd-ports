--- main.c.orig	2017-10-26 09:00:30 UTC
+++ main.c
@@ -20,7 +20,7 @@
 #include <sys/param.h>
 #if HAVE_CAPSICUM
 # include <sys/resource.h>
-# include <sys/capability.h>
+# include <sys/capsicum.h>
 #endif
 
 #if HAVE_ERR
