--- src/rda.c.orig	Tue Mar 11 13:20:22 2003
+++ src/rda.c	Tue Apr 22 13:53:10 2003
@@ -376,7 +376,7 @@
   options,                           /* specials that are allowed */
   generated,                         /* where to hang them */
   error,                             /* for errors */
-  qualify_domain_recipient,          /* to qualify \name */
+  deliver_domain,                    /* to qualify \name */
   include_directory,                 /* restrain to directory */
   eblockp);                          /* for skipped syntax errors */
 }
