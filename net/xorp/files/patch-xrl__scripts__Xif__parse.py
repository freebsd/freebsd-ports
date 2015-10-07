--- xrl/scripts/Xif/parse.py.orig	2012-01-11 17:56:10 UTC
+++ xrl/scripts/Xif/parse.py
@@ -71,8 +71,10 @@ def parse_cpp_hash(line):
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
 
