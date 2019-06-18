--- components/download/quarantine/quarantine_linux.cc.orig	2019-03-11 22:00:56 UTC
+++ components/download/quarantine/quarantine_linux.cc
@@ -2,11 +2,15 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#include "build/build_config.h"
+
 #include "components/download/quarantine/quarantine.h"
 
 #include <stddef.h>
 #include <sys/types.h>
+#if !defined(OS_BSD)
 #include <sys/xattr.h>
+#endif
 
 #include "base/files/file_path.h"
 #include "base/logging.h"
@@ -25,7 +29,7 @@ bool SetExtendedFileAttribute(const char* path,
                               int flags) {
 // On Chrome OS, there is no component that can validate these extended
 // attributes so there is no need to set them.
-#if !defined(OS_CHROMEOS)
+#if !defined(OS_CHROMEOS) && !defined(OS_BSD)
   base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
   int result = setxattr(path, name, value, value_size, flags);
   if (result) {
@@ -33,7 +37,7 @@ bool SetExtendedFileAttribute(const char* path,
                  << path;
     return false;
   }
-#endif  // !defined(OS_CHROMEOS)
+#endif  // !defined(OS_CHROMEOS) && !defined(OS_BSD)
   return true;
 }
 
