--- src/hooks/utf8conv.h	Thu Jan  1 08:00:00 1970
+++ src/hooks/utf8conv.h	Tue Nov 19 15:19:44 2002
@@ -0,0 +1,56 @@
+/*-------------------------------------------------------*/
+/* utf8conv.h     ( Utf8 Converter )                     */
+/*-------------------------------------------------------*/
+/* target : Converting Utf8 from/to string/char          */
+/* modifier : clsung@dragon2.net                         */
+/* create : unknown                                      */
+/* update : 02/11/19                                     */
+/*-------------------------------------------------------*/
+#ifndef _UTF8CONV_
+#define _UTF8CONV_
+
+#ifndef HAVE_ICONV_H
+#define HAVE_ICONV_H
+#endif
+
+#ifdef HAVE_ICONV_H
+#include <iconv.h>
+#endif
+#include <string>
+#define DEFAULT_CHARSET "ISO-8859-1"
+/* charset name cache buffer */
+static char loc_charset[32];
+/* 
+** Name:    safe_iconv
+** Purpose: 'Fault-tolerant' version if iconv. Replaces invalid seq with '?'
+** Input:   see iconv manpage
+*/
+int safe_iconv( iconv_t handle, const char **inbuf, size_t *inbytesleft,
+	     char **outbuf, size_t *outbytesleft);
+
+/*
+** Name:    guess_current_locale_charset
+** Purpose: Try to guess default charset for the current locale
+** Output:  charset name
+** FIXME:   is there more right method for guessing charset
+	    than scanning $LANG ?
+*/
+const char* guess_current_locale_charset();
+
+/*
+** Name:    Str2Utf8
+** Purpose: convert a string in UTF-8 format
+** Input:   inbuf     - the string to convert
+** Output:  a new string in UTF-8 format
+*/
+char *StrToUtf8( const char *inbuf );
+std::string StrToUtf8( const std::string &instr );
+/*
+** Name:    Utf8ToStr
+** Purpose: revert UTF-8 string conversion
+** Input:   inbuf  - the string to decode
+** Output:  a new decoded string
+*/
+char *Utf8ToStr( const char *inbuf );
+std::string Utf8ToStr( const std::string &instr );
+#endif
