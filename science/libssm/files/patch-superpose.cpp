https://bugs.launchpad.net/ssm/+bug/1780908

--- superpose.cpp.orig	2015-10-05 00:41:45 UTC
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
@@ -295,7 +295,7 @@ int             argNo,i,nStructures,rc;
   }
 
   printf ( "\n"
-    " Superpose v."superpose_version" from "superpose_date" "
+    " Superpose v." superpose_version " from " superpose_date " "
                                         "(based on SSM algorithm)\n"
     " ---------------------------------------------------------\n\n"
    );
