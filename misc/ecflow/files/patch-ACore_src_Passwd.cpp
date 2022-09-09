- fixes failure: error: use of undeclared identifier 'time' on FreeBSD 12
- This seems to be a general problem that this header isn't included.
- it's unclear how to report bugs: emails to Software.Software@ecmwf.int bounce, and linked JIRA account has no such project.

--- ACore/src/Passwd.cpp.orig	2022-09-04 16:37:50 UTC
+++ ACore/src/Passwd.cpp
@@ -13,6 +13,7 @@
 // Description :
 //============================================================================
 
+#include <time.h> // for time(3)
 #include <unistd.h>
 
 #include "Passwd.hpp"
