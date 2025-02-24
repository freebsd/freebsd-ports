--- ncrystal_core/src/utils/NCCFileUtils.cc.orig	2025-02-24 09:02:29 UTC
+++ ncrystal_core/src/utils/NCCFileUtils.cc
@@ -24,12 +24,6 @@
 #  define MC_IS_WINDOWS
 #endif
 #ifndef MC_IS_WINDOWS
-#  ifndef _POSIX_C_SOURCE
-#    define _POSIX_C_SOURCE 200809L
-#  endif
-#  ifndef _XOPEN_SOURCE
-#    define _XOPEN_SOURCE 500
-#  endif
 #  include <unistd.h>
 #  include <limits.h>
 #  include <errno.h>
