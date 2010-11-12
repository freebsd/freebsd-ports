Description: Skip the timestamp when matching specified patterns.
Origin: http://marc.info/?m=96056408505485
Author: Gerritt Pape <pape@smarden.org>
Last-Update: 2010-11-12

--- multilog.c.orig
+++ multilog.c
@@ -496,7 +496,7 @@
   flagtimestamp = 0;
   if (script[0])
     if (script[0][0] == 't')
-      flagtimestamp = 1;
+      flagtimestamp = 26;
 
   for (i = 0;i <= 1000;++i) line[i] = '\n';
   linelen = 0;
@@ -529,12 +529,12 @@
       switch(*action) {
         case '+':
           if (!flagselected)
-            if (match(action + 1,line,linelen))
+            if (match(action + 1,line + flagtimestamp,linelen - flagtimestamp))
               flagselected = 1;
           break;
         case '-':
           if (flagselected)
-            if (match(action + 1,line,linelen))
+            if (match(action + 1,line + flagtimestamp,linelen - flagtimestamp))
               flagselected = 0;
           break;
         case 'e':
