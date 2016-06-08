--- config/ssl/aws-net-ssl__openssl.adb.orig	2015-06-22 10:52:10 UTC
+++ config/ssl/aws-net-ssl__openssl.adb
@@ -1819,10 +1819,7 @@ package body AWS.Net.SSL is
                       TLSv1_1_Client => TSSL.TLSv1_1_client_method'Access,
                       TLSv1_2        => TSSL.TLSv1_2_method'Access,
                       TLSv1_2_Server => TSSL.TLSv1_2_server_method'Access,
-                      TLSv1_2_Client => TSSL.TLSv1_2_client_method'Access,
-                      SSLv3          => TSSL.SSLv3_method'Access,
-                      SSLv3_Server   => TSSL.SSLv3_server_method'Access,
-                      SSLv3_Client   => TSSL.SSLv3_client_method'Access);
+                      TLSv1_2_Client => TSSL.TLSv1_2_client_method'Access);
 
          ---------------------
          -- Set_Certificate --
