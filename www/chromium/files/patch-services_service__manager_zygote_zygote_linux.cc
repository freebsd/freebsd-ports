--- services/service_manager/zygote/zygote_linux.cc.orig	2018-08-04 19:15:10.269247000 +0200
+++ services/service_manager/zygote/zygote_linux.cc	2018-08-04 19:16:18.712635000 +0200
@@ -1,6 +1,7 @@
 // Copyright (c) 2012 The Chromium Authors. All rights reserved.
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
+#if 0
 
 #include "services/service_manager/zygote/zygote_linux.h"
 
@@ -664,3 +665,4 @@
 }
 
 }  // namespace service_manager
+#endif
