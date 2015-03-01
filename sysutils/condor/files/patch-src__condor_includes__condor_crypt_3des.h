--- src/condor_includes/condor_crypt_3des.h.orig	2014-12-09 23:15:18.000000000 +0100
+++ src/condor_includes/condor_crypt_3des.h	2015-02-28 19:35:54.722059602 +0100
@@ -61,7 +61,7 @@
     //------------------------------------------
     // Private constructor
     //------------------------------------------
-    des_key_schedule  keySchedule1_, keySchedule2_, keySchedule3_;
+    DES_key_schedule  keySchedule1_, keySchedule2_, keySchedule3_;
     unsigned char     ivec_[8];
     int               num_;
 };
