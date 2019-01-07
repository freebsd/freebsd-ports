--- components/download/quarantine/quarantine_linux.cc.orig	2018-12-03 21:16:48.000000000 +0100
+++ components/download/quarantine/quarantine_linux.cc	2018-12-13 18:59:24.718194000 +0100
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
@@ -24,12 +28,14 @@
                               size_t value_size,
                               int flags) {
   base::ScopedBlockingCall scoped_blocking_call(base::BlockingType::MAY_BLOCK);
+#if !defined(OS_BSD)
   int result = setxattr(path, name, value, value_size, flags);
   if (result) {
     DPLOG(ERROR) << "Could not set extended attribute " << name << " on file "
                  << path;
     return false;
   }
+#endif // defined(OS_BSD)
   return true;
 }
 
