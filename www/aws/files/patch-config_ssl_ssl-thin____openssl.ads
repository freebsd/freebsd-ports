--- config/ssl/ssl-thin__openssl.ads.orig	2015-06-22 10:52:10 UTC
+++ config/ssl/ssl-thin__openssl.ads
@@ -723,15 +723,6 @@ package SSL.Thin is
    -- Context control routines  --
    -------------------------------
 
-   function SSLv3_method         return SSL_Method
-     with Import, Convention => C, External_Name => "SSLv3_method";
-
-   function SSLv3_server_method  return SSL_Method
-     with Import, Convention => C, External_Name => "SSLv3_server_method";
-
-   function SSLv3_client_method  return SSL_Method
-     with Import, Convention => C, External_Name => "SSLv3_client_method";
-
    function SSLv23_method        return SSL_Method
      with Import, Convention => C, External_Name => "SSLv23_method";
 
