--- msn/util.cpp.orig	2009-07-22 19:57:10.000000000 +0000
+++ msn/util.cpp
@@ -25,11 +25,12 @@
 #include <msn/util.h>
 #include <sstream>
 #include <errno.h>
+#include <unistd.h>
 #include <cctype>
 #include <fstream>
 #include <openssl/rand.h>
 #include <cstring>
-#include <sys/timeb.h>
+#include <sys/time.h>
 #include "md5.h"
 #include "libsiren/siren7.h"
 
@@ -367,10 +368,11 @@ namespace MSN
 
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
