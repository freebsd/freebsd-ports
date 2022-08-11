--- CMakeModules/UseCompat.cmake.orig	2022-06-25 11:42:57 UTC
+++ CMakeModules/UseCompat.cmake
@@ -49,7 +49,7 @@ macro(USE_COMPAT)
 
     include(CheckStructHasMember)
     check_struct_has_member("struct tm" tm_gmtoff time.h HAVE_TM_GMTOFF)
-    check_symbol_exists(timezone time.h HAVE_TIME_H_TIMEZONE)
+#    check_symbol_exists(timezone time.h HAVE_TIME_H_TIMEZONE)
 
     check_symbol_exists(realpath "stdlib.h" HAVE_REALPATH)
     check_symbol_exists(localtime_r "time.h" HAVE_LOCALTIME_R)
