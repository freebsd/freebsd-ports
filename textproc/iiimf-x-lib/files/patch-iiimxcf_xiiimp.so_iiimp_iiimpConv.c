--- iiimxcf/xiiimp.so/iiimp/iiimpConv.c	Wed Apr 28 18:28:59 2004
+++ iiimxcf/xiiimp.so/iiimp/iiimpConv.c	Wed Feb 16 20:41:07 2005
@@ -68,7 +68,7 @@
 #ifdef USE_CSCONV
 #include <dlfcn.h>
 #include "csconv.h"
-#define CSC_PATH	"/usr/lib/im/csconv/csconv.so"
+#define CSC_PATH	(IMDIR "/csconv/csconv.so")
 #define CSC_OPEN_LOCALE	"csconv_open_locale"
 #define CSC_OPEN	"csconv_open"
 #define CSC_CONV	"csconv"
