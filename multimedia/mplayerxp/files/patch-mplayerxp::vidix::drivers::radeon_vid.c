--- mplayerxp/vidix/drivers/radeon_vid.c.orig	Sun Nov 24 15:13:43 2002
+++ mplayerxp/vidix/drivers/radeon_vid.c	Sun Nov 24 15:13:53 2002
@@ -11,6 +11,7 @@
 #include <string.h>
 #include <math.h>
 #include <inttypes.h>
+#include <sys/types.h>
 #include <sys/mman.h>
 #include "../../libdha/pci_ids.h"
 #include "../../libdha/pci_names.h"
