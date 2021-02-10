--- src/opaque.c.orig	2021-02-09 21:56:37 UTC
+++ src/opaque.c
@@ -32,6 +32,7 @@
 /* Original: https://svnweb.freebsd.org/base/head/sbin/sysctl/sysctl.c */
 
 #include <sys/param.h>
+#include <sys/queue.h>
 #include <sys/resource.h>
 #include <sys/time.h>
 #include <sys/vmmeter.h>
