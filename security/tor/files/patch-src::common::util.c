diff -ur /tmp/tor-0.0.6.2/src/common/util.c ./src/common/util.c
--- /tmp/tor-0.0.6.2/src/common/util.c	Sun May  2 00:29:20 2004
+++ ./src/common/util.c	Fri May 28 14:49:22 2004
@@ -56,7 +56,9 @@
 #include <sys/limits.h>
 #endif
 #ifdef HAVE_MACHINE_LIMITS_H
+#ifndef __FreeBSD__
 #include <machine/limits.h>
+#endif
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h> /* Must be included before sys/stat.h for Ultrix */
