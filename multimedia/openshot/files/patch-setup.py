--- setup.py.orig	2019-11-11 07:57:57 UTC
+++ setup.py
@@ -68,7 +68,7 @@ os_files = [
     # AppStream metadata
     ('share/metainfo', ['xdg/org.openshot.OpenShot.appdata.xml']),
     # Debian menu system application icon
-    ('share/pixmaps', ['xdg/openshot-qt.svg']),
+    ('share/pixmaps', ['xdg/icon/64/openshot-qt.png']),
     # XDG Freedesktop icon paths
     ('share/icons/hicolor/scalable/apps', ['xdg/openshot-qt.svg']),
     ('share/icons/hicolor/64x64/apps', ['xdg/icon/64/openshot-qt.png']),
@@ -77,7 +77,7 @@ os_files = [
     # XDG desktop mime types cache
     ('share/mime/packages', ['xdg/org.openshot.OpenShot.xml']),
     # launcher (mime.types)
-    ('lib/mime/packages', ['xdg/openshot-qt']),
+    #('lib/mime/packages', ['xdg/openshot-qt']),
 ]
 
 # Find files matching patterns
@@ -118,26 +118,6 @@ if os.path.exists(os.path.join(PATH, "src")):
 FAILED = 'Failed to update.\n'
 
 if ROOT and dist != None:
-    # update the XDG Shared MIME-Info database cache
-    try:
-        sys.stdout.write('Updating the Shared MIME-Info database cache.\n')
-        subprocess.call(["update-mime-database", os.path.join(sys.prefix, "share/mime/")])
-    except:
-        sys.stderr.write(FAILED)
-
-    # update the mime.types database
-    try:
-        sys.stdout.write('Updating the mime.types database\n')
-        subprocess.call("update-mime")
-    except:
-        sys.stderr.write(FAILED)
-
-    # update the XDG .desktop file database
-    try:
-        sys.stdout.write('Updating the .desktop file database.\n')
-        subprocess.call(["update-desktop-database"])
-    except:
-        sys.stderr.write(FAILED)
     sys.stdout.write("\n-----------------------------------------------")
     sys.stdout.write("\nInstallation Finished!")
     sys.stdout.write("\nRun OpenShot by typing 'openshot-qt' or through the Applications menu.")
