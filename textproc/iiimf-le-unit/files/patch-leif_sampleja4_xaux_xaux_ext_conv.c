--- leif/sampleja4/xaux/xaux_ext_conv.c	Fri Jun 27 11:41:21 2003
+++ leif/sampleja4/xaux/xaux_ext_conv.c	Wed Feb 16 20:43:31 2005
@@ -79,7 +79,7 @@
 #ifdef USE_CSCONV
 #include <dlfcn.h>
 #include "csconv.h"
-#define CSC_PATH	"/usr/lib/im/csconv/csconv.so"
+#define CSC_PATH	(IMDIR "/csconv/csconv.so")
 #define CSC_OPEN_LOCALE	"csconv_open_locale"
 #define CSC_OPEN	"csconv_open"
 #define CSC_CONV	"csconv"
