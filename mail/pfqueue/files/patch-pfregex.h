--- pfregex.h.orig	Mon Mar 14 00:46:55 2005
+++ pfregex.h	Mon Mar 14 00:47:03 2005
@@ -1,7 +1,5 @@
-
+#include <sys/types.h>
 #include <regex.h>
 
 regex_t	*regexp;
 char	*regexps;
-
-
