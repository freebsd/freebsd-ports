--- compface/compface.c.orig
+++ compface/compface.c
@@ -14,16 +14,19 @@
  *  to me, then an attempt will be made to fix them.
  */
 
+#define MAIN
+
 #include "compface.h"
-#include "vars.h"
 
 int
-compface(char *fbuf)
+compface(fbuf)
+char *fbuf;
 {
-    if (!(status = setjmp(comp_env))) {
+	if (!(status = setjmp(comp_env)))
+	{
         ReadFace(fbuf);
         GenFace();
         CompAll(fbuf);
     }
-    return(status);
+	return status;
 }
