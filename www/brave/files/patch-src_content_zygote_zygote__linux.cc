--- src/content/zygote/zygote_linux.cc.orig	2026-10-18 18:43:23 UTC
+++ src/content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -707,3 +708,4 @@ void Zygote::HandleReinitializeLoggingRe
 }
 
 }  // namespace content
+#endif
