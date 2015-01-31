--- texk/xdvik/encodings.h.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/encodings.h	2015-01-31 21:02:18.000000000 +0900
@@ -53,5 +53,7 @@
 extern Boolean is_hyphenchar(uint32_t unicode);
 extern Boolean is_ideograph(uint32_t unicode);
 
+extern uint32_t jis2unicode(wide_ubyte jis);
+
 #endif /* ENCODINGS_H_ */
 
