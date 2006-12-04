--- config.h.orig	Mon Dec  4 22:49:35 2006
+++ config.h	Mon Dec  4 22:50:40 2006
@@ -19,7 +19,7 @@
 #ifdef WIN32
 #  define CONFIG_DIR	"."
 #else
-#  define CONFIG_DIR	"/etc/fl0p"
+#  define CONFIG_DIR	"%%PREFIX%%/share/fl0p"
 #endif /* WIN32 */
 
 #define FPRINT_DB	"fl0p.fp"
