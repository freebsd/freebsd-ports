--- src/galeon-main.c.orig	Thu Sep 11 01:11:30 2003
+++ src/galeon-main.c	Thu Sep 11 01:12:31 2003
@@ -130,7 +130,7 @@
 #ifdef ENABLE_NLS
 	/* Initialize the i18n stuff */
 	setlocale(LC_ALL, "");
-	bindtextdomain(GETTEXT_PACKAGE, DATADIR "/locale");
+	bindtextdomain(GETTEXT_PACKAGE, GNOMELOCALEDIR);
 	textdomain(GETTEXT_PACKAGE);
 #endif
 	/* set the application name manually until gnome handles the
