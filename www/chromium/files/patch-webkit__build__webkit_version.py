--- webkit/build/webkit_version.py.orig	2011-03-15 05:46:26.000000000 +0200
+++ webkit/build/webkit_version.py	2011-03-15 05:52:33.000000000 +0200
@@ -45,21 +45,24 @@
 
   # "svn info" tells us what we want, but third_party/WebKit does *not*
   # point at the upstream repo.  So instead we run svn info on the directory
-  # containing the versioning file (which is some subdirectory of WebKit),
-  # then strip that path back off of the resulting URL.
+  # containing the versioning file (which is some subdirectory of WebKit).
   version_file_dir = os.path.dirname(version_file)
   version_info = lastchange.FetchVersionInfo(
       default_lastchange=None,
       directory=os.path.join(webkit_dir, version_file_dir))
 
-  # Now compute the real WebKit URL by stripping off the version file
-  # directory from the URL we get out of version_info.
-  # Further, we want to strip off the "http://svn..." from the left.
-  # This is the root URL from the repository.
-  assert version_info.url.startswith(version_info.root)
-  assert version_info.url.endswith(version_file_dir)
-  webkit_url = version_info.url[len(version_info.root):-len(version_file_dir)]
-  webkit_url = webkit_url.strip('/')
+  if (version_info.url.startswith(version_info.root) and
+      version_info.url.endswith(version_file_dir)):
+    # Now compute the real WebKit URL by stripping off the version file
+    # directory from the URL we get out of version_info.
+    # Further, we want to strip off the "http://svn..." from the left.
+    # This is the root URL from the repository.
+    webkit_url = version_info.url[len(version_info.root):-len(version_file_dir)]
+    webkit_url = webkit_url.strip('/')
+  else:
+    # The data isn't as we expect: perhaps they're using git without svn?
+    # Just dump the output directly.
+    webkit_url = version_info.url
 
   return "%s@%s" % (webkit_url, version_info.revision)
 
