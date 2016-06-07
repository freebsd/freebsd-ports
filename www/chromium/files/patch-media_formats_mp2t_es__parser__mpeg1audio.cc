--- media/formats/mp2t/es_parser_mpeg1audio.cc.orig	2016-05-11 19:02:24 UTC
+++ media/formats/mp2t/es_parser_mpeg1audio.cc
@@ -110,11 +110,11 @@ bool EsParserMpeg1Audio::LookForMpeg1Aud
   const uint8_t* es;
   es_queue_->Peek(&es, &es_size);
 
-  int max_offset = es_size - MPEG1AudioStreamParser::kHeaderSize;
-  if (max_offset <= 0)
+  int _max_offset = es_size - MPEG1AudioStreamParser::kHeaderSize;
+  if (_max_offset <= 0)
     return false;
 
-  for (int offset = 0; offset < max_offset; offset++) {
+  for (int offset = 0; offset < _max_offset; offset++) {
     const uint8_t* cur_buf = &es[offset];
     if (cur_buf[0] != 0xff)
       continue;
@@ -155,7 +155,7 @@ bool EsParserMpeg1Audio::LookForMpeg1Aud
     return true;
   }
 
-  es_queue_->Pop(max_offset);
+  es_queue_->Pop(_max_offset);
   return false;
 }
 
