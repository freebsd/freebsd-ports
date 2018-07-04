--- tdfiglet.c.orig	2018-06-27 04:00:22 UTC
+++ tdfiglet.c
@@ -40,6 +40,14 @@
 #define ENC_UNICODE	0
 #define ENC_ANSI	1
 
+#ifndef FONT_DIR
+#define FONT_DIR	"fonts"
+#endif /* FONT_DIR */
+
+#ifndef FONT_EXT
+#define FONT_EXT	"tdf"
+#endif /* FONT_EXT */
+
 typedef struct opt_s {
 	uint8_t justify;
 	uint8_t width;
@@ -117,6 +125,10 @@ main(int argc, char *argv[])
 	opt.info = false;
 	opt.encoding = ENC_UNICODE;
 
+	if (argc == 1) {
+		usage();
+	}
+
 	while((o = getopt(argc, argv, "w:j:c:e:i")) != -1) {
 		switch (o) {
 			case 'w':
@@ -194,7 +206,7 @@ main(int argc, char *argv[])
 }
 
 font_t
-*loadfont(char *fn) {
+*loadfont(char *fn_arg) {
 
 	font_t *font;
 	uint8_t *map = NULL;
@@ -202,9 +214,20 @@ font_t
 	struct stat st;
 	size_t len;
 	uint8_t *p;
+	char *fn = strdup("");
 
 	const char *magic = "\x13TheDraw FONTS file\x1a";
 
+	if (!strchr(fn_arg, '/')) {
+		if (strchr(fn_arg, '.')) {
+			sprintf(fn, "%s/%s", FONT_DIR, fn_arg);
+		} else {
+			sprintf(fn, "%s/%s.%s", FONT_DIR, fn_arg, FONT_EXT);
+		}
+	} else {
+		strcpy(fn, fn_arg);
+	}
+
 	fd = open(fn, O_RDONLY);
 
 	if (opt.info) {
@@ -299,6 +322,7 @@ font_t
 		}
 	}
 
+	free(fn);
 	return font;
 }
 
