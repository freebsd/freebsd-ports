--- testsuite/libdejagnu/unit.cc.orig	Thu May  3 22:25:59 2001
+++ testsuite/libdejagnu/unit.cc	Mon Jul 16 16:17:05 2001
@@ -1,5 +1,6 @@
 // unit.cc -- This is a test case for the Dejagnu.h classes.
 
+#include <sys/types.h>
 #include <iostream>
 #include <dejagnu.h>
 
@@ -7,7 +8,6 @@
 #include <string>
 #include <fstream>
 #include <set>
-#include <sys/types.h>
 
 TestState runtest;
 TestState test;
