--- src/cxx/ncvalues.cpp.orig	Mon Sep 16 16:28:57 2002
+++ src/cxx/ncvalues.cpp	Mon Sep 16 16:29:42 2002
@@ -310,7 +310,7 @@
       os << the_values[i] << ", ";
     if (the_number > 0)
       os << the_values[the_number-1] ;
-    os.flags(save);
+    os.flags(std::_Ios_Fmtflags(save));
     return os;
 }
 
@@ -322,6 +322,6 @@
       os << the_values[i] << ", ";
     if (the_number > 0)
       os << the_values[the_number-1];
-    os.flags(save);
+    os.flags(std::_Ios_Fmtflags(save));
     return os;
 }
