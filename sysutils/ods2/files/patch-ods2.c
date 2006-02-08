--- ods2.c~	Fri Sep  7 23:17:04 2001
+++ ods2.c	Tue Jan 31 13:03:50 2006
@@ -1094,8 +1094,10 @@
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
