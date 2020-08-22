--- src/char-coding.c.orig	2020-08-22 13:49:25 UTC
+++ src/char-coding.c
@@ -340,14 +340,31 @@ void char_coding(char **inbuf, size_t * inbytesleft, c
 		// Fallback method: copy all printable chars from *inbuf to *outbuf.
 		size_t i;
 		size_t pos = 0;
-
+#ifdef __FreeBSD__
+		int to_utf = user_charset_id < iconv_codes_count() &&
+		    !strncmp(iconv_codes[user_charset_id], "UTF", sizeof "UTF" - 1);
+#endif
 		for (i = 0; i < nsrc; i++) {
 			switch ((uint8_t) * (psrc + i)) {
 				//case 0x20 ... 0x7E:
 				//case 0xA0 ... 0xFF:
 				// printable chars ISO-6937-2
 				// Figure A.1: Character code table 00 - Latin alphabet
+#ifdef __FreeBSD__
+			case 0x80 ... 0xFF:
+				// the iconv used on FreeBSD doesn't know about the
+				// default DVB charset ISO-6397-2 so we'll end up here
+				// for 8-bit chars in channel names that are (usually
+				// wrongly) specified as the default charset - and if
+				// we are converting to UTF those will create invalid
+				// encodings.
+				if (to_utf)
+					continue;
+				// FALLTHRU
+			case 0x01 ... 0x7F:
+#else
 			case 0x01 ... 0xFF:	// 20121202: don't touch anything; leave it as it is.
+#endif
 				*(pdest + pos++) = *(psrc + i);
 			default:;
 			}
