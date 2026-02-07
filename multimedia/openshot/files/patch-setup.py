--- setup.py.orig	2024-12-22 02:37:46 UTC
+++ setup.py
@@ -29,8 +29,8 @@ import os
 import sys
 import fnmatch
 import subprocess
-from setuptools import setup
-from shutil import copytree, rmtree, copy
+from setuptools import setup, find_namespace_packages
+from shutil import copytree, rmtree, copy, move
 
 
 # Determine absolute PATH of OpenShot folder
@@ -38,9 +38,12 @@ PATH = os.path.dirname(os.path.realpath(__file__))  # 
 
 # Make a copy of the src tree (temporary for naming reasons only)
 if os.path.exists(os.path.join(PATH, "src")):
-    print("Copying modules to openshot_qt directory: %s" % os.path.join(PATH, "openshot_qt"))
-    # Only make a copy if the SRC directory is present (otherwise ignore this)
-    copytree(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt"))
+#    print("Copying modules to openshot_qt directory: %s" % os.path.join(PATH, "openshot_qt"))
+#    # Only make a copy if the SRC directory is present (otherwise ignore this)
+#    copytree(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt"))
+	print("Move for switching to flat-layout: %s -> %s" %
+		(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt")))
+	move(os.path.join(PATH, "src"), os.path.join(PATH, "openshot_qt"))
 
 if os.path.exists(os.path.join(PATH, "openshot_qt")):
     # Append path to system path
@@ -68,7 +71,7 @@ os_files = [
     # AppStream metadata
     ('share/metainfo', ['xdg/org.openshot.OpenShot.appdata.xml']),
     # Debian menu system application icon
-    ('share/pixmaps', ['xdg/openshot-qt.svg']),
+    ('share/pixmaps', ['xdg/icon/64/openshot-qt.png']),
     # XDG Freedesktop icon paths
     ('share/icons/hicolor/scalable/apps', ['xdg/openshot-qt.svg']),
     ('share/icons/hicolor/scalable/mimetypes', ['xdg/openshot-qt-doc.svg']),
@@ -79,7 +82,7 @@ os_files = [
     # XDG desktop mime types cache
     ('share/mime/packages', ['xdg/org.openshot.OpenShot.xml']),
     # launcher (mime.types)
-    ('lib/mime/packages', ['xdg/openshot-qt']),
+    #('lib/mime/packages', ['xdg/openshot-qt']),
 ]
 
 # Find files matching patterns
@@ -97,20 +100,35 @@ def find_files(directory, patterns):
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
+	packages=find_namespace_packages(
+		where=".",	# default
+		exclude=[
+			"build", "build.*",
+			"doc", "doc.*",
+			"images", "images.*",
+			"installer", "installer.*",
+			"src", "src.*",
+			"xdg", "xdg.*",
+			],	# for flat-layout
+		),
+	data_files=os_files,
+	include_package_data=True,
+	**info.SETUP)
 # -------------------------------------
 
 # Remove temporary folder (if SRC folder present)
@@ -122,22 +140,28 @@ FAILED = 'Failed to update.\n'
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
