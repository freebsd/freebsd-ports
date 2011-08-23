--- Source/JavaScriptCore/runtime/JSValue.h.orig	2011-01-03 22:55:02.000000000 +0000
+++ Source/JavaScriptCore/runtime/JSValue.h	2011-01-11 16:34:27.000000000 +0000
@@ -434,7 +434,11 @@ namespace JSC {
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
