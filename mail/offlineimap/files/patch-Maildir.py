--- offlineimap/repository/Maildir.py.orig	Thu May  8 01:28:58 2003
+++ offlineimap/repository/Maildir.py	Thu May  8 01:29:22 2003
@@ -132,7 +132,7 @@
 
                 retval.append(folder.Maildir.MaildirFolder(self.root, foldername,
                                                            self.getsep(), self, self.accountname))
-            if self.getsep() == '/':
+            if self.getsep() == '/' and dirname != '.':
                 # Check sub-directories for folders.
                 retval.extend(self._getfolders_scandir(root, foldername))
         self.debug("_GETFOLDERS_SCANDIR RETURNING %s" % \
