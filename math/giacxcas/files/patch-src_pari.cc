- workaroud of the removal of the ANYARG macro in pari-2.15.0

--- src/pari.cc.orig	2022-03-16 11:38:05 UTC
+++ src/pari.cc
@@ -44,6 +44,9 @@ using namespace std;
 #include <pthread.h>
 #endif
 
+// workaround for the removal of the ANYARG macro in pari-2.15.0
+#define ANYARG ...
+
 static long int abs(long int & l){
   if (l<0)
     return -l;
