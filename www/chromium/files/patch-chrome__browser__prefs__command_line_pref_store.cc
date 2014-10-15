--- chrome/browser/prefs/command_line_pref_store.cc.orig	2014-10-02 17:39:46 UTC
+++ chrome/browser/prefs/command_line_pref_store.cc
@@ -33,6 +33,7 @@
       { switches::kDiskCacheDir, prefs::kDiskCacheDir },
       { switches::kSSLVersionMin, prefs::kSSLVersionMin },
       { switches::kSSLVersionMax, prefs::kSSLVersionMax },
+      { switches::kSSLVersionFallbackMin, prefs::kSSLVersionFallbackMin },
 };
 
 const CommandLinePrefStore::BooleanSwitchToPreferenceMapEntry
