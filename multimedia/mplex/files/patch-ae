--- interact.c.orig	Wed May 31 20:18:33 1995
+++ interact.c	Fri Feb 11 10:04:07 2000
@@ -67,7 +67,7 @@
     char input[20];
 
     printf ("\nContinue processing (y/n) : ");
-    do gets (input);
+    do fgets (input, sizeof(input), stdin);
     while (input[0]!='N'&&input[0]!='n'&&input[0]!='y'&&input[0]!='Y');
 
     if (input[0]=='N' || input[0]=='n')
@@ -92,7 +92,7 @@
     char input[20];
 
     printf ("\nVery verbose mode (y/n) : ");
-    do gets (input);
+    do fgets (input, sizeof(input), stdin);
     while (input[0]!='N'&&input[0]!='n'&&input[0]!='y'&&input[0]!='Y');
 
     if (input[0]=='N' || input[0]=='n') return (FALSE); else return (TRUE);
