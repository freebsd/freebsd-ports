--- chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc.orig	2024-06-22 08:49:42 UTC
+++ chrome/browser/enterprise/profile_management/profile_management_navigation_throttle.cc
@@ -66,8 +66,8 @@ base::flat_map<std::string, SAMLProfileAttributes>& Ge
   // TODO(crbug.com/40267996): Add actual domains with attribute names.
   profile_attributes->insert(std::make_pair(
       "supported.test",
-      SAMLProfileAttributes("placeholderName", "placeholderDomain",
-                            "placeholderToken")));
+      SAMLProfileAttributes(SAMLProfileAttributes{"placeholderName", "placeholderDomain",
+                            "placeholderToken"})));
 
   // Extract domains and attributes from the command line switch.
   const base::CommandLine& command_line =
