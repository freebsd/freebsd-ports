--- media/formats/mp2t/es_parser_adts.cc.orig	2017-04-19 19:06:35 UTC
+++ media/formats/mp2t/es_parser_adts.cc
@@ -60,11 +60,11 @@ bool EsParserAdts::LookForAdtsFrame(Adts
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
@@ -104,7 +104,7 @@ bool EsParserAdts::LookForAdtsFrame(Adts
     return true;
   }
 
-  es_queue_->Pop(max_offset);
+  es_queue_->Pop(_max_offset);
   return false;
 }
 
