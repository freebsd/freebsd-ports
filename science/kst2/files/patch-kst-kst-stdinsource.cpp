--- kst/kst/stdinsource.cpp.orig	Thu Apr 29 02:14:41 2004
+++ kst/kst/stdinsource.cpp	Thu Apr 29 02:15:33 2004
@@ -28,7 +28,7 @@
 # include <sys/time.h>
 # include <time.h>
 #else
-# ifdef HAVE_SYS_TIME_H
+# if defined(HAVE_SYS_TIME_H) || defined(__FreeBSD__)
 #  include <sys/time.h>
 # else
 #  include <time.h>
