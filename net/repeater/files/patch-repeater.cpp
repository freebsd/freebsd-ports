--- repeater.cpp.orig	Wed Oct 19 03:12:05 2005
+++ repeater.cpp	Sat Sep 30 10:01:56 2006
@@ -28,6 +28,13 @@
 // Linux port (C) 2005 Jari Korhonen, jarit1.korhonen@dnainternet.net
 // ///////////////////////////////////////////////////////////////////////////
 
+#if defined(__FreeBSD__)
+#if __FreeBSD__ < 5
+#include <machine/limits.h>
+#else
+#include <sys/limits.h>
+#endif
+#endif	/* __FreeBSD__ */
 #include <sys/types.h>
 #include <sys/wait.h>
 #include <sys/stat.h>
