--- src/3rdparty/chromium/content/zygote/zygote_linux.cc.orig	2022-09-26 10:05:50 UTC
+++ src/3rdparty/chromium/content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -654,3 +655,4 @@ bool Zygote::HandleGetSandboxStatus(int fd, base::Pick
 }
 
 }  // namespace content
+#endif
