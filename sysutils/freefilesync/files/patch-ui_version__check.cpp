--- ui/version_check.cpp.orig	2016-06-30 13:33:44.614966000 +0800
+++ ui/version_check.cpp	2016-06-30 13:36:17.540454000 +0800
@@ -104,16 +104,10 @@
     const auto osvMinor = getOsVersion().minor;
 
 #elif defined ZEN_LINUX
-    params.emplace_back("os_name", "Linux");
+    params.emplace_back("os_name", "FreeBSD");
 
-    const wxLinuxDistributionInfo distribInfo = wxGetLinuxDistributionInfo();
-    assert(contains(distribInfo.Release, L'.'));
-    std::vector<wxString> digits = split<wxString>(distribInfo.Release, L'.'); //e.g. "15.04"
-    digits.resize(2);
-    //distribInfo.Id //e.g. "Ubuntu"
-
-    const int osvMajor = stringTo<int>(digits[0]);
-    const int osvMinor = stringTo<int>(digits[1]);
+    const int osvMajor = 0;
+    const int osvMinor = 0;
 
 #elif defined ZEN_MAC
     params.emplace_back("os_name", "Mac");
