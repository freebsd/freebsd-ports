--- src/mozilla/ContentHandler.cpp.orig	Sat Apr 12 16:37:06 2003
+++ src/mozilla/ContentHandler.cpp	Sat Apr 12 16:38:54 2003
@@ -364,9 +364,9 @@
 	nsCOMPtr<nsIFilePicker> aFilePicker =
 				do_CreateInstance (G_FILEPICKER_CONTRACTID);
 
-	NS_NAMED_LITERAL_STRING (title, _("Select the destination filename"));
+	NS_NAMED_LITERAL_CSTRING (title, _("Select the destination filename"));
 
-	aFilePicker->Init (aWindowInternal, title.get(), 
+	aFilePicker->Init (aWindowInternal, PromiseFlatString(NS_ConvertUTF8toUCS2(title)).get(),
 			   nsIFilePicker::modeSave);
 	aFilePicker->SetDefaultString (aDefaultFile);
 	aFilePicker->SetDisplayDirectory (saveDir);
