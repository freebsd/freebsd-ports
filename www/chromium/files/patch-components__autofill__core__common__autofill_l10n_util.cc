--- components/autofill/core/common/autofill_l10n_util.cc.orig	2016-01-21 18:39:29.016461188 +0100
+++ components/autofill/core/common/autofill_l10n_util.cc	2016-01-21 18:39:45.136459722 +0100
@@ -22,7 +22,7 @@
     // library. This could be due to a device-specific issue (has been seen in
     // the wild on Android devices). In the failure case, |collator_| will be
     // null. See http://crbug.com/558625.
-    icu_54::UnicodeString name;
+    icu_55::UnicodeString name;
     std::string locale_name;
     locale.getDisplayName(name).toUTF8String(locale_name);
     LOG(ERROR) << "Failed to initialize the ICU Collator for "
