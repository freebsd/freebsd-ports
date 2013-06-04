--- simget.c.orig
+++ simget.c
@@ -19,8 +19,9 @@
 
 #include <stdio.h>
 
-
-#define RAND_MAX  ((1<<31)-1)
+#ifndef RAND_MAX
+#define RAND_MAX  ((1UL<<31)-1)
+#endif
 
 
 /*************************************************************************
@@ -32,6 +33,7 @@ void SimGetInit()
   unsigned int e;
   
   srand( 17);
+  srandom( 17);
 }
 
 
