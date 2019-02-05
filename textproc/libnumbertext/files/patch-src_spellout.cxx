--- src/spellout.cxx.orig	2019-02-05 01:41:33 UTC
+++ src/spellout.cxx
@@ -10,7 +10,7 @@
 
 #define LANG "LANG"
 #define PATH "NUMBERTEXTPATH"
-#define DEFPATH "/usr/share/libnumbertext/"
+#define DEFPATH DATADIR "/libnumbertext/"
 #define DEFPATH2 "data/"
 
 enum State { base, loaded, flag_lang, flag_prefix};
