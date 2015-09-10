--- portell.py.orig
+++ portell.py
@@ -6,7 +6,7 @@
 # Version: 0.2
 # Usage: portell.py <portname>
 
-import sys, os, shelve
+import sys, os, bsddb
 
 try:
     PORTELL_DB = os.environ['PORTELL_PATH']
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
@@ -30,7 +34,7 @@
         os.unlink(PORTELL_DB + ".db") 
         
     try:
-        d = shelve.open(PORTELL_DB)
+	d = bsddb.btopen(PORTELL_DB, 'c')
         fix_dbdb()
         os.chmod(PORTELL_DB, 0666) 
     except:
@@ -63,10 +67,10 @@
     else:
         portname = sys.argv[1]
 
-    d = shelve.open(PORTELL_DB)
+    d = bsddb.btopen(PORTELL_DB, 'r')
     fix_dbdb()
 
-    if d.has_key(portname): 
+    if d.has_key(portname):
         if os.uname()[0].lower() == "freebsd":
             descr_path = d[portname] + "/pkg-descr"
         else:
