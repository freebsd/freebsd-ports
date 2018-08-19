--- file.c.orig	2017-12-13 17:48:59 UTC
+++ file.c
@@ -202,7 +202,12 @@ int savefile() {
     del_range_chars(name, 0, 1 + force_rewrite);
     wordexp(name, &p, 0);
 
-    if (! force_rewrite && p.we_wordv[0] && file_exists(p.we_wordv[0])) {
+    if (wcslen(inputline) > 2 && (!p.we_wordv || !p.we_wordv[0])) {
+       sc_error("Trailing space(s)");
+       return -1;
+    }
+
+    if (! force_rewrite && p.we_wordv && p.we_wordv[0] && file_exists(p.we_wordv[0])) {
         sc_error("File already exists. Use \"!\" to force rewrite.");
         wordfree(&p);
         return -1;
