--- builtin.cpp.orig	Mon Jan 13 04:11:10 2003
+++ builtin.cpp	Wed Jul 19 11:27:41 2006
@@ -600,7 +600,7 @@
 	0x00f8, 0x00f9, 0x00fa, 0x00fb, 0x00fc, 0x00fd, 0x00fe, 0x00ff
     };
 
-};
+}
 
 Encoding::BuiltinEncoding_t Encoding::builtin_encodings[] = {
     {256,191,32,{TT_PLATFORM_MICROSOFT,TT_MS_ID_UNICODE_CS,iso8859_1},{"iso8859-1",}},
