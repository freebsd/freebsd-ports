--- net/dns/dns_config_service_posix_unittest.cc.orig	2019-03-11 22:01:01 UTC
+++ net/dns/dns_config_service_posix_unittest.cc
@@ -2,8 +2,6 @@
 // Use of this source code is governed by a BSD-style license that can be
 // found in the LICENSE file.
 
-#include <resolv.h>
-
 #include <memory>
 
 #include "base/cancelable_callback.h"
@@ -46,7 +44,7 @@ const char* const kNameserversIPv4[] = {
     "1.0.0.1",
 };
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const char* const kNameserversIPv6[] = {
     NULL,
     "2001:DB8:0::42",
@@ -82,7 +80,7 @@ void InitializeResState(res_state res) {
     ++res->nscount;
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   // Install IPv6 addresses, replacing the corresponding IPv4 addresses.
   unsigned nscount6 = 0;
   for (unsigned i = 0; i < base::size(kNameserversIPv6) && i < MAXNS; ++i) {
@@ -103,7 +101,7 @@ void InitializeResState(res_state res) {
 }
 
 void CloseResState(res_state res) {
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   for (int i = 0; i < res->nscount; ++i) {
     if (res->_u._ext.nsaddrs[i] != NULL)
       free(res->_u._ext.nsaddrs[i]);
@@ -128,7 +126,7 @@ void InitializeExpectedConfig(DnsConfig* config) {
     config->nameservers.push_back(IPEndPoint(ip, NS_DEFAULTPORT + i));
   }
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   for (unsigned i = 0; i < base::size(kNameserversIPv6) && i < MAXNS; ++i) {
     if (!kNameserversIPv6[i])
       continue;
