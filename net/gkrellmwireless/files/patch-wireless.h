--- wireless.h.orig	Thu Aug 22 15:38:11 2002
+++ wireless.h	Thu Aug 22 15:38:24 2002
@@ -21,7 +21,7 @@
 #include <gkrellm/gkrellm.h>
 #ifdef __FreeBSD__
   #include <net/if.h>
-  #include <machine/if_wavelan_ieee.h>
+  #include <dev/wi/if_wavelan_ieee.h>
   #define ANCACHE
   #include <dev/an/if_aironet_ieee.h>
 #endif
