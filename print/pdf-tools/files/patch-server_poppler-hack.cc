--- server/poppler-hack.cc.orig	2018-12-09 09:39:37 UTC
+++ server/poppler-hack.cc
@@ -62,7 +62,7 @@ GType poppler_annot_markup_get_type (void) G_GNUC_CONS
       return NULL;
 
     if (s->hasUnicodeMarker()) {
-      result = g_convert (s->getCString () + 2,
+      result = g_convert (s->c_str () + 2,
                           s->getLength () - 2,
                           "UTF-8", "UTF-16BE", NULL, NULL, NULL);
     } else {
