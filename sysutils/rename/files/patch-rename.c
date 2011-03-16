--- ./rename.c.orig	2002-05-20 11:50:50.000000000 -0400
+++ ./rename.c	2011-03-13 05:05:52.000000000 -0400
@@ -65,7 +65,7 @@
 
 #if HAVE_REGEX_H
   #include <regex.h>
-#elif
+#else
   #include "regex.h"
 #endif
 
@@ -608,7 +608,7 @@
 
 skip:
     if (attr & MOD_VERBO) 
-	printf("skiped\n");
+	printf("skipped\n");
     return rs;
 }
 
@@ -659,6 +659,6 @@
     if (mode)  
 	printf(version, VERSION);  
     else  
-	printf(help);
+	printf("%s", help);
 }
 
