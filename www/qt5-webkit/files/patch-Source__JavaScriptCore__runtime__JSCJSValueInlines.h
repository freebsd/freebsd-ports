--- ./Source/JavaScriptCore/runtime/JSCJSValueInlines.h.orig	2013-10-22 01:49:45.000000000 -0700
+++ ./Source/JavaScriptCore/runtime/JSCJSValueInlines.h	2013-11-08 00:51:34.238960064 -0800
@@ -198,7 +198,11 @@
         u.asBits.tag = CellTag;
     else
         u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+    u.asBits.payload = reinterpret_cast<int64_t>(ptr);
+#else
     u.asBits.payload = reinterpret_cast<int32_t>(ptr);
+#endif
 }
 
 inline JSValue::JSValue(const JSCell* ptr)
@@ -207,7 +211,11 @@
         u.asBits.tag = CellTag;
     else
         u.asBits.tag = EmptyValueTag;
+#if defined(__sparc64__)
+    u.asBits.payload = reinterpret_cast<int64_t>(const_cast<JSCell*>(ptr));
+#else
     u.asBits.payload = reinterpret_cast<int32_t>(const_cast<JSCell*>(ptr));
+#endif
 }
 
 inline JSValue::operator bool() const
