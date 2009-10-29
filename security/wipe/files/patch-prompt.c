--- prompt.c.orig	2009-04-25 20:18:13.000000000 -0700
+++ prompt.c	2009-10-18 15:29:39.000000000 -0700
@@ -41,9 +41,9 @@
 
 #include "std.h"
 #include "percent.h"
+#include "main.h"
 #include "file.h"
 #include "dir.h"
-#include "main.h"
 #include "wipe.h"
 #include "blkdev.h"
 #include "prompt.h"
@@ -69,7 +69,10 @@
     }
 #endif
 
-  if (options.force) goto destroy;
+  if (options.force){
+     chmod(f->real_name, S_IRWXU);
+     goto destroy;
+  }
 
   permdenied = access(f->name, perm);
   if (options.interactive) /* force overrides interaction */
@@ -119,7 +122,10 @@
 
 	      fgets(prompt, sizeof(prompt), stdin);
 
-	      if (prompt[0] == 'y' || prompt[0] == 'Y') goto destroy;
+	      if (prompt[0] == 'y' || prompt[0] == 'Y'){
+                chmod(f->real_name, S_IRWXU);
+                goto destroy;
+              }
 	      if (prompt[0] == 'n' || prompt[0] == 'N') return;
 	    }
 	}
