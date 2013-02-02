--- ./deluge/core/torrent.py.orig	2012-04-10 05:53:16.000000000 +0400
+++ ./deluge/core/torrent.py	2013-02-02 13:09:08.000000000 +0400
@@ -837,22 +837,30 @@
         # Attempt to convert utf8 path to unicode
         # Note: Inconsistent encoding for 'dest', needs future investigation
         try:
-           dest_u = unicode(dest, "utf-8")
+           dest = unicode(dest, "utf-8")
         except TypeError:
            # String is already unicode
-           dest_u = dest
+           pass
 
-        if not os.path.exists(dest_u):
+        if not os.path.exists(dest):
             try:
                 # Try to make the destination path if it doesn't exist
-                os.makedirs(dest_u)
+                os.makedirs(dest)
             except IOError, e:
                 log.exception(e)
-                log.error("Could not move storage for torrent %s since %s does not exist and could not create the directory.", self.torrent_id, dest_u)
+                log.error("Could not move storage for torrent %s since %s does not exist and could not create the directory.", self.torrent_id, dest)
                 return False
+
+        dest_bytes = dest.encode('utf-8')
+
         try:
-            self.handle.move_storage(dest_u)
-        except:
+            # libtorrent needs unicode object if wstrings are enabled, utf8 bytestring otherwise
+            try:
+                self.handle.move_storage(dest)
+            except TypeError:
+                self.handle.move_storage(dest_bytes)
+        except Exception, e:
+            log.error("Error calling libtorrent move_storage: %s" % e)
             return False
 
         return True
@@ -928,8 +936,18 @@
         """Renames files in the torrent. 'filenames' should be a list of
         (index, filename) pairs."""
         for index, filename in filenames:
+            # Make sure filename is a unicode object
+            try:
+                filename = unicode(filename, "utf-8")
+            except TypeError:
+                pass
             filename = sanitize_filepath(filename)
-            self.handle.rename_file(index, filename.encode("utf-8"))
+            # libtorrent needs unicode object if wstrings are enabled, utf8 bytestring otherwise
+            try:
+                self.handle.rename_file(index, filename)
+            except TypeError:
+                self.handle.rename_file(index, filename.encode("utf-8"))
+
 
     def rename_folder(self, folder, new_folder):
         """Renames a folder within a torrent.  This basically does a file rename
