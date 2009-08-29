--- kkconsui/src/conscommon.cc.orig	2009-08-29 18:34:40.000000000 -0400
+++ kkconsui/src/conscommon.cc	2009-08-29 18:36:31.000000000 -0400
@@ -274,9 +274,9 @@ string makebidi(const string &buf, int l
 	// really sick thing
 
     base = FRIBIDI_TYPE_N;
-    fribidi_iso8859_8_to_unicode(cbuf, buf.size(), us);
+    fribidi_charset_to_unicode(FRIBIDI_CHAR_SET_ISO8859_8,cbuf, buf.size(), us);
     fribidi_log2vis(us, buf.size(), &base, out_us, 0, 0, 0);
-    fribidi_unicode_to_iso8859_8(out_us, buf.size(), outstring);
+    fribidi_unicode_to_charset(FRIBIDI_CHAR_SET_ISO8859_8, out_us, buf.size(), outstring);
 
     r = outstring;
 
