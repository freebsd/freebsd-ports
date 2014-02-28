--- ./xrl/scripts/Xif/parse.py.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./xrl/scripts/Xif/parse.py	2014-02-26 21:17:13.000000000 +0000
@@ -71,8 +71,10 @@
         pop_file()
         pop_file()
         push_file(file, line)
+    elif (flag == "3") or (flag == "4"):
+        print "Pre-processor #line flag (%s)" % flag
     else:
-        print "Invalid pre-processor #line flag (%d)\n", flag
+        print "Invalid pre-processor #line flag (%s)" % flag
         sys.exit(1)
     return 1
 
