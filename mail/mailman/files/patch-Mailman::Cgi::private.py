Index: Mailman/Cgi/private.py
===================================================================
RCS file: /cvsroot/mailman/mailman/Mailman/Cgi/private.py,v
retrieving revision 2.16.2.1
diff -u -r2.16.2.1 private.py
--- private.py	8 Feb 2003 07:13:50 -0000	2.16.2.1
+++ private.py	10 Feb 2005 03:34:21 -0000
@@ -1,4 +1,4 @@
-# Copyright (C) 1998-2003 by the Free Software Foundation, Inc.
+# Copyright (C) 1998-2005 by the Free Software Foundation, Inc.
 #
 # This program is free software; you can redistribute it and/or
 # modify it under the terms of the GNU General Public License
@@ -35,13 +35,17 @@
 _ = i18n._
 i18n.set_language(mm_cfg.DEFAULT_SERVER_LANGUAGE)
 
+SLASH = '/'
+
 
 
 def true_path(path):
     "Ensure that the path is safe by removing .."
-    path = path.replace('../', '')
-    path = path.replace('./', '')
-    return path[1:]
+    parts = path.split(SLASH)
+    safe = [x for x in parts if x not in ('.', '..')]
+    if parts <> safe:
+        syslog('mischief', 'Directory traversal attack thwarted')
+    return SLASH.join(safe)[1:]
 
 
 
