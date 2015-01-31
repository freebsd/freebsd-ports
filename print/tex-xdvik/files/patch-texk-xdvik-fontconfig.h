--- /dev/null	2015-01-31 21:35:05.000000000 +0900
+++ texk/xdvik/fontconfig.h	2015-01-31 21:02:18.000000000 +0900
@@ -0,0 +1,11 @@
+
+#ifndef FONTCONFIG_H_
+#define FONTCONFIG_H_
+
+#ifdef	PTEX
+
+char *get_ptex_font_pathname(char *name);
+
+#endif /* PTEX */
+
+#endif /* FONTCONFIG_H_ */
