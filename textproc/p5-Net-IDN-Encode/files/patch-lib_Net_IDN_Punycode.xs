--- lib/Net/IDN/Punycode.xs.orig	2018-10-06 00:28:07 UTC
+++ lib/Net/IDN/Punycode.xs
@@ -24,6 +24,10 @@
 #define utf8_to_uvchr_buf(in_p,in_e,u8) utf8_to_uvchr(in_p,u8);
 #endif
 
+#ifndef uvchr_to_utf8_flags
+#define uvchr_to_utf8_flags(d, uv, flags) uvuni_to_utf8_flags(d, uv, flags);
+#endif
+
 static char enc_digit[BASE] = {
   'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
   'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
@@ -253,7 +257,7 @@ decode_punycode(input)
 		  if(skip_p < re_p)				/* move succeeding chars */
 		    Move(skip_p, skip_p + u8, re_p - skip_p, char);
 		  re_p += u8;
-		  uvuni_to_utf8_flags((U8*)skip_p, n, UNICODE_ALLOW_ANY);
+		  uvchr_to_utf8_flags((U8*)skip_p, n, UNICODE_ALLOW_ANY);
 		}
 
 		if(!first) SvUTF8_on(RETVAL);			/* UTF-8 chars have been inserted */
