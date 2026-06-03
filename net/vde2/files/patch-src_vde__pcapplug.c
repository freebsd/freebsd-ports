--- src/vde_pcapplug.c.orig	2026-03-23 08:45:44 UTC
+++ src/vde_pcapplug.c
@@ -32,7 +32,6 @@
 #include <libgen.h>
 #define _GNU_SOURCE
 #include <getopt.h>
-#include <pcap.h>
 #include <limits.h>
 
 #include <config.h>
@@ -41,8 +40,11 @@
 #include <libvdeplug.h>
 
 #ifdef VDE_FREEBSD
+#include <net/bpf.h>
 #include <sys/socket.h>
 #endif
+
+#include <pcap.h>
 
 #if defined(VDE_DARWIN) || defined(VDE_FREEBSD)
 #	if defined HAVE_SYSLIMITS_H
