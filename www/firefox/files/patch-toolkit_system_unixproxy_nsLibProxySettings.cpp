--- toolkit/system/unixproxy/nsLibProxySettings.cpp.orig	2015-10-29 22:18:00 UTC
+++ toolkit/system/unixproxy/nsLibProxySettings.cpp
@@ -9,6 +9,7 @@
 #include "nsIURI.h"
 #include "nsString.h"
 #include "nsCOMPtr.h"
+#include "nsNetCID.h"
 #include "nspr.h"
 
 extern "C" {
