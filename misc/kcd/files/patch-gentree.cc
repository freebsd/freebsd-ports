--- gentree.cc.orig
+++ gentree.cc
@@ -29,6 +29,10 @@
 #include "cstrlib.h"
 #include "scandir.h"
 
+#ifdef HAVE_UNISTD_H
+# include <unistd.h>
+#endif
+
 //#define DUMP_HTML	
 #ifdef DUMP_HTML
 # include <fcntl.h>
