--- ./chrome/browser/memory_purger.cc.orig	2010-12-16 02:11:58.000000000 +0100
+++ ./chrome/browser/memory_purger.cc	2010-12-20 20:15:08.000000000 +0100
@@ -135,7 +135,7 @@
   // * Purge AppCache memory.  Not yet implemented sufficiently.
   // * Browser-side DatabaseTracker.  Not implemented sufficiently.
 
-#if (defined(OS_WIN) || defined(OS_LINUX)) && defined(USE_TCMALLOC)
+#if (defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FREEBSD)) && defined(USE_TCMALLOC)
   // Tell tcmalloc to release any free pages it's still holding.
   //
   // TODO(pkasting): A lot of the above calls kick off actions on other threads.
