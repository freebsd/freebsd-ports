--- snmp++/classes/include/snmp++/oid.h.orig	Fri Aug 29 20:00:24 2003
+++ snmp++/classes/include/snmp++/oid.h	Fri Aug 29 20:00:41 2003
@@ -57,6 +57,7 @@
 #include <string.h>               // strlen, etc..
 }
 
+using namespace std;
 #include <vector>
 
 #include "smival.h"                // derived class for all values
