--- content/zygote/zygote_linux.cc.orig	2022-12-02 17:56:32 UTC
+++ content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -696,3 +697,4 @@ void Zygote::HandleReinitializeLoggingRequest(base::Pi
 }
 
 }  // namespace content
+#endif
