--- ./content/plugin/plugin_main_linux.cc.orig	2014-04-24 22:35:42.000000000 +0200
+++ ./content/plugin/plugin_main_linux.cc	2014-04-24 23:23:44.000000000 +0200
@@ -5,13 +5,13 @@
 #include <signal.h>
 #include <string.h>
 #include <sys/types.h>
-#include <syscall.h>
+#include <sys/syscall.h>
 #include <unistd.h>
 
 #include "build/build_config.h"
 
 // This whole file is only useful on 64-bit architectures.
-#if defined(ARCH_CPU_64_BITS)
+#if defined(ARCH_CPU_64_BITS) && !defined(OS_BSD)
 
 namespace content {
 
