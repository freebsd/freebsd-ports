--- chrome/browser/net/ssl_config_service_manager_pref.cc.orig	2014-10-02 17:39:46 UTC
+++ chrome/browser/net/ssl_config_service_manager_pref.cc
@@ -174,6 +174,7 @@
   BooleanPrefMember rev_checking_required_local_anchors_;
   StringPrefMember ssl_version_min_;
   StringPrefMember ssl_version_max_;
+  StringPrefMember ssl_version_fallback_min_;
   BooleanPrefMember ssl_record_splitting_disabled_;
 
   // The cached list of disabled SSL cipher suites.
@@ -204,6 +205,8 @@
       prefs::kSSLVersionMin, local_state, local_state_callback);
   ssl_version_max_.Init(
       prefs::kSSLVersionMax, local_state, local_state_callback);
+  ssl_version_fallback_min_.Init(
+      prefs::kSSLVersionFallbackMin, local_state, local_state_callback);
   ssl_record_splitting_disabled_.Init(
       prefs::kDisableSSLRecordSplitting, local_state, local_state_callback);
 
@@ -230,8 +233,12 @@
       SSLProtocolVersionToString(default_config.version_min);
   std::string version_max_str =
       SSLProtocolVersionToString(default_config.version_max);
+  std::string version_fallback_min_str =
+      SSLProtocolVersionToString(default_config.version_fallback_min);
   registry->RegisterStringPref(prefs::kSSLVersionMin, version_min_str);
   registry->RegisterStringPref(prefs::kSSLVersionMax, version_max_str);
+  registry->RegisterStringPref(prefs::kSSLVersionFallbackMin,
+                               version_fallback_min_str);
   registry->RegisterBooleanPref(prefs::kDisableSSLRecordSplitting,
                                 !default_config.false_start_enabled);
   registry->RegisterListPref(prefs::kCipherSuiteBlacklist);
@@ -275,10 +282,14 @@
       rev_checking_required_local_anchors_.GetValue();
   std::string version_min_str = ssl_version_min_.GetValue();
   std::string version_max_str = ssl_version_max_.GetValue();
+  std::string version_fallback_min_str = ssl_version_fallback_min_.GetValue();
   config->version_min = net::kDefaultSSLVersionMin;
   config->version_max = net::kDefaultSSLVersionMax;
+  config->version_fallback_min = net::kDefaultSSLVersionFallbackMin;
   uint16 version_min = SSLProtocolVersionFromString(version_min_str);
   uint16 version_max = SSLProtocolVersionFromString(version_max_str);
+  uint16 version_fallback_min =
+      SSLProtocolVersionFromString(version_fallback_min_str);
   if (version_min) {
     // TODO(wtc): get the minimum SSL protocol version supported by the
     // SSLClientSocket class. Right now it happens to be the same as the
@@ -293,6 +304,9 @@
     uint16 supported_version_max = config->version_max;
     config->version_max = std::min(supported_version_max, version_max);
   }
+  if (version_fallback_min) {
+    config->version_fallback_min = version_fallback_min;
+  }
   config->disabled_cipher_suites = disabled_cipher_suites_;
   // disabling False Start also happens to disable record splitting.
   config->false_start_enabled = !ssl_record_splitting_disabled_.GetValue();
