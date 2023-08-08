--- mlxarchive/mlxarchive_mfa2.cpp.orig	2022-12-16 18:15:27.440142000 +0100
+++ mlxarchive/mlxarchive_mfa2.cpp	2022-12-16 18:16:25.933770000 +0100
@@ -40,7 +40,9 @@
  */
 
 #include <xz_utils/xz_utils.h>
+#ifndef NO_OPEN_SSL
 #include <mlxsign_lib/mlxsign_lib.h>
+#endif
 #include "mlxarchive_mfa2.h"
 #include "mlxarchive_mfa2_utils.h"
 
@@ -115,6 +117,7 @@
         printf("-E- zipped size not as expected\n");
         exit(1);
     }
+#ifndef NO_OPEN_SSL
     // compute descriptors SHA256
     vector<u_int8_t> descriptorsBuff;
     packDescriptors(descriptorsBuff);
@@ -131,6 +134,7 @@
     mlxSignSHA256 << zippedComponentBlockBuff;
     mlxSignSHA256.getDigest(digest);
     _packageDescriptor.setSHA256(digest);
+#endif
 }
 
 /*void MFA2::update(vector<u_int8_t>& buff)
