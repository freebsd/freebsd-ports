--- interp.c.orig	Tue Nov  7 03:17:26 1995
+++ interp.c	Fri Mar 10 13:34:37 2000
@@ -516,7 +516,7 @@
     mdays[1] = 28 + (yr%4 == 0);
 
     if (mo < 1 || mo > 12 || day < 1 || day > mdays[--mo] ||
-		yr > 1999 || yr < 1970) {
+		yr > 2099 || yr < 1970) {
 	scerror("@dts: invalid argument");
 	cellerror = CELLERROR;
 	return(0.0);
