--- src/common/json.cpp.orig	2018-02-24 09:41:56 UTC
+++ src/common/json.cpp
@@ -96,7 +96,7 @@ strip_comments(nlohmann::json::string_t 
   } catch (mtx::mm_io::exception &) {
   }
 
-  return std::string{reinterpret_cast<char *>(out.get_buffer()), out.getFilePointer()};
+  return std::string{reinterpret_cast<char *>(out.get_buffer()), static_cast<std::string::size_type>(out.getFilePointer())};
 }
 
 }
