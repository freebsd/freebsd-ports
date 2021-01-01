--- tracdownloads/consoleadmin.py.orig	2011-04-07 08:36:09 UTC
+++ tracdownloads/consoleadmin.py
@@ -122,7 +122,8 @@ class DownloadsConsoleAdmin(Component):
         self.log.debug(download)
 
         # Upload file to DB and file storage.
-        api.store_download(context, download, file)
+        api._add_download(context, download, file)
+
 
         # Close input file and commit changes in DB.
         file.close()
