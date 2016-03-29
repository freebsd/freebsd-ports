--- media/formats/mp2t/es_parser_adts.cc.orig	2016-03-04 23:09:52.322624868 +0100
+++ media/formats/mp2t/es_parser_adts.cc	2016-03-04 23:10:00.912499378 +0100
@@ -62,11 +62,11 @@
   const uint8_t* es;
   es_queue_->Peek(&es, &es_size);
 
-  int max_offset = es_size - kADTSHeaderMinSize;
-  if (max_offset <= 0)
+  int _max_offset = es_size - kADTSHeaderMinSize;
+  if (_max_offset <= 0)
     return false;
 
-  for (int offset = 0; offset < max_offset; offset++) {
+  for (int offset = 0; offset < _max_offset; offset++) {
     const uint8_t* cur_buf = &es[offset];
     if (!isAdtsSyncWord(cur_buf))
       continue;
@@ -104,7 +104,7 @@
     return true;
   }
 
-  es_queue_->Pop(max_offset);
+  es_queue_->Pop(_max_offset);
   return false;
 }
 
