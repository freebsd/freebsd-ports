--- policy/common/element.hh.orig	2018-07-03 02:07:04 UTC
+++ policy/common/element.hh
@@ -24,6 +24,7 @@
 #define __POLICY_COMMON_ELEMENT_HH__
 
 
+#pragma clang diagnostic ignored "-Wundefined-var-template"
 
 #include "libxorp/ipv4.hh"
 #include "libxorp/ipv6.hh"

