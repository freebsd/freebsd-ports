--- OrthancServer/OrthancInitialization.cpp.orig	2016-06-27 11:02:35 UTC
+++ OrthancServer/OrthancInitialization.cpp
@@ -534,7 +534,9 @@ namespace Orthanc
 #if ORTHANC_SSL_ENABLED == 1
     // Finalize OpenSSL
     // https://wiki.openssl.org/index.php/Library_Initialization#Cleanup
+#ifdef FIPS_mode_set
     FIPS_mode_set(0);
+#endif
     ENGINE_cleanup();
     CONF_modules_unload(1);
     EVP_cleanup();
