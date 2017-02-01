--- libflatfile/JFile3.cpp.orig	2003-06-19 23:37:46 UTC
+++ libflatfile/JFile3.cpp
@@ -454,7 +454,7 @@ PalmLib::FlatFile::JFile3::getOptions(vo
 void PalmLib::FlatFile::JFile3::JFileAppInfoType::unpack(const PalmLib::Block& block)
 {
     unsigned i;
-    pi_char_t* null_ptr;
+    const pi_char_t* null_ptr;
 
     // Ensure that we have enough space to extract information from.
     if (block.size() < ( (20 * (20+1)) + 20*2 + 2 + 2 + 20*2 + 2
@@ -467,7 +467,7 @@ void PalmLib::FlatFile::JFile3::JFileApp
     // Extract the field names.
     for (i = 0; i < 20; ++i) {
         /* Find the trailing null byte and extract the string. */
-        null_ptr = reinterpret_cast<pi_char_t*> (memchr(p, 0, 21));
+        null_ptr = reinterpret_cast<const pi_char_t*> (memchr(p, 0, 21));
         if (null_ptr)
             fieldNames[i] = std::string((char *) p, null_ptr - p);
         else
@@ -518,7 +518,7 @@ void PalmLib::FlatFile::JFile3::JFileApp
     p += sizeof(pi_uint16_t);
 
     // Extract the string used last by Find.
-    null_ptr = reinterpret_cast<pi_char_t*> (memchr(p, 0, 16));
+    null_ptr = reinterpret_cast<const pi_char_t*> (memchr(p, 0, 16));
     if (null_ptr)
         findString = std::string((char *) p, null_ptr - p);
     else
@@ -526,7 +526,7 @@ void PalmLib::FlatFile::JFile3::JFileApp
     p += 16;
 
     // Extract the string used last by Filter.
-    null_ptr = reinterpret_cast<pi_char_t*> (memchr(p, 0, 16));
+    null_ptr = reinterpret_cast<const pi_char_t*> (memchr(p, 0, 16));
     if (null_ptr)
         filterString = std::string((char *) p, null_ptr - p);
     else
@@ -542,7 +542,7 @@ void PalmLib::FlatFile::JFile3::JFileApp
     p += sizeof(pi_uint16_t);
 
     // Extract the password (if any).
-    null_ptr = reinterpret_cast<pi_char_t*> (memchr(p, 0, 12));
+    null_ptr = reinterpret_cast<const pi_char_t*> (memchr(p, 0, 12));
     if (null_ptr)
         password = std::string((char *) p, null_ptr - p);
     else
