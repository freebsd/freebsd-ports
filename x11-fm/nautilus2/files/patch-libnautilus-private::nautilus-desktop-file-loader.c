
$FreeBSD$

--- libnautilus-private/nautilus-desktop-file-loader.c.orig	Wed Sep 26 19:37:15 2001
+++ libnautilus-private/nautilus-desktop-file-loader.c	Fri Mar 29 14:58:54 2002
@@ -39,7 +39,9 @@
 #include <ctype.h>
 #include <locale.h>
 #include <iconv.h>
+#if (defined __FreeBSD__) && (__FreeBSD_version > 450001)
 #include <langinfo.h>
+#endif
 
 typedef struct NautilusDesktopFileSection NautilusDesktopFileSection;
 typedef struct NautilusDesktopFileAddition NautilusDesktopFileAddition;
@@ -117,6 +119,44 @@
 									   const char                      *value);
 static void                         addition_free                         (NautilusDesktopFileAddition     *addition);
 
+#if (defined __FreeBSD__) && (__FreeBSD_version < 450001)
+/* Quick and dirty implementation of nl_langinfo(CODESET) */
+static char *
+nl_langinfo(void) {
+	char *ret, *s, *cs;
+	static char *cset = NULL;
+
+	ret = "";
+	if ((s = setlocale(LC_CTYPE, NULL)) != NULL) {
+		if ((cs = strchr(s, '.')) != NULL) {
+			ret = cs + 1;
+			if (strncmp(ret, "ISO_", 4) == 0) {
+				int slen = strlen(ret);
+
+				if ((cset = reallocf(cset, slen)) != NULL) {
+					strcpy(cset, "ISO");
+					strcat(cset, ret + 4);
+					ret = cset;
+				} else
+					ret = "";
+			} else if (strcmp(ret, "EUC") == 0) {
+				if (strncmp(s, "ja_JP", 5) == 0)
+					ret = "eucJP";
+				else if (strncmp(s, "ko_KR", 5) == 0)
+					ret = "eucKR";
+				else if (strncmp(s, "zh_CN", 5) == 0)
+					ret = "eucCN";
+			} else if (strcmp(ret, "ASCII") == 0)
+				ret = "US-ASCII";
+		} else if (strcmp(s, "C") == 0 ||
+			   strcmp(s, "POSIX") == 0
+			   || strstr(s, "ASCII") != NULL)
+			ret = "US-ASCII";
+	}
+	return ret;
+}
+#define nl_langinfo(x) nl_langinfo()
+#endif
 
 static NautilusDesktopFile*
 nautilus_desktop_file_new (void)
