--- src/3rdparty/webkit/JavaScriptCore/runtime/JSValue.h.orig	2010-03-23 23:39:05.000000000 +0100
+++ src/3rdparty/webkit/JavaScriptCore/runtime/JSValue.h	2010-03-23 23:44:23.000000000 +0100
@@ -476,7 +476,11 @@
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
     }
 
     inline JSValue::JSValue(const JSCell* ptr)
@@ -485,7 +489,11 @@
             u.asBits.tag = CellTag;
         else
             u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(const_cast<JSCell*>(ptr));
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+#endif
     }
 
     inline JSValue::operator bool() const
