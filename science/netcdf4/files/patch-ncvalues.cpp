--- cxx/ncvalues.cpp.orig	Tue Dec 22 19:21:49 1998
+++ cxx/ncvalues.cpp	Sat Feb  7 13:34:17 2004
@@ -7,7 +7,6 @@
  *   $Header: /upc/share/CVS/netcdf-3/cxx/ncvalues.cpp,v 1.3 1998/12/22 18:21:49 russ Exp $
  *********************************************************************/
 
-#include <iostream.h>		// for debugging
 #include "ncvalues.h"
 
 NcValues::NcValues( void ) : the_number(0), the_type(ncNoType)
@@ -310,7 +309,11 @@
       os << the_values[i] << ", ";
     if (the_number > 0)
       os << the_values[the_number-1] ;
+#if (__GNUC__ == 2)
     os.flags(save);
+#else
+    os.flags(std::_Ios_Fmtflags(save));
+#endif
     return os;
 }
 
@@ -322,6 +325,10 @@
       os << the_values[i] << ", ";
     if (the_number > 0)
       os << the_values[the_number-1];
+#if (__GNUC__ == 2)
     os.flags(save);
+#else
+    os.flags(std::_Ios_Fmtflags(save));
+#endif
     return os;
 }
