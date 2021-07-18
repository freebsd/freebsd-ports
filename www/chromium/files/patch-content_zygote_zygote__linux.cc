--- content/zygote/zygote_linux.cc.orig	2021-04-14 18:41:03 UTC
+++ content/zygote/zygote_linux.cc
@@ -1,7 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
-
+#if 0
 #include "content/zygote/zygote_linux.h"
 
 #include <errno.h>
@@ -651,3 +651,4 @@ bool Zygote::HandleGetSandboxStatus(int fd, base::Pick
 }
 
 }  // namespace content
+#endif
