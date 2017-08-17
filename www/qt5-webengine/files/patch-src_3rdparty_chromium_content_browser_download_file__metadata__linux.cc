--- src/3rdparty/chromium/content/browser/download/file_metadata_linux.cc.orig	2017-04-20 13:00:41 UTC
+++ src/3rdparty/chromium/content/browser/download/file_metadata_linux.cc
@@ -6,7 +6,7 @@
 
 #include <stddef.h>
 #include <sys/types.h>
-#include <sys/xattr.h>
+#include <sys/extattr.h>
 
 #include "base/files/file_path.h"
 #include "base/files/file_util.h"
@@ -21,7 +21,7 @@ const char kReferrerURLAttrName[] = "use
 static void SetExtendedFileAttribute(const char* path, const char* name,
                                      const char* value, size_t value_size,
                                      int flags) {
-  int result = setxattr(path, name, value, value_size, flags);
+  int result = extattr_set_file(path, EXTATTR_NAMESPACE_USER, name, value, value_size);
   if (result) {
     DPLOG(ERROR)
         << "Could not set extended attribute " << name << " on file " << path;
