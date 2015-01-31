--- texk/xdvik/gui/help-window.c.orig	2014-09-02 18:41:34.000000000 +0900
+++ texk/xdvik/gui/help-window.c	2015-01-31 21:02:18.000000000 +0900
@@ -314,6 +314,9 @@
 #if FREETYPE
 	"- freetype2 (direct rendering of PS fonts) enabled\n",
 #endif
+#ifdef PTEX
+	"- FreeType2 (Kanji font rendering) enabled\n",
+#endif /* PTEX */
 #if HAVE_ICONV_H
 	"- Iconv support compiled in\n",
 #if USE_LANGINFO
