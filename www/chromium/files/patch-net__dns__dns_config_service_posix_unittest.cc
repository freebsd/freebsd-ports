--- ./net/dns/dns_config_service_posix_unittest.cc.orig	2014-04-30 22:43:08.000000000 +0200
+++ ./net/dns/dns_config_service_posix_unittest.cc	2014-05-04 14:38:48.000000000 +0200
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include "base/sys_byteorder.h"
 #include "net/dns/dns_config_service_posix.h"
 
