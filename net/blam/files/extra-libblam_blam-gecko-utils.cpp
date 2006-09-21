--- libblam/blam-gecko-utils.cpp.orig	Fri May  6 04:07:49 2005
+++ libblam/blam-gecko-utils.cpp	Wed Sep 20 19:15:58 2006
@@ -29,6 +29,8 @@
 #include <nsEmbedString.h>
 #include <nsIPrefService.h>
 #include <nsIServiceManager.h>
+#include <nsServiceManagerUtils.h>
+#include <nsCOMPtr.h>
 
 #if defined (HAVE_CHROME_NSICHROMEREGISTRYSEA_H)
 #include <chrome/nsIChromeRegistrySea.h>
