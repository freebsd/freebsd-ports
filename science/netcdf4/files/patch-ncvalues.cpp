--- cxx/ncvalues.cpp.orig	Wed Dec 23 02:21:49 1998
+++ cxx/ncvalues.cpp	Tue Oct  1 10:27:32 2002
@@ -310,7 +310,11 @@
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
 
@@ -322,6 +326,10 @@
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
