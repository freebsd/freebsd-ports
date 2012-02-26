--- io.c.orig	2002-04-27 22:35:30.000000000 +0400
+++ io.c	2012-02-26 11:44:42.000000000 +0400
@@ -38,6 +38,7 @@
 ** Modifications from version 5.40 to 5.41 are by Alois Treindl.
 */
 
+#include <ctype.h>
 #include "astrolog.h"
 #include <string.h>
 /*
@@ -141,12 +142,12 @@
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
@@ -432,7 +433,7 @@
 /* so we have to distinguish them from new strings with two dots. VA.    */
 
   newstyle = fTrue;
-  if (pm == pmTim || pm == pmLon || pm == pmLat) {
+  if (pm == pmTim || pm == pmLon || pm == pmLat || pm == pmZon) {
     havedot = 0; dot1 = 0; dot2 = 0;
     for (i = 0; i < cch; i++) {
       chdot = sz[i];
@@ -453,6 +454,7 @@
 /* it to the old style.                                              */
 
     if (newstyle) {
+      memset(minutes, chNull, sizeof(minutes));
       for (i = dot1+1; i < cch; i++) {
         j = i - (dot1 + 1);
         if (sz[i] >= '.' && sz[i] <= '9' && sz[i] != '/')
@@ -724,7 +726,7 @@
       /* them. Be prepared to skip over them in old files for compatibility. */
 
       if (i == oVtx) {
-        while (getc(file) >= ' ')
+	while (!iscntrl((_char)getc(file)))
           ;
         if ((ch = getc(file)) != 'H')
           i = cuspHi;
