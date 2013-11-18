--- libs/libmythbase/logging.cpp.orig	2013-09-18 20:06:08.000000000 +0000
+++ libs/libmythbase/logging.cpp	2013-10-18 14:57:43.000000000 +0000
@@ -859,7 +859,7 @@
 #ifndef _WIN32
     if (logPropagateOpts.facility >= 0)
     {
-        CODE *syslogname;
+        const CODE *syslogname;
 
         for (syslogname = &facilitynames[0];
              (syslogname->c_name &&
@@ -996,7 +996,7 @@
         "Windows does not support syslog, disabling" );
     return( -2 );
 #else
-    CODE *name;
+    const CODE *name;
     int i;
     QByteArray ba = facility.toLocal8Bit();
     char *string = (char *)ba.constData();
