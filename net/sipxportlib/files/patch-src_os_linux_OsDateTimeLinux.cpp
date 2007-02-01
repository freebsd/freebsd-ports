--- ./src/os/linux/OsDateTimeLinux.cpp.orig	Tue Aug  1 03:09:34 2006
+++ ./src/os/linux/OsDateTimeLinux.cpp	Thu Dec 28 16:14:44 2006
@@ -169,7 +169,7 @@
    gettimeofday( &theTime, NULL );
 
    struct tm curDateTime;
-   gmtime_r(&theTime.tv_sec, &curDateTime);
+   gmtime_r((time_t *)&theTime.tv_sec, &curDateTime);
 
    rDateTime.mYear        = 1900 + curDateTime.tm_year;
    rDateTime.mMonth       = (unsigned char) curDateTime.tm_mon;
