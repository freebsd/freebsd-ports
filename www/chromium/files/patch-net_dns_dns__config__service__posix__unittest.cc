--- net/dns/dns_config_service_posix_unittest.cc.orig	2016-05-11 19:02:24 UTC
+++ net/dns/dns_config_service_posix_unittest.cc
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include "base/cancelable_callback.h"
 #include "base/files/file_util.h"
 #include "base/sys_byteorder.h"
