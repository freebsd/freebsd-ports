--- src/codeconv.c.orig	Mon Feb 21 12:46:21 2005
+++ src/codeconv.c	Mon Feb 21 12:46:30 2005
@@ -1577,8 +1577,20 @@
 		Xalloca(buf, buflen, return);
 		conv_anytodisp(buf, buflen, str);
 		unmime_header(outbuf, buf);
-	} else
+	} else {
+		gchar *tmp;
 		unmime_header(outbuf, str);
+		if (outbuf && !g_utf8_validate(outbuf, -1, NULL)) {
+			tmp = conv_codeset_strdup(outbuf,
+					conv_get_locale_charset_str(),
+					CS_UTF_8);
+			if (tmp) {
+				strncpy(outbuf, tmp, outlen-1);
+				g_free(tmp);
+			}
+		}
+	}
+
 }
 
 #define MAX_LINELEN		76
