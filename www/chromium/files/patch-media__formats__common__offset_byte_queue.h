--- media/formats/common/offset_byte_queue.h.orig	2016-01-21 17:56:56.371637446 +0100
+++ media/formats/common/offset_byte_queue.h	2016-01-21 17:57:23.779644008 +0100
@@ -42,7 +42,7 @@
   // including the case where |max_offset| is less than the current head.
   // Returns false if |max_offset| > tail() (although all bytes currently
   // buffered are still cleared).
-  bool Trim(int64 max_offset);
+  bool Trim(int64 _max_offset);
 
   // The head and tail positions, in terms of the file's absolute offsets.
   // tail() is an exclusive bound.
