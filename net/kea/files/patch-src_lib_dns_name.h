--- src/lib/dns/name.h.orig	2024-07-25 08:50:58 UTC
+++ src/lib/dns/name.h
@@ -228,7 +228,7 @@ class Name { (private)
     //@{
 private:
     /// \brief Name data string
-    typedef std::basic_string<uint8_t> NameString;
+    typedef std::vector<uint8_t> NameString;
     /// \brief Name offsets type
     typedef std::vector<uint8_t> NameOffsets;
 
