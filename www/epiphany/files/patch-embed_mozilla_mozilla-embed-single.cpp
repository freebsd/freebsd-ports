--- embed/mozilla/mozilla-embed-single.cpp.orig	Thu Dec 11 14:58:19 2003
+++ embed/mozilla/mozilla-embed-single.cpp	Thu Dec 11 14:58:27 2003
@@ -385,7 +385,7 @@
 		return NS_ERROR_FAILURE;
 	}
 
-#if MOZILLA_SNAPSHOT >= 12
+#if MOZILLA_SNAPSHOT > 12
 	result = localeService->GetLocaleComponentForUserAgent (aUILang);
 #else
 	nsXPIDLString uiLang;
