--- lily/midi-item.cc.orig	2020-04-29 11:39:18 UTC
+++ lily/midi-item.cc
@@ -319,7 +319,7 @@ Midi_text::Midi_text (Audio_text *a)
 string
 Midi_text::to_string () const
 {
-  uint8_t text_code[] = {0xff, audio_->type_};
+  uint8_t text_code[] = {0xff, uint8_t (audio_->type_)};
   string str ((char *) text_code, sizeof (text_code));
   str += int2midi_varint_string (int (audio_->text_string_.length ()));
   str += audio_->text_string_;
