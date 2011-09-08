--- src/node_buffer.cc.orig	2011-09-08 16:40:06.000000000 +0800
+++ src/node_buffer.cc	2011-09-08 16:40:18.000000000 +0800
@@ -478,7 +478,7 @@ Handle<Value> Buffer::Utf8Write(const Ar
 
   if (written > 0 && p[written-1] == '\0' && char_written == length) {
     uint16_t last_char;
-    s->Write(&last_char, length - 1, 1, String::NO_HINTS);
+    s->Write(&last_char, length - 1, 1, String::NO_OPTIONS);
     if (last_char != 0 || written > s->Utf8Length()) {
       written--;
     }
