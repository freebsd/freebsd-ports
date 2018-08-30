--- src/lib/ndpi_main.c.orig	2018-08-30 09:28:13 UTC
+++ src/lib/ndpi_main.c
@@ -43,9 +43,7 @@
 
 #include "ndpi_content_match.c.inc"
 #include "third_party/include/ndpi_patricia.h"
-#include "third_party/src/ndpi_patricia.c"
 #include "third_party/include/hash.h"
-#include "third_party/src/hash.c"
 
 #ifdef HAVE_HYPERSCAN
 #include <hs/hs.h>
