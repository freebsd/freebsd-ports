--- scribus/gtdialogs.cpp.orig	2018-12-15 16:52:02 UTC
+++ scribus/gtdialogs.cpp
@@ -160,7 +160,7 @@ bool gtDialogs::runImporterDialog(const QStringList& i
 	if (imp != "false")
 	{
 		res = imp;
-		if (importers.contains(res) > 0)
+		if (importers.contains(res))
 			ok = true;
 	}
 	
