--- src/yencode/platform.cc.orig	2022-05-29 12:33:49 UTC
+++ src/yencode/platform.cc
@@ -5,10 +5,8 @@
 #  include <cpu-features.h>
 # elif defined(__linux__) || (defined(__FreeBSD__) && __FreeBSD__ >= 12)
 #  include <sys/auxv.h>
-#  include <asm/hwcap.h>
 # elif (defined(__FreeBSD__) && __FreeBSD__ < 12)
 #  include <sys/sysctl.h>
-#  include <asm/hwcap.h>
 # elif defined(_WIN32)
 #  define WIN32_LEAN_AND_MEAN
 #  define NOMINMAX
