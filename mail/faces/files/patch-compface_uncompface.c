--- compface/uncompface.c.orig
+++ compface/uncompface.c
@@ -14,16 +14,19 @@
  *  to me, then an attempt will be made to fix them.
  */
 
+#define MAIN
+
 #include "compface.h"
-#include "vars.h"
 
 int
-uncompface(char *fbuf)
+uncompface(fbuf)
+char *fbuf;
 {
-    if (!(status = setjmp(comp_env))) {
-        UnCompAll(fbuf);       /* compress otherwise */
+	if (!(status = setjmp(comp_env)))
+	{
+		UnCompAll(fbuf);/* compress otherwise */
         UnGenFace();
         WriteFace(fbuf);
     }
-    return(status);
+	return status;
 }
