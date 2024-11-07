--- core/OOXML/XlsxFormat/Worksheets/SheetData.cpp.orig	2024-08-28 20:40:12 UTC
+++ core/OOXML/XlsxFormat/Worksheets/SheetData.cpp
@@ -72,6 +72,8 @@
 #include <boost/date_time/gregorian/gregorian.hpp>
 #include <boost/date_time/posix_time/posix_time.hpp>
 
+#include <cfloat>
+
 #ifndef MININT32
 #define MAXUINT32   ((uint32_t)~((uint32_t)0))
 #define MAXINT32    ((int32_t)(MAXUINT32 >> 1))
