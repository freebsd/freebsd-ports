- workaroud of the removal of the ANYARG macro in pari-2.15.0

--- src/pari.cc.orig	2024-05-22 16:04:06 UTC
+++ src/pari.cc
@@ -55,6 +55,9 @@ using namespace std;
 #include <pthread.h>
 #endif
 
+// workaround for the removal of the ANYARG macro in pari-2.15.0
+#define ANYARG ...
+
 static long int abs(long int & l){
   if (l<0)
     return -l;
