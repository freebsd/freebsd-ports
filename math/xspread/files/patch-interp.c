--- interp.c.orig	1995-11-07 02:17:26 UTC
+++ interp.c
@@ -516,7 +516,7 @@ int mo, day, yr;
     mdays[1] = 28 + (yr%4 == 0);
 
     if (mo < 1 || mo > 12 || day < 1 || day > mdays[--mo] ||
-		yr > 1999 || yr < 1970) {
+		yr > 2099 || yr < 1970) {
 	scerror("@dts: invalid argument");
 	cellerror = CELLERROR;
 	return(0.0);
