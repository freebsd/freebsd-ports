--- content/zygote/zygote_linux.cc.orig	2018-08-16 15:29:57.557439000 +0200
+++ content/zygote/zygote_linux.cc	2018-08-16 15:30:18.097569000 +0200
@@ -1,6 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "content/zygote/zygote_linux.h"
 
@@ -666,3 +667,4 @@
 }
 
 }  // namespace content
+#endif
