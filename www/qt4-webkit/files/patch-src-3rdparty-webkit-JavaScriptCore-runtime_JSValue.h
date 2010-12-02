--- src/3rdparty/webkit/JavaScriptCore/runtime/JSValue.h.orig	2010-05-22 11:09:21.423802590 +0200
+++ src/3rdparty/webkit/JavaScriptCore/runtime/JSValue.h	2010-05-22 11:31:33.896924042 +0200
@@ -491,7 +491,11 @@
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
@@ -503,7 +507,11 @@
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(const_cast<JSCell*>(ptr));
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+#endif
 #if ENABLE(JSC_ZOMBIES)
         ASSERT(!isZombie());
 #endif
