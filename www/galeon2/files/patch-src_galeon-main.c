--- src/galeon-main.c.orig	Sun Aug 17 14:59:02 2003
+++ src/galeon-main.c	Sun Aug 17 15:00:25 2003
@@ -126,7 +126,7 @@
 	
 #ifdef ENABLE_NLS
 	/* Initialize the i18n stuff */
-	bindtextdomain(GETTEXT_PACKAGE, DATADIR "/locale");
+	bindtextdomain(GETTEXT_PACKAGE, GNOMELOCALEDIR);
 	bind_textdomain_codeset(GETTEXT_PACKAGE, "UTF-8");
 	textdomain(GETTEXT_PACKAGE);
 #endif
