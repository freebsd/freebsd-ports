--- src/base/threading/thread_restrictions.h.orig	2026-06-01 00:00:00 UTC
+++ src/base/threading/thread_restrictions.h
@@ -749,8 +749,11 @@
       const ScopedAllowBaseSyncPrimitives&) = delete;
 
  private:
+#if !defined(BRAVE_REDIRECT_CC_BUILD)
+  // Forward declared in brave/chromium_src/base/threading/thread_restrictions.h
   friend class ::BraveBrowsingDataRemoverDelegate;
   friend class brave::ProcessLauncher;
+#endif
   // This can only be instantiated by friends. Use
   // ScopedAllowBaseSyncPrimitivesForTesting in unit tests to avoid the friend
   // requirement.
