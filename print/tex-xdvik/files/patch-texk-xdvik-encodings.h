--- texk/xdvik/encodings.h.orig	2004-11-01 23:15:22 UTC
+++ texk/xdvik/encodings.h
@@ -53,5 +53,7 @@ extern int str_iso_8859_1_to_utf8(const 
 extern Boolean is_hyphenchar(uint32_t unicode);
 extern Boolean is_ideograph(uint32_t unicode);
 
+extern uint32_t jis2unicode(wide_ubyte jis);
+
 #endif /* ENCODINGS_H_ */
 
