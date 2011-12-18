--- xbmc/pvrclients/MediaPortal/CriticalSection.cpp.orig
+++ xbmc/pvrclients/MediaPortal/CriticalSection.cpp
@@ -18,6 +18,10 @@
 
 #include "CriticalSection.h"
 
+#ifdef __FreeBSD__
+#define	PTHREAD_MUTEX_RECURSIVE_NP PTHREAD_MUTEX_RECURSIVE
+#endif
+
 CCriticalSection::CCriticalSection(void)
 {
 }
