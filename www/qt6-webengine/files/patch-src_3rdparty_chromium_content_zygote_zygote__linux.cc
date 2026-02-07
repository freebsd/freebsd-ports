--- src/3rdparty/chromium/content/zygote/zygote_linux.cc.orig	2025-08-15 18:30:00 UTC
+++ src/3rdparty/chromium/content/zygote/zygote_linux.cc
@@ -1,6 +1,7 @@
 // Copyright 2012 The Chromium Authors
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #ifdef UNSAFE_BUFFERS_BUILD
 // TODO(crbug.com/342213636): Remove this and spanify to fix the errors.
@@ -709,3 +710,4 @@ void Zygote::HandleReinitializeLoggingRequest(base::Pi
 }
 
 }  // namespace content
+#endif
