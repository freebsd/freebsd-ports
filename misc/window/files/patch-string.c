--- string.c.orig	2009-02-23 10:26:32 UTC
+++ string.c
@@ -45,6 +45,8 @@ static char rcsid[] =
 #include <stdio.h>
 #include <stdlib.h>
 
+struct mystring str_head;
+
 char *
 str_cpy(s)
 register char *s;
