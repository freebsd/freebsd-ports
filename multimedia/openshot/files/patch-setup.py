--- setup.py.orig	2026-08-27 04:54:17 UTC
+++ setup.py
@@ -29,7 +29,7 @@ import subprocess
 import sys
 import fnmatch
 import subprocess
-from setuptools import setup
+from setuptools import setup, find_namespace_packages
 from shutil import copytree, rmtree, copy
 
 
@@ -38,9 +38,12 @@ if os.path.exists(os.path.join(PATH, "src")):
 
 # Make a copy of the src tree (temporary for naming reasons only)
 if os.path.exists(os.path.join(PATH, "src")):
-    print("Copying modules to openshot_qt directory: %s" % os.path.join(PATH, "openshot_qt"))
-    # Only make a copy if the SRC directory is present (otherwise ignore this)
-    copytree(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt"))
+#    print("Copying modules to openshot_qt directory: %s" % os.path.join(PATH, "openshot_qt"))
+#    # Only make a copy if the SRC directory is present (otherwise ignore this)
+#    copytree(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt"))
+    # Append path to system path
+    sys.path.append(os.path.join(PATH, "src"))
+    print("Loaded modules from src directory: %s" % os.path.join(PATH, "src"))
 
 if os.path.exists(os.path.join(PATH, "openshot_qt")):
     # Append path to system path
@@ -53,6 +56,10 @@ log.info("Execution path: %s" % os.path.abspath(__file
 
 log.info("Execution path: %s" % os.path.abspath(__file__))
 
+# changes made to keep PORTNAME
+info.SETUP['name'] = 'openshot'
+info.SETUP['classifiers'] += ['Operating System :: POSIX :: BSD :: FreeBSD']
+
 # Boolean: running as root?
 ROOT = os.geteuid() == 0
 # For Debian packaging it could be a fakeroot so reset flag to prevent execution of
@@ -68,7 +75,7 @@ os_files = [
     # AppStream metadata
     ('share/metainfo', ['xdg/org.openshot.OpenShot.appdata.xml']),
     # Debian menu system application icon
-    ('share/pixmaps', ['xdg/openshot-qt.svg']),
+    ('share/pixmaps', ['xdg/icon/64/openshot-qt.png']),
     # XDG Freedesktop icon paths
     ('share/icons/hicolor/scalable/apps', ['xdg/openshot-qt.svg']),
     ('share/icons/hicolor/scalable/mimetypes', ['xdg/openshot-qt-doc.svg']),
@@ -79,7 +86,7 @@ os_files = [
     # XDG desktop mime types cache
     ('share/mime/packages', ['xdg/org.openshot.OpenShot.xml']),
     # launcher (mime.types)
-    ('lib/mime/packages', ['xdg/openshot-qt']),
+    #('lib/mime/packages', ['xdg/openshot-qt']),
 ]
 
 # Find files matching patterns
@@ -97,20 +104,30 @@ package_data = {}
 package_data = {}
 
 # Find all project files
-src_files = []
-for filename in find_files(os.path.join(PATH, "openshot_qt"), ["*"]):
-    src_files.append(filename.replace(os.path.join(PATH, "openshot_qt"), ""))
-package_data["openshot_qt"] = src_files
+#src_files = []
+#for filename in find_files(os.path.join(PATH, "openshot_qt"), ["*"]):
+#    src_files.append(filename.replace(os.path.join(PATH, "openshot_qt"), ""))
+#package_data["openshot_qt"] = src_files
 
 # Call the main Distutils setup command
 # -------------------------------------
+#dist = setup(
+#    packages=[('openshot_qt')],
+#    package_data=package_data,
+#    data_files=os_files,
+#    include_package_data=True,
+#    **info.SETUP
+#)
 dist = setup(
-    packages=[('openshot_qt')],
-    package_data=package_data,
-    data_files=os_files,
-    include_package_data=True,
-    **info.SETUP
-)
+    packages = ['openshot_qt'] +
+        ['openshot_qt.' + s for s in find_namespace_packages(where = 'src')],
+    package_dir = {
+        'openshot_qt': 'src',
+        '': 'src',
+        },
+    data_files = os_files,
+    include_package_data = True,
+    **info.SETUP)
 # -------------------------------------
 
 # Remove temporary folder (if SRC folder present)
@@ -122,22 +139,28 @@ if ROOT and dist != None:
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
