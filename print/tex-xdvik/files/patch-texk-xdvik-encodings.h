--- texk/xdvik/encodings.h.orig	2019-07-27 23:56:42 UTC
+++ texk/xdvik/encodings.h
@@ -52,5 +52,7 @@ extern int str_iso_8859_1_to_utf8(const char *latin1, 
 extern Boolean is_hyphenchar(uint32_t unicode);
 extern Boolean is_ideograph(uint32_t unicode);
 
+extern uint32_t jis2unicode(wide_ubyte jis);
+
 #endif /* ENCODINGS_H_ */
 
