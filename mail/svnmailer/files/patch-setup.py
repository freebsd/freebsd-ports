--- setup.py.orig	2005-09-25 22:47:47.000000000 +0400
+++ setup.py	2008-06-07 21:40:11.000000000 +0400
@@ -1,4 +1,4 @@
-#!/usr/bin/env python
+#!/usr/local/bin/python2.5
 # -*- coding: utf-8 -*-
 import os, sys
 
@@ -157,7 +157,7 @@
             moredocs.include_pattern(convre(r"docs/[^/]+"), is_regex = 1)
             moredocs.exclude_pattern(convre(r"docs/[^/]+.\d"), is_regex = 1)
             docs.extend(moredocs.files)
-            base = 'doc/svnmailer'
+            base = 'share/doc/svnmailer'
             self.data_files.append((base, docs))
 
             rre = re.escape('/') == '\\/'
@@ -171,15 +171,15 @@
                 apidocs.include_pattern(
                     convre('%s/[^/]+' % repath), is_regex = 1
                 )
-                base = 'doc/svnmailer/%s'% path
+                base = 'share/doc/svnmailer/%s'% path
                 self.data_files.append((base, apidocs.files))
 
             samples = fixfiles(SAMPLES)
-            base = 'doc/svnmailer/sample'
+            base = 'share/doc/svnmailer/sample'
             self.data_files.append((base, samples))
 
             hooks = HOOKS
-            base = 'doc/svnmailer/sample/hooks'
+            base = 'share/doc/svnmailer/sample/hooks'
             if win32:
                 hooks = ["%s.bat" % hook for hook in hooks]
                 scriptsdefault = "C:\\path\\to"
@@ -191,17 +191,17 @@
             })
             self.data_files.append((base, hooks))
 
+            # so late, because some files need to be touched in the tree
+            # anyway
+            if store.get('no-install-docs', False):
+                self.data_files = []
+
             # man pages only on *x
             if not win32:
                 for section, pages in MAN.items():
                     fixfiles(pages)
                     self.data_files.append(("man/man%s" % section, pages))
 
-            # so late, because some files need to be touched in the tree
-            # anyway
-            if store.get('no-install-docs', False):
-                self.data_files = []
-
 
     core.setup(
         name = "svnmailer",
