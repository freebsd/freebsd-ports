--- mozilla/ContentHandler.cpp.orig	Fri Feb 21 00:06:59 2003
+++ mozilla/ContentHandler.cpp	Fri Feb 21 00:04:32 2003
@@ -427,11 +427,11 @@
 
 NS_METHOD GContentHandler::FindHelperApp (void)
 {
-	if (mUrlHelper)
-	{
+//	if (mUrlHelper)
+//	{
 		return LaunchHelperApp ();
-	}
-	else
+//	}
+/*	else
 	{
 		if (NS_SUCCEEDED(SynchroniseMIMEInfo()))
 		{
@@ -441,7 +441,7 @@
 		{
 				return NS_ERROR_FAILURE;
 		}
-	}
+	}*/
 }
 
 NS_METHOD GContentHandler::LaunchHelperApp (void)
