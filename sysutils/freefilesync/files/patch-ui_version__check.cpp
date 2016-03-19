--- ui/version_check.cpp.orig	2016-03-09 02:07:44 UTC
+++ ui/version_check.cpp
@@ -112,17 +112,10 @@ std::string geHttpPostParameters() //mus
     const auto osvMinor = getOsVersion().minor;
 
 #elif defined ZEN_LINUX
-    params += "&os_name=Linux";
-    assert(std::this_thread::get_id() == mainThreadId);
-
-    const wxLinuxDistributionInfo distribInfo = wxGetLinuxDistributionInfo();
-    assert(contains(distribInfo.Release, L'.'));
-    std::vector<wxString> digits = split<wxString>(distribInfo.Release, L'.'); //e.g. "15.04"
-    digits.resize(2);
-    //distribInfo.Id //e.g. "Ubuntu"
+    params += "&os_name=FreeBSD";
 
-    const int osvMajor = stringTo<int>(digits[0]);
-    const int osvMinor = stringTo<int>(digits[1]);
+    const int osvMajor = 0;
+    const int osvMinor = 0;
 
 #elif defined ZEN_MAC
     params += "&os_name=Mac";
