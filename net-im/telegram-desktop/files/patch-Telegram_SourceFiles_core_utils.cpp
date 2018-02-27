--- Telegram/SourceFiles/core/utils.cpp.orig	2018-02-27 20:30:42 UTC
+++ Telegram/SourceFiles/core/utils.cpp
@@ -308,7 +308,9 @@ namespace ThirdParty {
 		av_lockmgr_register(nullptr);
 
 		CRYPTO_cleanup_all_ex_data();
+#ifndef LIBRESSL_VERSION_NUMBER
 		FIPS_mode_set(0);
+#endif
 		ENGINE_cleanup();
 		CONF_modules_unload(1);
 		ERR_remove_state(0);
