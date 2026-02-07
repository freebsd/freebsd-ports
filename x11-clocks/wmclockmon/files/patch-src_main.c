--- src/main.c.orig	2005-04-07 09:37:43 UTC
+++ src/main.c
@@ -51,7 +51,7 @@
 #define FREE(data) {if (data) free(data); data = NULL;}
 #define SET_STRING(str, val) {if (str) free(str); str = xstrdup(val);}
 
-#if defined(netbsd) || defined(openbsd) || defined(freebsd) || defined(darwin)
+#if defined(__NetBSD__) || defined(__OpenBSD__) || defined(__FreeBSD__) || defined(__APPLE__)
 #  define BSDTIMEZONE
 #endif
 
@@ -1270,10 +1270,10 @@ static void time_update() {
     time_t     tnow;
 
     time(&tnow);
-    timeinfos = localtime(&tnow);
 
     if (time_mode == INTERNET) {
         long localtmzone;
+    	timeinfos = gmtime(&tnow);
         swtime = timeinfos->tm_hour * 3600
                + timeinfos->tm_min * 60
                + timeinfos->tm_sec;
@@ -1290,6 +1290,9 @@ static void time_update() {
             swtime -= 1000;
         else
             if (swtime < 0) swtime += 1000;
+    }
+    else {
+    	timeinfos = localtime(&tnow);
     }
 }
 
