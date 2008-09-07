--- talk/base/base64.h.orig	2008-09-06 23:14:08.000000000 -0300
+++ talk/base/base64.h	2008-09-06 23:14:50.000000000 -0300
@@ -23,8 +23,8 @@
   static std::string decode(const std::string & data);
   static std::string encodeFromArray(const char * data, size_t len);
 private:
-  static const std::string Base64::Base64Table;
-  static const std::string::size_type Base64::DecodeTable[];
+  static const std::string Base64Table;
+  static const std::string::size_type DecodeTable[];
 };
 
 } // namespace talk_base
