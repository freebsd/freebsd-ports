--- src/yencode/crc.cc.orig	2022-05-29 12:33:49 UTC
+++ src/yencode/crc.cc
@@ -43,10 +43,8 @@ int cpu_supports_crc_isa();
 #  include <cpu-features.h>
 # elif defined(__linux__) || (defined(__FreeBSD__) && __FreeBSD__ >= 12)
 #  include <sys/auxv.h>
-#  include <asm/hwcap.h>
 # elif (defined(__FreeBSD__) && __FreeBSD__ < 12)
 #  include <sys/sysctl.h>
-#  include <asm/hwcap.h>
 # elif defined(__APPLE__)
 #  include <sys/types.h>
 #  include <sys/sysctl.h>
