--- sandbox/linux/services/init_process_reaper.cc.orig	2018-08-04 19:26:41.605247000 +0200
+++ sandbox/linux/services/init_process_reaper.cc	2018-08-04 19:27:02.769442000 +0200
@@ -1,6 +1,7 @@
 // Copyright 2013 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "sandbox/linux/services/init_process_reaper.h"
 
@@ -100,3 +101,4 @@
 }
 
 }  // namespace sandbox.
+#endif
