--- src/rewrite.c.orig	Tue Mar 11 13:20:22 2003
+++ src/rewrite.c	Tue Apr 15 14:48:37 2003
@@ -261,7 +261,7 @@
         while (*p2 == ' ') p2++;
         pf2 = parse_fix_phrase(p2, Ustrlen(p2), buff2, sizeof(buff2));
 
-        start = Ustrlen(buff1) + start + new - p1;
+        start = Ustrlen(pf1) + start + new - p1;
         end = start + Ustrlen(newparsed);
         new = string_sprintf("%s%.*s%s", pf1, p2 - p1, p1, pf2);
         }
