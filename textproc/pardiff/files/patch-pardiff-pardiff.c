--- pardiff/pardiff.c.orig	Sat Jul  7 07:54:35 2001
+++ pardiff/pardiff.c	Sun Jul  8 15:30:10 2001
@@ -23,7 +23,7 @@
 
 /* include files to determine the width of the output terminal */
 #include <fcntl.h>
-#include <termio.h>
+#include <sys/ttycom.h>
 
 
 #else
@@ -314,7 +314,7 @@
          * Preprocess lines to get a consistent EOL
          */
         if (convertCrlf) {
-            line_len = strnlen(nextline, PARDIFF_LINE_BUF_SIZE); 
+            line_len = strlen(nextline);
             if (line_len > 2 && nextline[line_len - 2] == 0xd) {
                 nextline[line_len - 2] = '\n';
                 nextline[line_len - 1] = '\0';
