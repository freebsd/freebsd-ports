--- rename.c.orig	2002-05-20 15:50:50 UTC
+++ rename.c
@@ -65,7 +65,7 @@
 
 #if HAVE_REGEX_H
   #include <regex.h>
-#elif
+#else
   #include "regex.h"
 #endif
 
@@ -608,7 +608,7 @@ int do_rename(char *oldp, char *newp)
 
 skip:
     if (attr & MOD_VERBO) 
-	printf("skiped\n");
+	printf("skipped\n");
     return rs;
 }
 
@@ -659,6 +659,6 @@ Report bugs to <xuming@bigfoot.com>.\n";
     if (mode)  
 	printf(version, VERSION);  
     else  
-	printf(help);
+	printf("%s", help);
 }
 
