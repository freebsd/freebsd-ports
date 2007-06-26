--- io.c.orig	1998-12-23 23:29:21.000000000 +0300
+++ io.c	2007-06-26 15:35:03.000000000 +0400
@@ -35,6 +35,7 @@
 ** Last code change made 12/20/1998.
 */
 
+#include <ctype.h>
 #include "astrolog.h"
 
 
@@ -139,12 +140,12 @@
   }
 
   loop {
-    while (!feof(file) && (ch = getc(file)) < ' ')
+    while (!feof(file) && iscntrl((_char)(ch = getc(file))))
       ;
     if (feof(file))
       break;
     for (szLine[0] = ch, i = 1; i < cchSzMax && !feof(file) &&
-      (szLine[i] = getc(file)) >= ' '; i++)
+      !iscntrl((_char)(szLine[i] = getc(file))); i++)
       ;
     szLine[i] = chNull;
     argc = NParseCommandLine(szLine, argv);
@@ -675,7 +676,7 @@
       /* them. Be prepared to skip over them in old files for compatibility. */
 
       if (i == oVtx) {
-        while (getc(file) >= ' ')
+	while (!iscntrl((_char)getc(file)))
           ;
         if ((ch = getc(file)) != 'H')
           i = cuspHi;
