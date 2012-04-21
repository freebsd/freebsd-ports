--- i18n.h.orig
+++ i18n.h
@@ -9,8 +9,10 @@
 #ifndef _I18N__H
 #define _I18N__H
 
+#if (APIVERSNUM < 10507)
 #include <vdr/i18n.h>
 
 extern const tI18nPhrase Phrases[];
+#endif
 
 #endif //_I18N__H
