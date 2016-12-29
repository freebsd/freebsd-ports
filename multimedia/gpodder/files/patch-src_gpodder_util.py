--- src/gpodder/util.py.orig	2016-12-22 13:48:52 UTC
+++ src/gpodder/util.py
@@ -1833,7 +1833,7 @@ def unix_get_active_interfaces():
     process = subprocess.Popen(['ifconfig'], stdout=subprocess.PIPE)
     stdout, _ = process.communicate()
     for i in re.split('\n(?!\t)', stdout, re.MULTILINE):
-        b = re.match('(\\w+):.*status: active$', i, re.MULTILINE | re.DOTALL)
+        b = re.match('(\\w+):.*status: (active|associated)$', i, re.MULTILINE | re.DOTALL)
         if b:
             yield b.group(1)
 
