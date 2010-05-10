--- JavaScriptCore/runtime/JSValue.h.orig	2010-02-05 17:26:52.000000000 +0100
+++ JavaScriptCore/runtime/JSValue.h	2010-03-25 21:43:11.000000000 +0100
@@ -491,7 +491,11 @@ namespace JSC {
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64)
+        u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
