--- python/setup.py.orig	Thu Mar  4 05:28:18 2004
+++ python/setup.py	Thu Mar  4 05:29:35 2004
@@ -57,6 +57,9 @@
     if lib[0:2] == "-L":
         library_dirs.append(lib[2:])
         continue
+    if lib[0:2] == "-W":
+	# Skip linker flags
+	continue
     print "Unknown entry '%s' in $LIBS variable passed to setup.py" % lib
     sys.exit(1)
 
