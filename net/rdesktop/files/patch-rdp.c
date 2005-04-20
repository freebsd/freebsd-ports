--- rdp.c.orig	2004-10-07 17:00:28.000000000 +0400
+++ rdp.c	2004-12-15 12:12:23.022107839 +0300
@@ -19,10 +19,14 @@
 */
 
 #include <time.h>
+#include <errno.h>
+#include <iconv.h>
+#include <unistd.h>
 #include "rdesktop.h"
 
 extern uint16 g_mcs_userid;
-extern char g_username[16];
+extern char g_username[64];
+extern char g_codepage[16];
 extern BOOL g_bitmap_compression;
 extern BOOL g_orders;
 extern BOOL g_encryption;
@@ -140,17 +144,51 @@
 void
 rdp_out_unistr(STREAM s, char *string, int len)
 {
-	int i = 0, j = 0;
+	static iconv_t iconv_h = (iconv_t)-1;
+	size_t ibl = strlen(string), obl = len + 2;
+	char   *pin = string, *pout;
+#ifdef	WORDS_BIGENDIAN
+	char ss[4096];	// FIXME: global MAX_BUF_SIZE macro need
+
+	pout = ss;
+#else
+	pout = s->p;
+#endif
 
-	len += 2;
+	memset(pout, 0, len + 4);
 
-	while (i < len)
+	if (iconv_h == (iconv_t)-1)
 	{
-		s->p[i++] = string[j++];
-		s->p[i++] = 0;
+		size_t i = 1, o = 4;
+		if ((iconv_h = iconv_open(WINDOWS_CODEPAGE, g_codepage)) == (iconv_t)-1)
+		{
+			printf("rdp_out_unistr: iconv_open[%s -> %s] fail %d\n",
+				g_codepage, WINDOWS_CODEPAGE, (int)iconv_h);
+			return;
+		}
+		if (iconv(iconv_h, &pin, &i, &pout, &o) == (size_t)-1)
+		{
+			iconv_close(iconv_h);
+			iconv_h = (iconv_t)-1;
+			printf("rdp_out_unistr: iconv(1) fail, errno %d\n", errno);
+			return;
+		}
+		pin = string; pout = s->p;
 	}
 
-	s->p += len;
+	if (iconv(iconv_h, &pin, &ibl, &pout, &obl) == (size_t)-1)
+	{
+		iconv_close(iconv_h);
+		iconv_h = (iconv_t)-1;
+		printf("rdp_out_unistr: iconv(2) fail, errno %d\n", errno);
+		return;
+	}
+
+#ifdef	WORDS_BIGENDIAN
+	swab(ss, s->p, len + 4);
+#endif
+
+	s->p += len + 2;
 }
 
 /* Input a string in Unicode
@@ -160,15 +198,36 @@
 int
 rdp_in_unistr(STREAM s, char *string, int uni_len)
 {
-	int i = 0;
+	static iconv_t iconv_h = (iconv_t)-1;
+	size_t ibl = uni_len, obl = uni_len;
+	char *pin, *pout = string;
+#ifdef	WORDS_BIGENDIAN
+	char ss[4096];	// FIXME: global MAX_BUF_SIZE macro need
+
+	swab(s->p, ss, uni_len);
+	pin = ss;
+#else
+	pin = s->p;
+#endif
 
-	while (i < uni_len / 2)
+	if (iconv_h == (iconv_t)-1)
 	{
-		in_uint8a(s, &string[i++], 1);
-		in_uint8s(s, 1);
+		if ((iconv_h = iconv_open(g_codepage, WINDOWS_CODEPAGE)) == (iconv_t)-1)
+		{
+			printf("rdp_in_unistr: iconv_open[%s -> %s] fail %d\n",
+				WINDOWS_CODEPAGE, g_codepage, (int)iconv_h);
+			return 0;
+		}
 	}
 
-	return i - 1;
+	if (iconv(iconv_h, &pin, &ibl, &pout, &obl) == (size_t)-1)
+	{
+		iconv_close(iconv_h);
+		iconv_h = (iconv_t)-1;
+		printf("rdp_in_unistr: iconv fail, errno %d\n", errno);
+		return 0;
+	}
+	return pout - string;
 }
 
 
