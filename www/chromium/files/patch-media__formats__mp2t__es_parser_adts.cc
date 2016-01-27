--- media/formats/mp2t/es_parser_adts.cc.orig	2016-01-21 18:00:32.996621604 +0100
+++ media/formats/mp2t/es_parser_adts.cc	2016-01-21 18:00:53.692621141 +0100
@@ -61,11 +61,11 @@
   const uint8* es;
   es_queue_->Peek(&es, &es_size);
 
-  int max_offset = es_size - kADTSHeaderMinSize;
-  if (max_offset <= 0)
+  int _max_offset = es_size - kADTSHeaderMinSize;
+  if (_max_offset <= 0)
     return false;
 
-  for (int offset = 0; offset < max_offset; offset++) {
+  for (int offset = 0; offset < _max_offset; offset++) {
     const uint8* cur_buf = &es[offset];
     if (!isAdtsSyncWord(cur_buf))
       continue;
@@ -103,7 +103,7 @@
     return true;
   }
 
-  es_queue_->Pop(max_offset);
+  es_queue_->Pop(_max_offset);
   return false;
 }
 
