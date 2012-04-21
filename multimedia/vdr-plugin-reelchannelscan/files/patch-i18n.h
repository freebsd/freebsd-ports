--- i18n.h.orig
+++ i18n.h
@@ -29,6 +29,8 @@
 #include <vdr/i18n.h>
 #include <vdr/config.h>
 
+#if (APIVERSNUM < 10507)
 extern const tI18nPhrase Phrases[];
+#endif
 
 #endif //_I18N__H
