--- ods2.c.orig	2001-09-07 21:17:04 UTC
+++ ods2.c
@@ -1094,8 +1094,10 @@ int main(int argc,char *argv[])
 #ifdef VMS
 	    if (getcmd (str, "$> ") == NULL) break;
 #else
-            printf("$> ");
-            if (gets(str) == NULL) break;
+          printf("$> ");
+          if (fgets(str, sizeof(str), stdin) == NULL)
+              break;
+          str[strlen(str)-1] = '\0'; /* strip newline from str */
 #endif
         }
         ptr = str;
