--- libcpupowerd.c.orig	2008-11-13 22:38:33.000000000 +0100
+++ libcpupowerd.c	2008-11-13 22:39:19.000000000 +0100
@@ -33,6 +33,7 @@
 #include <sys/ioctl.h>
 #include <sys/sysctl.h>
 #ifdef __FreeBSD__
+#include <sys/param.h>
 #if __FreeBSD_version < 800042
 #include <cpu.h>
 #define RDMSR			CPU_RDMSR
