--- ./libgnomecups/snmpkit/structfill.C.orig	2014-08-17 11:53:38.000000000 -0400
+++ ./libgnomecups/snmpkit/structfill.C	2014-08-17 11:55:45.000000000 -0400
@@ -28,7 +28,7 @@
 #include <string.h>
 #include <stdlib.h>
 #include <stdio.h>
-#include <iostream.h>
+#include <iostream>
 #include <algorithm>
 
 #include "snmpkit"
@@ -91,22 +91,22 @@
 	 counters or large ints */
       if(curber->type()==INT_TAG && cur->type==COUNTER_TAG)
 	// these errors are minor enough and simple enough to fix
-	cerr << "Warning: Counter returned when Integer expected for " 
+	std::cerr << "Warning: Counter returned when Integer expected for " 
 	     << cur->oidstr << " Buggy firmware?\n";
       else if(curber->type()==COUNTER_TAG && cur->type==INT_TAG)
 	// these errors are minor enough and simple enough to fix
-	cerr << "Warning: Integer returned when Counter expected for "
+	std::cerr << "Warning: Integer returned when Counter expected for "
 	     << cur->oidstr << " Buggy firmware?\n";
       else{
-	ios::fmtflags opts=ios::hex;
-	opts=cerr.flags(opts);
-	cerr << "Warning: Printer returned a value of type 0x"
+	std::ios::fmtflags opts=std::ios::hex;
+	opts=std::cerr.flags(opts);
+	std::cerr << "Warning: Printer returned a value of type 1x"
 	     << static_cast<long unsigned int>(curber->type()) 
 	     << " when a value of 0x" 
 	     << static_cast<long unsigned int>(cur->type)
 	     << " was expected for " << cur->oidstr 
 	     << " Buggy firmware? Skipping.\n";
-	cerr.flags(opts);
+	std::cerr.flags(opts);
 	retval=0;
 	break;
       }
@@ -177,7 +177,7 @@
     throw SNMPNoResponseException();
 
   if(!fillStruct(retseq,(unsigned char*)tobefilled)){
-    cerr << "Warning: printer did not respond with a value for one of the "
+    std::cerr << "Warning: printer did not respond with a value for one of the "
 	 << "OIDs. Buggy firmware?\n";
     return NULL;
   }
