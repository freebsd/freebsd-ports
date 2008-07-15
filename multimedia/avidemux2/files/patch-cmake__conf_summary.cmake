--- ./cmake/conf_summary.cmake.orig	2008-06-28 10:20:38.000000000 +0200
+++ ./cmake/conf_summary.cmake	2008-07-10 17:16:26.000000000 +0200
@@ -1,10 +1,10 @@
 MACRO(ADM_DISPLAY _name _val)
 #MESSAGE("${_val}")
-if(${_val} EQUAL 1)
+if(${_val} EQUAL 1 OR ${_val} STREQUAL "YES")
   set(s "Yes")
-else(${_val} EQUAL 1)
+else(${_val} EQUAL 1 OR ${_val} STREQUAL "YES")
   set(s "No")
-endif(${_val} EQUAL 1)
+endif(${_val} EQUAL 1 OR ${_val} STREQUAL "YES")
 MESSAGE("${_name}  ${s}") 
 ENDMACRO(ADM_DISPLAY _name _val)
 
@@ -13,8 +13,8 @@
 MESSAGE("*******************")
 MESSAGE("**  Summary      **")
 MESSAGE("*******************")
-MESSAGE("Gtk         ${GTK_FOUND}")
-MESSAGE("Qt4         ${QT4_FOUND}")
+ADM_DISPLAY("Gtk       "  GTK_FOUND)
+ADM_DISPLAY("Qt4       "  QT4_FOUND)
 MESSAGE("*** Video Codec ***")
 ADM_DISPLAY("X264      " USE_X264)
 ADM_DISPLAY("Xvid4     " USE_XVID_4)
