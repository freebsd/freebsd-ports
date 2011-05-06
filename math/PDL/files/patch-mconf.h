--- Basic/Math/mconf.h.orig	2010-05-08 21:43:08.000000000 -0500
+++ Basic/Math/mconf.h	2011-03-19 17:12:01.099417176 -0500
@@ -89,8 +89,10 @@ Copyright 1984, 1987, 1989, 1995 by Step
 #endif
 #if defined __alpha && ! defined __linux
 #include <float.h>
+#ifndef __FreeBSD__
 #include <nan.h>
 #endif
+#endif
 #ifndef NANARG
 #define NANARG
 #endif
