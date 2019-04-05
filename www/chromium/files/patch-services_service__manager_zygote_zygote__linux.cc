--- services/service_manager/zygote/zygote_linux.cc.orig	2019-03-11 22:01:02 UTC
+++ services/service_manager/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "services/service_manager/zygote/zygote_linux.h"
 
@@ -664,3 +665,4 @@ bool Zygote::HandleGetSandboxStatus(int fd, base::Pick
 }
 
 }  // namespace service_manager
+#endif
