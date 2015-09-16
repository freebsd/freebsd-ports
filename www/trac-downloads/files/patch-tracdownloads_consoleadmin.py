--- tracdownloads/consoleadmin.py.orig
+++ tracdownloads/consoleadmin.py
@@ -122,7 +122,8 @@
         self.log.debug(download)
 
         # Upload file to DB and file storage.
-        api.store_download(context, download, file)
+        api._add_download(context, download, file)
+
 
         # Close input file and commit changes in DB.
         file.close()
