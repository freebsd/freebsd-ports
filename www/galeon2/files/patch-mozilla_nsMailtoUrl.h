--- mozilla/nsMailtoUrl.h.orig	Mon Apr  7 18:13:50 2003
+++ mozilla/nsMailtoUrl.h	Mon Apr  7 18:14:24 2003
@@ -43,8 +43,10 @@
 
 #include "nsIMailtoUrl.h"
 #include "nsIURI.h"
-#include "nsIFileSpec.h"
+#include "nsCRT.h"
 #include "nsCOMPtr.h"
+#include "nsString.h"
+#include "nsIComponentManager.h"
 #include "nsIPrompt.h"
 #include "nsIAuthPrompt.h"
 #include "nsIInterfaceRequestor.h"
