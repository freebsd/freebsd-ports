--- lib/stride/stride.c-xxx	Fri Dec 17 18:18:42 2004
+++ lib/stride/stride.c	Fri Dec 17 18:19:21 2004
@@ -93,7 +93,7 @@
   for( i=0; i<NHBond; i++ ) free(HBond[i]);
   free(Cmd);
 
-  return(SUCCESS);
+  return(0);
 }
 
 void ProcessStrideOptions(char **List, int ListLength, COMMAND *Cmd)
