--- t1asm.c.orig	2004-01-24 02:28:23 UTC
+++ t1asm.c
@@ -280,7 +280,7 @@ static int check_line_charstring()
    the newline is put into line[]. When terminated by '{', the '{' is not put
    into line[], and the flag start_charstring is set to 1. */
 
-static void getline()
+static void get_line()
 {
   int c;
   char *p = line;
@@ -725,7 +725,7 @@ particular purpose.\n");
      without /Subrs sections and provided a patch. */
   
   while (!feof(ifp) && !ferror(ifp)) {
-    getline();
+    get_line();
     
     if (!ever_active) {
       if (strncmp(line, "currentfile eexec", 17) == 0 && isspace(line[17])) {
@@ -796,7 +796,7 @@ particular purpose.\n");
   
   /* There may be additional code. */
   while (!feof(ifp) && !ferror(ifp)) {
-    getline();
+    get_line();
     eexec_string(line);
   }
   
