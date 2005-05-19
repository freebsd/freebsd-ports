
$FreeBSD$

--- portell.py.orig
+++ portell.py
@@ -14,12 +14,16 @@
     PORTELL_DB = "/var/db/portell.db"
 
 PORTS_DIR = "/usr/ports/"
-
+IGNORE_DIRS = { "distfiles":None, "Tools":None, "packages":None }
 
 def write_pathname(d, dirname, names):
-    '/'.join(dirname.split('/')[:5]) # chop port path subdirs
-    d[os.path.basename(dirname)] = dirname
-
+	dirs=dirname.split('/')
+	if len(dirs)==4:
+	    if IGNORE_DIRS.has_key(dirs[3]):
+		del names[:]
+	elif len(dirs)==5:
+	    d[dirs[4]] = dirname
+	    del names[:]
 
 def update_db(msg):
     print msg
