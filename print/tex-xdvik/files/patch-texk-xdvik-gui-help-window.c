--- texk/xdvik/gui/help-window.c.orig	2013-03-31 05:28:21 UTC
+++ texk/xdvik/gui/help-window.c
@@ -314,6 +314,9 @@ initialize_items(struct topic_info *info
 #if FREETYPE
 	"- freetype2 (direct rendering of PS fonts) enabled\n",
 #endif
+#ifdef PTEX
+	"- FreeType2 (Kanji font rendering) enabled\n",
+#endif /* PTEX */
 #if HAVE_ICONV_H
 	"- Iconv support compiled in\n",
 #if USE_LANGINFO
