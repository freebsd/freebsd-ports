--- src/io/NCHelper.cpp.orig	2018-11-05 01:48:41 UTC
+++ src/io/NCHelper.cpp
@@ -714,7 +714,7 @@ ErrorCode NCHelper::get_tag_to_set(ReadN
       rval = mbImpl->tag_get_handle(tag_name.str().c_str(), 0, MB_TYPE_INTEGER, tagh, MB_TAG_CREAT | MB_TAG_SPARSE | MB_TAG_VARLEN);
       break;
     default:
-      std::cerr << "Unrecognized data type for tag " << tag_name << std::endl;
+      std::cerr << "Unrecognized data type for tag " << tag_name.str() << std::endl;
       rval = MB_FAILURE;
   }
 
