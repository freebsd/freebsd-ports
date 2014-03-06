--- Source/JavaScriptCore/runtime/JSCell.h.orig	2014-03-06 00:47:38.620499335 +0000
+++ Source/JavaScriptCore/runtime/JSCell.h	2014-03-06 00:48:03.250498156 +0000
@@ -49,6 +49,9 @@
     IncludeDontEnumProperties
 };
 
+template<typename T> void* allocateCell(Heap&);
+template<typename T> void* allocateCell(Heap&, size_t);
+
 class JSCell {
     friend class JSValue;
     friend class MarkedBlock;
