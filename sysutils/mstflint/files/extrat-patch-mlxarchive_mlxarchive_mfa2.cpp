--- mlxarchive/mlxarchive_mfa2.cpp.orig	2020-01-05 16:50:06.000000000 +0100
+++ mlxarchive/mlxarchive_mfa2.cpp	2020-01-09 14:20:54.186228000 +0100
@@ -39,7 +39,9 @@
  */
 
 #include <xz_utils/xz_utils.h>
+#ifndef NO_OPEN_SSL
 #include <mlxsign_lib/mlxsign_lib.h>
+#endif
 #include "mlxarchive_mfa2.h"
 #include "mlxarchive_mfa2_utils.h"
 
@@ -120,6 +122,7 @@ void MFA2::pack(vector<u_int8_t>& buff)
     xz_compress_crc32(9, componentsBlockBuff.data(), componentsBlockBuff.size(),
             zippedComponentBlockBuff.data(), zippedSize);
 
+#ifndef NO_OPEN_SSL
     //compute descriptors SHA256
     vector<u_int8_t> descriptorsBuff;
     packDescriptors(descriptorsBuff);
@@ -136,7 +139,7 @@ void MFA2::pack(vector<u_int8_t>& buff)
     mlxSignSHA256 << zippedComponentBlockBuff;
     mlxSignSHA256.getDigest(digest);
     _packageDescriptor.setSHA256(digest);
-
+#endif
 }
 
 /*void MFA2::update(vector<u_int8_t>& buff)
