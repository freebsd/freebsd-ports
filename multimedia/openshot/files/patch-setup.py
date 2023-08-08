--- setup.py.orig	2023-04-01 07:04:04 UTC
+++ setup.py
@@ -68,7 +68,7 @@ os_files = [
     # AppStream metadata
     ('share/metainfo', ['xdg/org.openshot.OpenShot.appdata.xml']),
     # Debian menu system application icon
-    ('share/pixmaps', ['xdg/openshot-qt.svg']),
+    ('share/pixmaps', ['xdg/icon/64/openshot-qt.png']),
     # XDG Freedesktop icon paths
     ('share/icons/hicolor/scalable/apps', ['xdg/openshot-qt.svg']),
     ('share/icons/hicolor/scalable/mimetypes', ['xdg/openshot-qt-doc.svg']),
@@ -79,7 +79,7 @@ os_files = [
     # XDG desktop mime types cache
     ('share/mime/packages', ['xdg/org.openshot.OpenShot.xml']),
     # launcher (mime.types)
-    ('lib/mime/packages', ['xdg/openshot-qt']),
+    #('lib/mime/packages', ['xdg/openshot-qt']),
 ]
 
 # Find files matching patterns
@@ -122,22 +122,28 @@ FAILED = 'Failed to update.\n'
 if ROOT and dist != None:
     # update the XDG Shared MIME-Info database cache
     try:
-        sys.stdout.write('Updating the Shared MIME-Info database cache.\n')
-        subprocess.call(["update-mime-database", os.path.join(sys.prefix, "share/mime/")])
+        # It would be executed with a pkg trigger of USES=shared-mime-info
+        #sys.stdout.write('Updating the Shared MIME-Info database cache.\n')
+        #subprocess.call(["update-mime-database", os.path.join(sys.prefix, "share/mime/")])
+        pass
     except:
         sys.stderr.write(FAILED)
 
     # update the mime.types database
     try:
-        sys.stdout.write('Updating the mime.types database\n')
-        subprocess.call("update-mime")
+        # It is provided by mime-support:misc/mime-support but not installed
+        #sys.stdout.write('Updating the mime.types database\n')
+        #subprocess.call("update-mime")
+        pass
     except:
         sys.stderr.write(FAILED)
 
     # update the XDG .desktop file database
     try:
-        sys.stdout.write('Updating the .desktop file database.\n')
-        subprocess.call(["update-desktop-database"])
+        # It would be executed with a pkg trigger of USES=desktop-file-utils
+        #sys.stdout.write('Updating the .desktop file database.\n')
+        #subprocess.call(["update-desktop-database"])
+        pass
     except:
         sys.stderr.write(FAILED)
     sys.stdout.write("\n-----------------------------------------------")
