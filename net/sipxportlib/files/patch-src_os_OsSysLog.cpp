--- src/os/OsSysLog.cpp.orig	Tue Jul 25 17:05:55 2006
+++ src/os/OsSysLog.cpp	Wed Feb 14 09:54:52 2007
@@ -39,6 +39,9 @@
 #if defined(_WIN32)
      // Windows va_arg function does not take a const 
 #    define OS_VA_ARG_CONST 
+#elif defined(__FreeBSD__)
+     // FreeBSD's va_list is not const
+#    define OS_VA_ARG_CONST
 #elif defined(__pingtel_on_posix__)
      // Posix va_arg function takes a const
 #    define OS_VA_ARG_CONST const
@@ -333,7 +336,9 @@
       {
          UtlString logData;
          UtlString logEntry;
-         myvsprintf(logData, format, ap) ;
+         OS_VA_ARG_CONST va_list *myap;
+         myap = (OS_VA_ARG_CONST va_list *)&ap;
+         myvsprintf(logData, format, *myap) ;
          logData = escape(logData) ;
 
          OsTime timeNow;
