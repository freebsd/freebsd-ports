--- scandir.cc.orig
+++ scandir.cc
@@ -32,6 +32,10 @@
 #include "cstrlib.h"
 #include "dirtree.h"
 
+#ifdef HAVE_UNISTD_H
+# include <unistd.h>
+#endif
+
 /*************************************************************************
 	Log scan results to command line output
 *************************************************************************/
