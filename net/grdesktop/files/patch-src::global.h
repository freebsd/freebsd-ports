--- src/global.h.old	Mon Feb  2 14:05:53 2004
+++ src/global.h	Tue Feb  3 15:07:16 2004
@@ -61,9 +61,9 @@
 
 #define MAXHOSTS 10			/* maximum hosts to store */
 #define PIXDIR DATADIR"/pixmaps/grdesktop"
-#ifndef KBPATH
+
+#undef KBPATH
 #define KBPATH "/usr/local/share/rdesktop/keymaps/"
-#endif
 
 #define GCONF_BASE "/apps/grdesktop/options"
 
