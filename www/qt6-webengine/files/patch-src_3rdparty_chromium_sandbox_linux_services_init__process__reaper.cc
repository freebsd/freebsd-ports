--- src/3rdparty/chromium/sandbox/linux/services/init_process_reaper.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/sandbox/linux/services/init_process_reaper.cc
@@ -2,6 +2,7 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
+#if 0
 #include "sandbox/linux/services/init_process_reaper.h"
 
 #include <signal.h>
@@ -100,3 +101,4 @@ bool CreateInitProcessReaper(base::OnceClosure post_fo
 }
 
 }  // namespace sandbox.
+#endif
