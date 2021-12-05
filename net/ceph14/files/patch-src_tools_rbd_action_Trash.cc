diff --git src/tools/rbd/action/Trash.cc src/tools/rbd/action/Trash.cc
index c4a17e4134..8b8fd8a322 100644
--- src/tools/rbd/action/Trash.cc
+++ src/tools/rbd/action/Trash.cc
@@ -12,6 +12,7 @@
  *
  */
 
+#include "include/compat.h"
 #include "tools/rbd/ArgumentTypes.h"
 #include "tools/rbd/Shell.h"
 #include "tools/rbd/Utils.h"
@@ -145,9 +146,6 @@ int execute_remove(const po::variables_map &vm,
       std::cerr << "rbd: image has snapshots - these must be deleted"
                 << " with 'rbd snap purge' before the image can be removed."
                 << std::endl;
-    } else if (r == -EUCLEAN) {
-      std::cerr << "rbd: error: image not fully moved to trash."
-                << std::endl;
     } else if (r == -EBUSY) {
       std::cerr << "rbd: error: image still has watchers"
                 << std::endl
