--- ./src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSValueInlineMethods.h.orig	2011-12-08 06:06:02.000000000 +0100
+++ ./src/3rdparty/webkit/Source/JavaScriptCore/runtime/JSValueInlineMethods.h	2012-01-08 17:18:52.511348683 +0100
@@ -227,7 +227,11 @@
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
@@ -239,7 +243,11 @@
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
