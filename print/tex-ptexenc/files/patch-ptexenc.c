--- ptexenc.c.orig	2023-01-01 05:42:55 UTC
+++ ptexenc.c
@@ -16,6 +16,7 @@
 #include <ptexenc/unicode-jp.h>
 
 #include <ctype.h>
+#include <fnmatch.h>
 #include <sys/stat.h>
 
 #define ENC_UNKNOWN  0
@@ -25,11 +26,47 @@
 #define ENC_UTF8     4
 #define ENC_UPTEX    5
 
-static int default_kanji_enc;
+static int default_kanji_is_uptex;
 static boolean UPTEX_enabled;
 static boolean ptex_mode = false;
 static boolean prior_file_enc = false;
 
+static struct le {
+    char *name;
+    int enc;
+    int flag;
+} letable[] = {
+    {"*.UTF-8",     ENC_UTF8, FNM_NOESCAPE},
+    {"*.eucJP",     ENC_EUC, FNM_NOESCAPE | FNM_CASEFOLD},
+    {"*.EUC-JP",    ENC_EUC, FNM_NOESCAPE},
+    {"*.EUC",       ENC_EUC, FNM_NOESCAPE | FNM_CASEFOLD},
+    {"*.PCK",       ENC_SJIS, FNM_NOESCAPE | FNM_CASEFOLD},
+    {"*.SJIS",      ENC_SJIS, FNM_NOESCAPE | FNM_CASEFOLD},
+    {"*.ISO-2022-JP",       ENC_JIS, FNM_NOESCAPE | FNM_CASEFOLD},
+    {NULL, 0, 0}
+};
+
+static int
+default_kanji_enc(void)
+{
+    struct le *le;
+    const char *name;
+    int i;
+
+    if (default_kanji_is_uptex)
+        return (ENC_UPTEX);
+    name = getenv("LANG");
+    if (name == NULL)
+        return (ENC_UTF8);
+
+    for (i = 0; letable[i].name != NULL; i++) {
+        if (fnmatch(letable[i].name, name, letable[i].flag) !=
+            FNM_NOMATCH)
+                return (letable[i].enc);
+    }
+    return (ENC_UTF8);
+}
+
 #define ESC '\033'
 
 #ifndef NOFILE
@@ -65,7 +102,7 @@ static int string_to_enc(const_string str)
 static int string_to_enc(const_string str)
 {
     if (str == NULL)                    return ENC_UNKNOWN;
-    if (strcasecmp(str, "default")== 0) return default_kanji_enc;
+    if (strcasecmp(str, "default")== 0) return default_kanji_enc();
     if (strcasecmp(str, "jis")    == 0) return ENC_JIS;
     if (strcasecmp(str, "euc")    == 0) return ENC_EUC;
     if (strcasecmp(str, "sjis")   == 0) return ENC_SJIS;
@@ -95,7 +132,7 @@ static int get_default_enc(void)
     } else if (enc != ENC_UNKNOWN) {
         return enc;
     }
-    return default_kanji_enc;
+    return default_kanji_enc();
 }
 
 static void set_file_enc(int enc)
@@ -165,14 +202,14 @@ void enable_UPTEX (boolean enable)
 {
     UPTEX_enabled = enable;
     if (enable) {
-        default_kanji_enc = ENC_UPTEX;
+        default_kanji_is_uptex = 1;
         internal_enc = ENC_UPTEX;
     } else {
 #ifdef WIN32
         default_kanji_enc = ENC_UTF8;
         internal_enc = ENC_SJIS;
 #else
-        default_kanji_enc = ENC_UTF8;
+        default_kanji_is_uptex = 0;
         internal_enc = ENC_EUC;
 #endif
     }
