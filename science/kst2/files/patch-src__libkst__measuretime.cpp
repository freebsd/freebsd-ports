--- ./src/libkst/measuretime.cpp.orig	2009-12-01 10:15:36.000000000 +0300
+++ ./src/libkst/measuretime.cpp	2010-02-19 00:41:22.998033638 +0300
@@ -67,7 +67,7 @@
   started = st.QuadPart * frequency;
 #else
   timespec t;
-  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
+  clock_gettime(CLOCK_PROF, &t);
   started = 1.0 * t.tv_sec + 1e-9 * t.tv_nsec;  
 #endif
   interval = 0;
@@ -82,7 +82,7 @@
   double now = st.QuadPart * frequency;
 #else
   timespec t;
-  clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &t);
+  clock_gettime(CLOCK_PROF, &t);
   double now = 1.0 * t.tv_sec + 1e-9 * t.tv_nsec;
 #endif
   interval += now - started;
