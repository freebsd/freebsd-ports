--- offlineimap/imapserver.py.orig	2022-02-27 05:55:01 UTC
+++ offlineimap/imapserver.py
@@ -879,7 +879,7 @@ class IdleThread:
             while not success:
                 imapobj = self.parent.acquireconnection()
                 try:
-                    imapobj.select(self.folder)
+                    imapobj.select(imaputil.foldername_to_imapname(self.folder))
                 except OfflineImapError as e:
                     if e.severity == OfflineImapError.ERROR.FOLDER_RETRY:
                         # Connection closed, release connection and retry.
