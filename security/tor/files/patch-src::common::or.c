diff -ur /tmp/tor-0.0.6.2/src/or/or.h ./src/or/or.h
--- /tmp/tor-0.0.6.2/src/or/or.h	Sun May  2 04:15:55 2004
+++ ./src/or/or.h	Fri May 28 14:49:34 2004
@@ -38,7 +38,9 @@
 #include <sys/limits.h>
 #endif
 #ifdef HAVE_MACHINE_LIMITS_H
+#ifndef __FreeBSD__
 #include <machine/limits.h>
+#endif
 #endif
 #ifdef HAVE_SYS_TYPES_H
 #include <sys/types.h> /* Must be included before sys/stat.h for Ultrix */
