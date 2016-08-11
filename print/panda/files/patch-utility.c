--- ./utility.c.orig	2004-04-13 02:46:24.000000000 +0200
+++ ./utility.c	2014-08-15 19:13:36.000000000 +0200
@@ -509,7 +509,7 @@
   char *output;
 
   length = strlen (input);
-  output = panda_xmalloc ((length + 1) * sizeof (char));
+  output = panda_xmalloc ((length*2 + 1) * sizeof (char));
   
     // todo_mikal: not sure I like the windows version of this code
     for (count = 0; count < length; count++)
@@ -518,11 +518,11 @@
       sprintf (output[count], "%2x", input[count]);
       
 #else	/*  */
-      snprintf (output[count], 1, "%2x", input[count]);
+      sprintf (output+count*2, "%2x", input[count]);
       
 #endif
     }
 
-  output[length + 1] = 0;
+  output[length*2] = 0;
   return output;
 }
