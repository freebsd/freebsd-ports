--- edit.c.orig	Thu May 13 19:04:33 1999
+++ edit.c	Sun Jan  7 22:48:23 2007
@@ -344,6 +344,7 @@
      */
     if (*cp && cp[1] == '\r') {
 	delimiter = *cp;
+	indelimit = !indelimit;
 	cp += 2;
     }
 
@@ -847,7 +847,7 @@ add_glob(str, slen)
 	for (s = toglob; *s; s++) {
 		if (*s == '\\' && s[1])
 			s++;
-		else if (*s == '*' || *s == '[' || *s == '?' || *s == '$'
+		else if (*s == '*' || *s == '[' || *s == '?'
 			 || (s[1] == '(' /*)*/ && strchr("*+?@!", *s)))
 			break;
 		else if (ISDIRSEP(*s))
