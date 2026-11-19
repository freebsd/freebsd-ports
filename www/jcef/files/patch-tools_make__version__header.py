--- tools/make_version_header.py.orig	2026-09-08 14:07:06 UTC
+++ tools/make_version_header.py
@@ -61,11 +61,11 @@ def write_svn_header(header):
   else:
     oldcontents = ''
 
-  if not git.is_checkout(jcef_dir):
-    raise Exception('Not a valid checkout')
+#  if not git.is_checkout(jcef_dir):
+#    raise Exception('Not a valid checkout')
 
-  commit_number = git.get_commit_number(jcef_dir)
-  commit_hash = git.get_hash(jcef_dir)
+  commit_number = "%%CI_NBR%%"
+  commit_hash = "%%CI_HASH%%"
 
   year = get_year()
 
