--- char-coding.c.orig	2016-06-20 13:13:56 UTC
+++ char-coding.c
@@ -250,6 +250,10 @@ void char_coding(char **inbuf, size_t * 
      // Fallback method: copy all printable chars from *inbuf to *outbuf.
      size_t i;
      size_t pos = 0;
+#ifdef __FreeBSD__
+     int to_utf = user_charset_id < iconv_codes_count() &&
+         !strncmp(iconv_codes[user_charset_id], "UTF", sizeof "UTF" - 1);
+#endif
 
      for (i = 0; i < nsrc; i++) {  
          switch((uint8_t) *(psrc + i)) {
@@ -257,7 +261,21 @@ void char_coding(char **inbuf, size_t * 
                //case 0xA0 ... 0xFF:
                     // printable chars ISO-6937-2
                     // Figure A.1: Character code table 00 - Latin alphabet
+#ifdef __FreeBSD__
+               case 0x80 ... 0xFF:
+                    // the iconv used on FreeBSD doesn't know about the
+                    // default DVB charset ISO_6937-2 so we'll end up here
+                    // for 8-bit chars in channel names that are (usually
+                    // wrongly) specified as the default charset - and if
+                    // we are converting to utf those will create invalid
+                    // encodings.
+                    if (to_utf)
+                        continue;
+                    // FALLTHRU
+               case 0x01 ... 0x7F:
+#else
                case 0x01 ... 0xFF: // 20121202: don't touch anything; leave it as it is.
+#endif
                     *(pdest + pos++) = *(psrc + i);
                default:;
                }
