--- encoding.l.orig	Wed Jul 19 11:39:18 2006
+++ encoding.l	Wed Jul 19 11:39:22 2006
@@ -8,7 +8,7 @@
 #include "ttmkfdir.h"    
 #include "encoding.h"    
 
-#define DEFAULT_SIZE 0x100 /* 8 bit encoding */
+#define DEFAULT_SIZE 0xFFFF /* 8 bit encoding */
 #define YY_DECL int yylex (char *current_file, Encodings_t &dest)
 
 static unsigned int line_number = 1;
@@ -43,6 +43,7 @@
 STARTENCODING{WHITESPACES}{STRING} {
     cur_enc = new Encoding;
     cur_enc->names.push_back (strip_first (yytext));
+    cur_enc->size = DEFAULT_SIZE;
     BEGIN(INSIDE_ENC_BLOCK);
 }
 
@@ -97,6 +98,7 @@
 <INSIDE_MAP_BLOCK>UNDEFINE{WHITESPACES}{NUMBER}({WHITESPACES}{NUMBER})? {
     char *startptr = strip_first (yytext);
     char *endptr;
+    long msize = cur_map->size();
 
     int i1 = std::strtol (startptr, &endptr, 0);
     startptr = endptr;
@@ -108,13 +110,14 @@
     }
     
     /* now mark all the unassigned codes */
-    for (long i = i1; i <= i2; i++) {
+    for (long i = i1; i <= i2 && i < msize; i++) {
 	(*cur_map)[i] = -1;
     }
 }
 
 <INSIDE_MAP_BLOCK>{NUMBER}({WHITESPACES}{NUMBER}){0,2} {
-    int numbers[3], i = 0, start_range, end_range, target, res;
+    int numbers[3], target, res;
+    unsigned int i = 0, start_range, end_range;
     char *startptr;
     char *endptr = yytext;
 
