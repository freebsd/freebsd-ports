--- src/SHA1Storage.cpp.orig	Fri Dec 20 14:06:10 2002
+++ src/SHA1Storage.cpp	Fri Dec 20 14:13:03 2002
@@ -100,7 +100,7 @@
 QString *SHA1Storage::get(SharedFile *sf)
 { 
       std::string n = sf -> completeFilename();
-      n += std::string::traits_type::eos();
+      n += '\0'; // std::string::traits_type::eos();
       QString fileName(n.data());
       QString *result = _cache[fileName];
       if (!result) {
