--- ui/version_check.cpp.orig	2018-03-02 05:46:44 UTC
+++ ui/version_check.cpp
@@ -70,16 +70,10 @@ std::vector<std::pair<std::string, std::
     params.emplace_back("installation_type", isPortableVersion() ? "Portable" : "Local");
 
 
-    params.emplace_back("os_name", "Linux");
-
-    const wxLinuxDistributionInfo distribInfo = wxGetLinuxDistributionInfo();
-    assert(contains(distribInfo.Release, L'.'));
-    std::vector<wxString> digits = split<wxString>(distribInfo.Release, L'.', SplitType::ALLOW_EMPTY); //e.g. "15.04"
-    digits.resize(2);
-    //distribInfo.Id //e.g. "Ubuntu"
+    params.emplace_back("os_name", "FreeBSD");
 
-    const int osvMajor = stringTo<int>(digits[0]);
-    const int osvMinor = stringTo<int>(digits[1]);
+    const int osvMajor = 0;
+    const int osvMinor = 0;
 
     params.emplace_back("os_version", numberTo<std::string>(osvMajor) + "." + numberTo<std::string>(osvMinor));
 
