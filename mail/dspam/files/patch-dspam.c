--- dspam.c.orig	Fri Apr  2 18:34:35 2004
+++ dspam.c	Mon Apr 26 23:59:03 2004
@@ -2422,12 +2422,12 @@
         i++;
       }
     }
-    arg = strsep (&margs, " ");
-
+ 
     if (arg != NULL) {
       strlcat (args, a, sizeof(args));
       strlcat (args, " ", sizeof (args));
     }
+    arg = strsep (&margs, " ");
   }
   free (mmargs);
 
