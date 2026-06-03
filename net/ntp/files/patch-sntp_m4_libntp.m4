--- sntp/m4/ntp_libntp.m4.orig	2024-05-07 04:21:13.000000000 -0700
+++ sntp/m4/ntp_libntp.m4	2026-03-23 13:11:24.414734000 -0700
@@ -827,7 +827,7 @@
     ]
 )
 
-AC_SEARCH_LIBS([MD5Init], [md5 md])
+AC_SEARCH_LIBS([MD5Init], [md md5])
 AC_CHECK_FUNCS([MD5Init sysconf getdtablesize sigaction sigset sigvec])
 
 # HMS: does this need to be a cached variable?
