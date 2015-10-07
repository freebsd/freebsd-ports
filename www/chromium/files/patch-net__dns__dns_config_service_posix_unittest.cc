--- net/dns/dns_config_service_posix_unittest.cc.orig	2015-07-15 16:30:05.000000000 -0400
+++ net/dns/dns_config_service_posix_unittest.cc	2015-07-22 07:45:57.034816000 -0400
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include "base/cancelable_callback.h"
 #include "base/files/file_util.h"
 #include "base/sys_byteorder.h"
