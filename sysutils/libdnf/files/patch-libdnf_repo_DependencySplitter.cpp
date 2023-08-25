- from https://bugs.freebsd.org/bugzilla/show_bug.cgi?id=273044
- fix regex and duplicate rtti

--- libdnf/repo/DependencySplitter.cpp.orig	2023-07-28 12:49:18 UTC
+++ libdnf/repo/DependencySplitter.cpp
@@ -29,7 +29,7 @@ static const Regex RELDEP_REGEX = 
 namespace libdnf {
 
 static const Regex RELDEP_REGEX = 
-    Regex("^(\\S*)\\s*(<=|>=|<|>|=|==)?\\s*(\\S*)$", REG_EXTENDED);
+    Regex("^([^[:space:]]*)[[:space:]]*(<=|>=|<|>|=|==)?[[:space:]]*([^[:space:]]*)$", REG_EXTENDED);
 
 static bool
 getCmpFlags(int *cmp_type, std::string matchCmpType)
