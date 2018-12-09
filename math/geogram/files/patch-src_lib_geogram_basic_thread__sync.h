--- src/lib/geogram/basic/thread_sync.h.orig	2018-12-09 17:42:18 UTC
+++ src/lib/geogram/basic/thread_sync.h
@@ -122,7 +122,7 @@ namespace GEO {
             unlock_mutex_android(&x);
         }
 
-#elif defined(GEO_OS_LINUX) || defined(GEO_COMPILER_MINGW)
+#elif defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD) || defined(GEO_COMPILER_MINGW)
 
         /** A lightweight synchronization structure. */
         typedef unsigned char spinlock;
@@ -500,7 +500,7 @@ namespace GEO {
             index_t size_;
         };
 
-#elif defined(GEO_OS_LINUX) 
+#elif defined(GEO_OS_LINUX) || defined(GEO_OS_FREEBSD)
 
         /**
          * \brief An array of light-weight synchronisation
