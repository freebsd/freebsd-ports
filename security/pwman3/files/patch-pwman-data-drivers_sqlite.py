--- pwman/data/drivers/sqlite.py.orig	2007-02-04 21:44:43.000000000 +0300
+++ pwman/data/drivers/sqlite.py	2011-08-29 21:02:34.000000000 +0400
@@ -22,7 +22,7 @@
 from pwman.data.nodes import Node
 from pwman.data.tags import Tag
 
-from pysqlite2 import dbapi2 as sqlite
+from sqlite3 import dbapi2 as sqlite
 import pwman.util.config as config
 import cPickle
 
