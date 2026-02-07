--- dev/ptx/ptx.h.orig	2011-12-13 19:19:39 UTC
+++ dev/ptx/ptx.h
@@ -4,6 +4,7 @@
 
 #include <sys/bus.h>
 #include <sys/types.h>
+#include <sys/lock.h>
 #include <sys/mutex.h>
 #include <sys/module.h>
 #include <sys/kernel.h>
