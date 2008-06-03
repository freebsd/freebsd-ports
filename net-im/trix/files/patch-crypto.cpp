--- src/crypto.cpp.orig		2008-01-04 18:25:54.000000000 +0200
+++ src/crypto.cpp		2008-04-21 01:30:02.000000000 +0300
@@ -1,4 +1,5 @@
 #include "crypto.h"
+typedef unsigned int uint;
 //#include <iostream>
 
 PROV_ENUMALGS_EX aProvEnumAlgsEx[4][RSAENH_MAX_ENUMALGS+1] =
