--- ptexenc.c.orig	2012-03-05 17:50:28.000000000 +0900
+++ ptexenc.c	2013-03-06 06:34:13.000000000 +0900
@@ -15,6 +15,7 @@
 #include <ptexenc/unicode-jp.h>
 
 #include <ctype.h>
+#include <fnmatch.h>
 
 #define ENC_UNKNOWN  0
 #define ENC_JIS      1
@@ -23,7 +24,39 @@
 #define ENC_UTF8     4
 #define ENC_UPTEX    5
 
-static int default_kanji_enc = ENC_UTF8;
+struct le {
+	char *name;
+	int enc;
+	int flag;
+} letable[] = {
+	{"*.UTF-8",	ENC_UTF8, FNM_NOESCAPE},
+	{"*.eucJP",	ENC_EUC, FNM_NOESCAPE | FNM_CASEFOLD},
+	{"*.EUC-JP",	ENC_EUC, FNM_NOESCAPE},
+	{"*.EUC",	ENC_EUC, FNM_NOESCAPE | FNM_CASEFOLD},
+	{"*.PCK",	ENC_SJIS, FNM_NOESCAPE | FNM_CASEFOLD},
+	{"*.SJIS",	ENC_SJIS, FNM_NOESCAPE | FNM_CASEFOLD},
+	{"*.ISO-2022-JP",	ENC_JIS, FNM_NOESCAPE | FNM_CASEFOLD},
+	{NULL, 0, 0}
+};
+
+static int default_kanji_is_uptex;
+static int
+default_kanji_enc()
+{
+	struct le *le;
+	const char *name;
+	int i;
+
+	if (default_kanji_is_uptex)
+		return (ENC_UPTEX);
+	name = getenv("LANG");
+	for (i = 0; letable[i].name != NULL; i++) {
+		if (fnmatch(letable[i].name, name, letable[i].flag) !=
+		    FNM_NOMATCH)
+		return (letable[i].enc);
+	}
+	return (ENC_UTF8);
+}
 static boolean UPTEX_enabled;
 static boolean prior_file_enc = false;
 
@@ -64,7 +97,7 @@
 static int string_to_enc(const_string str)
 {
     if (str == NULL)                    return ENC_UNKNOWN;
-    if (strcasecmp(str, "default")== 0) return default_kanji_enc;
+    if (strcasecmp(str, "default")== 0) return default_kanji_enc();
     if (strcasecmp(str, "jis")    == 0) return ENC_JIS;
     if (strcasecmp(str, "euc")    == 0) return ENC_EUC;
     if (strcasecmp(str, "sjis")   == 0) return ENC_SJIS;
@@ -92,7 +125,7 @@
     } else if (enc != ENC_UNKNOWN) {
         return enc;
     }
-    return default_kanji_enc;
+    return default_kanji_enc();
 }
 
 static void set_file_enc(int enc)
@@ -150,9 +183,9 @@
 {
     UPTEX_enabled = enable;
     if (enable)
-        default_kanji_enc = ENC_UPTEX;
+	default_kanji_is_uptex = 1;
     else {
-        default_kanji_enc = ENC_UTF8;
+	default_kanji_is_uptex = 0;
         if (internal_enc == ENC_UPTEX)
             internal_enc = ENC_EUC;
     }
