--- media/formats/common/offset_byte_queue.cc.orig	2016-03-04 23:04:36.711520923 +0100
+++ media/formats/common/offset_byte_queue.cc	2016-03-04 23:04:56.247519728 +0100
@@ -46,13 +46,13 @@
   *size = tail() - offset;
 }
 
-bool OffsetByteQueue::Trim(int64_t max_offset) {
-  if (max_offset < head_) return true;
-  if (max_offset > tail()) {
+bool OffsetByteQueue::Trim(int64_t _max_offset) {
+  if (_max_offset < head_) return true;
+  if (_max_offset > tail()) {
     Pop(size_);
     return false;
   }
-  Pop(max_offset - head_);
+  Pop(_max_offset - head_);
   return true;
 }
 
