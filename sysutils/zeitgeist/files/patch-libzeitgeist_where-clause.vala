--- libzeitgeist/where-clause.vala.orig	2017-09-03 19:29:23 UTC
+++ libzeitgeist/where-clause.vala
@@ -217,7 +217,7 @@ namespace Zeitgeist
             long[] pointers = new long[gptrarr.length + 1];
 #endif
             Memory.copy(pointers, ((PtrArray *) gptrarr)->pdata,
-                (gptrarr.length) * sizeof (void *));
+                gptrarr.length * sizeof (void *));
             return (T[]) pointers;
         }
 
