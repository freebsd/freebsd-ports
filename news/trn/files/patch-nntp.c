--- nntp.c.orig	Fri Nov 18 22:01:23 1994
+++ nntp.c	Sun Jul 21 13:13:58 1996
@@ -319,8 +319,8 @@
     for (month--; month; month--)
 	day += maxdays[month];
 
-    ss = ((((year-1970) * 365 + (year-1968)/4 + day - 1) * 24L + hh) * 60
-	  + mm) * 60 + ss;
+    ss = ((((year-1970) * 365 + (year-1969)/4 + day - 1) * 24L + hh) * 60
+        + mm) * 60 + ss;
 
     return ss;
 }
