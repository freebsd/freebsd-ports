--- media/formats/common/offset_byte_queue.cc.orig	2016-01-21 18:02:48.165612307 +0100
+++ media/formats/common/offset_byte_queue.cc	2016-01-21 18:03:02.909611412 +0100
@@ -46,13 +46,13 @@
   *size = tail() - offset;
 }
 
-bool OffsetByteQueue::Trim(int64 max_offset) {
-  if (max_offset < head_) return true;
-  if (max_offset > tail()) {
+bool OffsetByteQueue::Trim(int64 _max_offset) {
+  if (_max_offset < head_) return true;
+  if (_max_offset > tail()) {
     Pop(size_);
     return false;
   }
-  Pop(max_offset - head_);
+  Pop(_max_offset - head_);
   return true;
 }
 
