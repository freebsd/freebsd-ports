--- ./hald/freebsd/hf-devtree.c.orig	2009-09-17 15:47:14.000000000 +0200
+++ ./hald/freebsd/hf-devtree.c	2013-10-22 02:16:42.548388644 +0200
@@ -36,6 +36,7 @@
 #include "hf-ata.h"
 #include "hf-block.h"
 #include "hf-drm.h"
+#include "hf-memcard.h"
 #include "hf-pcmcia.h"
 #include "hf-storage.h"
 #include "hf-util.h"
@@ -388,7 +389,9 @@
   { "psm",		hf_devtree_psm_set_properties		},
   { "sio",		NULL					},
   { "speaker",		NULL					},
-  { "usbus",		NULL					}
+  { "usbus",		NULL					},
+  { "mmc",		hf_mmc_host_set_properties		},
+  { "mmcsd",		hf_mmc_set_properties			}
 };
 
 static void
