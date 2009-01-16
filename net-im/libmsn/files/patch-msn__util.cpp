--- ./msn/util.cpp.orig	2008-11-16 16:27:05.000000000 +0300
+++ ./msn/util.cpp	2009-01-16 20:32:29.000000000 +0300
@@ -29,7 +29,7 @@
 #include <fstream>
 #include <openssl/rand.h>
 #include <cstring>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include "md5.h"
 
 #ifdef _WIN32
@@ -352,10 +352,11 @@
 
     std::string new_branch()
     {
-        struct timeb t;
-        ftime(&t);
+        struct timeval t;
+        struct timezone tz;
+        gettimeofday(&t, &tz);
         char branch[100];
-        srand(t.millitm);
+        srand(t.tv_usec);
         unsigned int a=random();
         srand(a);
         unsigned short b=random();
