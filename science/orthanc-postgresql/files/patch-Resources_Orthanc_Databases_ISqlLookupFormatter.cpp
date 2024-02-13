--- Resources/Orthanc/Databases/ISqlLookupFormatter.cpp.orig	2021-04-22 15:22:26 UTC
+++ Resources/Orthanc/Databases/ISqlLookupFormatter.cpp
@@ -49,6 +49,7 @@
 
 #include "DatabaseConstraint.h"
 
+#include <cassert>
 #include <boost/lexical_cast.hpp>
 
 
