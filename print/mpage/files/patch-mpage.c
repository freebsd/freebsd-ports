$OpenBSD: patch-mpage_c,v 1.1 2002/07/07 17:03:37 naddy Exp $
--- mpage.c.orig	Tue Nov 13 18:04:46 2001
+++ mpage.c	Sun May 19 01:00:14 2002
@@ -74,10 +74,10 @@ char **argv;
      */
     if (doprint) {
         if (printque != NULL)
-            (void) sprintf(outcommand, "%s %s%s",
+            (void) snprintf(outcommand, sizeof(outcommand), "%s %s%s",
                            printprog, printarg, printque);
         else
-            (void) strcpy(outcommand, printprog);
+            (void) strlcpy(outcommand, printprog, sizeof(outcommand));
         if ((outfd = popen(outcommand, "w")) == NULL) {
             fprintf(stderr, "%s: cannot create pipe for '%s'\n",
                             MPAGE, outcommand);
