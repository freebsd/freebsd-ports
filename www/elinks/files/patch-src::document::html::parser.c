--- src/document/html/parser.c.orig	Sat Sep  6 02:09:37 2003
+++ src/document/html/parser.c	Sat Sep  6 02:10:14 2003
@@ -2330,8 +2330,8 @@
 	parse_frame_widths(d, y, HTML_FRAME_CHAR_HEIGHT, &fp.yw, &fp.y);
 	fp.parent = html_top.frameset;
 	if (fp.x && fp.y) html_top.frameset = special_f(ff, SP_FRAMESET, &fp);
-	mem_free(fp.xw);
-	mem_free(fp.yw);
+	if (fp.x) mem_free(fp.xw);
+	if (fp.y) mem_free(fp.yw);
 
 free_cd:
 	mem_free(c);
