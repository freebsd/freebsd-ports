--- nss_cache/nss_cache.cc.orig	2018-06-11 17:16:50 UTC
+++ nss_cache/nss_cache.cc
@@ -31,8 +31,8 @@ using oslogin_utils::MutexLock;
 using oslogin_utils::NssCache;
 
 // File paths for the nss cache file.
-static const char kDefaultFilePath[] = "/etc/oslogin_passwd.cache";
-static const char kDefaultBackupFilePath[] = "/etc/oslogin_passwd.cache.bak";
+static const char kDefaultFilePath[] = "%%PREFIX%%/etc/oslogin_passwd.cache";
+static const char kDefaultBackupFilePath[] = "%%PREFIX%%/etc/oslogin_passwd.cache.bak";
 
 // Local NSS Cache size. This affects the maximum number of passwd entries per
 // http request.
