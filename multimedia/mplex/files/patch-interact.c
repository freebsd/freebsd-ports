--- interact.c.orig	1995-05-31 11:18:33 UTC
+++ interact.c
@@ -67,7 +67,7 @@ void ask_continue ()
     char input[20];
 
     printf ("\nContinue processing (y/n) : ");
-    do gets (input);
+    do fgets (input, sizeof(input), stdin);
     while (input[0]!='N'&&input[0]!='n'&&input[0]!='y'&&input[0]!='Y');
 
     if (input[0]=='N' || input[0]=='n')
@@ -92,7 +92,7 @@ unsigned char ask_verbose ()
     char input[20];
 
     printf ("\nVery verbose mode (y/n) : ");
-    do gets (input);
+    do fgets (input, sizeof(input), stdin);
     while (input[0]!='N'&&input[0]!='n'&&input[0]!='y'&&input[0]!='Y');
 
     if (input[0]=='N' || input[0]=='n') return (FALSE); else return (TRUE);
