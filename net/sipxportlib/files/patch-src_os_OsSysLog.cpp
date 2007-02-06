--- src/os/OsSysLog.cpp.orig	Tue Jul 25 17:05:55 2006
+++ src/os/OsSysLog.cpp	Tue Feb  6 08:07:54 2007
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
@@ -333,7 +336,7 @@
       {
          UtlString logData;
          UtlString logEntry;
-         myvsprintf(logData, format, ap) ;
+         myvsprintf(logData, format, (OS_VA_ARG_CONST va_list)ap) ;
          logData = escape(logData) ;
 
          OsTime timeNow;
