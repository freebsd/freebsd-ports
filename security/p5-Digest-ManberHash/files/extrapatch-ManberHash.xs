--- ManberHash.xs.orig	Sat Dec 24 11:04:38 2005
+++ ManberHash.xs	Sat Dec 24 11:04:06 2005
@@ -3,6 +3,14 @@
 #include "perl.h"
 #include "XSUB.h"
 
+/* try to be compatible with older perls */
+/* SvPV_nolen() macro first defined in 5.005_55 */
+/* this is slow, not threadsafe, but works */
+#include "patchlevel.h"
+#if (PATCHLEVEL == 4) || ((PATCHLEVEL == 5) && (SUBVERSION < 55))
+static STRLEN nolen_na;
+# define SvPV_nolen(sv) SvPV ((sv), nolen_na)
+#endif
 
 #define BUFFER_SIZE (8192)
 #define BUFFER_2SIZE (BUFFER_SIZE*2)
@@ -105,7 +113,7 @@
        }
      */
 
-    fh=open(filename,O_RDONLY);
+    fh=open(filename,0000);
     if (fh<0) 
       return;
 
