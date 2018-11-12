--- sandbox-capsicum.c.orig	2018-06-19 09:48:45 UTC
+++ sandbox-capsicum.c
@@ -20,7 +20,7 @@
 #if HAVE_CAPSICUM
 
 #include <sys/resource.h>
-#include <sys/capability.h>
+#include <sys/capsicum.h>
 
 #include <assert.h>
 #include <unistd.h>
