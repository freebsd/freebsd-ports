--- antiword.h.orig	Sat Oct 27 08:35:52 2001
+++ antiword.h	Sat Oct 27 08:36:13 2001
@@ -143,7 +143,7 @@
 #define ANTIWORD_DIR		"antiword"
 #define FONTNAMES_FILE		"fontname.txt"
 #else
-#define GLOBAL_ANTIWORD_DIR	"/opt/antiword/share"
+#define GLOBAL_ANTIWORD_DIR	"%%PREFIX%%/share/antiword"
 #define ANTIWORD_DIR		".antiword"
 #define FONTNAMES_FILE		"fontnames"
 #endif /* __dos */
