https://bugs.launchpad.net/ssm/+bug/1780908

--- superpose.cpp.orig	2018-07-10 06:15:41 UTC
+++ superpose.cpp
@@ -114,7 +114,7 @@ void printInstructions ( char *argv0 )  
 #endif
     " Protein Structure Superposition\n"
     " -------------------------------\n"
-    " v."superpose_version" from "superpose_date" built with SSM v.%i.%i.%i, "
+    " v." superpose_version " from " superpose_date " built with SSM v.%i.%i.%i, "
     "MMDB v.%i.%i.%i\n"
     "\n"
     " USAGE:\n"
