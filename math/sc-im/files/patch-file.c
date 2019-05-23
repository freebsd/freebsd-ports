--- file.c.orig	2019-05-11 16:23:57 UTC
+++ file.c
@@ -189,21 +189,23 @@ int modcheck() {
 
 int savefile() {
     int force_rewrite = 0;
+    int shall_quit = 0;
     char name[BUFFERSIZE];
     #ifndef NO_WORDEXP
     size_t len;
     wordexp_t p;
     #endif
 
-    if (! curfile[0] && wcslen(inputline) < 3) { // casos ":w" ":w!" ":x" ":x!"
+    if (! curfile[0] && wcslen(inputline) < 3) { // casos ":w" ":w!" ":wq" ":x" ":x!"
         sc_error("There is no filename");
         return -1;
     }
 
     if (inputline[1] == L'!') force_rewrite = 1;
+    if (inputline[1] == L'q') shall_quit = 1;
 
     wcstombs(name, inputline, BUFFERSIZE);
-    del_range_chars(name, 0, 1 + force_rewrite);
+    del_range_chars(name, 0, 1 + force_rewrite + shall_quit);
 
     #ifndef NO_WORDEXP
     wordexp(name, &p, 0);
@@ -221,7 +223,7 @@ int savefile() {
     #endif
 
     if (! force_rewrite && file_exists(name)) {
-        sc_error("File already exists. Use \"!\" to force rewrite.");
+        sc_error("File already exists. Use \"w!\" to force rewrite.");
         return -1;
     }
 
@@ -235,7 +237,7 @@ int savefile() {
     // if it exists and no '!' is set, return.
     if (!strlen(curfile) && backup_exists(name)) {
         if (!force_rewrite) {
-            sc_error("Backup file of %s exists. Use \"!\" to force the write process.", name);
+            sc_error("Backup file of %s exists. Use \"w!\" to force the write process.", name);
             return -1;
         } else remove_backup(name);
     }
