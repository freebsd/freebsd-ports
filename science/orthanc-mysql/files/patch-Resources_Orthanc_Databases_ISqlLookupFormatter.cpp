--- Resources/Orthanc/Databases/ISqlLookupFormatter.cpp.orig	2021-07-22 18:16:30 UTC
+++ Resources/Orthanc/Databases/ISqlLookupFormatter.cpp
@@ -37,6 +37,7 @@
 
 #include "DatabaseConstraint.h"
 
+#include <cassert>
 #include <boost/lexical_cast.hpp>
 
 
