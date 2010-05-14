--- libs/libmythfreemheg/Programs.cpp.orig	2009-07-06 22:42:28.000000000 +0200
+++ libs/libmythfreemheg/Programs.cpp	2010-03-16 13:48:01.000000000 +0100
@@ -129,9 +129,7 @@
         if (m_Name.Equal("GCD")) { // GetCurrentDate - returns local time.
             if (args.Size() == 2) {
                 struct timeb timebuffer;
-#if HAVE_FTIME
-                ftime(&timebuffer);
-#elif HAVE_GETTIMEOFDAY
+#if HAVE_GETTIMEOFDAY
 		struct timeval   time;
                 struct timezone  zone;
 
