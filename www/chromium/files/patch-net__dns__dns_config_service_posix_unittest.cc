--- ./net/dns/dns_config_service_posix_unittest.cc.orig	2014-08-12 21:02:40.000000000 +0200
+++ ./net/dns/dns_config_service_posix_unittest.cc	2014-08-13 09:56:57.000000000 +0200
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include "base/sys_byteorder.h"
 #include "net/dns/dns_config_service_posix.h"
 
