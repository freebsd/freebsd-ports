--- installp.py.orig	1999-02-03 21:59:11.000000000 -0700
+++ installp.py	2014-05-29 09:23:31.000000000 -0700
@@ -14,17 +14,22 @@
         print "Usage: %s [-f] pymodule [npymodule...]" % sys.argv[0]
         sys.exit(1)
     for opt in opts:
-        if opt == '-f': FORCE = 1
+        if opt[0] == '-f': FORCE = 1
 
     v = sys.version[:3]
 
+    try:
+        destdir = os.environ['DESTDIR']
+    except KeyError:
+        destdir = ""
+
     if string.atof(v) >= 1.5:
-        sp = "%s/lib/python%s/site-packages" % (sys.prefix, v)
+        sp = "%s%s/lib/python%s/site-packages" % (destdir, sys.prefix, v)
         if not os.path.exists(sp):
-            os.mkdir(sp)
+            os.makedirs(sp)
     else:
         print "looks like Python is older than 1.5"
-        sp = "%s/lib/python%s" % (sys.prefix, v)
+        sp = "%s%s/lib/python%s" % (destdir, sys.prefix, v)
 
     if not FORCE:
         ans = raw_input("Install Python modules into %s? [y] " % sp)
