--- JavaScriptCore/runtime/JSValue.h.orig	2010-03-24 09:42:34.000000000 +0100
+++ JavaScriptCore/runtime/JSValue.h	2010-03-24 09:44:47.000000000 +0100
@@ -464,13 +464,21 @@
     inline JSValue::JSValue(JSCell* ptr)
     {
         u.asBits.tag = CellTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
     }
 
     inline JSValue::JSValue(const JSCell* ptr)
     {
         u.asBits.tag = CellTag;
+#if defined(__sparc64__)
+        u.asBits.payload = reinterpret_cast<int64_t>(const_cast<JSCell*>(ptr));
+#else
         u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+#endif
     }
 
     inline JSValue::operator bool() const
