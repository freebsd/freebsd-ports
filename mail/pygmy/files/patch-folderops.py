
$FreeBSD$

--- folderops.py	2001/05/04 21:59:28	1.1
+++ folderops.py	2001/05/04 22:14:52
@@ -295,7 +295,7 @@
 ##
 ##
 def create_folder_index(pathname, start=0):
-    import pygmymailbox, time, marshal, os, string, mimify
+    import pygmymailbox, time, marshal, os, string, mimify, rfc822
     from string import replace, join
     from posixpath import split
 
@@ -342,11 +342,11 @@
         subject = replace(subject, '\n', '')
         subject = replace(subject, '\r', '')
         # Get the Date: field
-        date = m.getdate('date') or ""
+        date = m.getdate_tz('date') or ""
         if date != "":
             # Convert to epoch value
             try:
-                date = time.mktime(date)
+                date = rfc822.mktime_tz(date)
             except:
                 date = time.time()
         else:
