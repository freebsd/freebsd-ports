--- classes/src/CflowdCiscoMap.cc.orig	Fri Aug 29 21:26:58 2003
+++ classes/src/CflowdCiscoMap.cc	Fri Aug 29 21:28:13 2003
@@ -39,6 +39,7 @@
 //    info@caida.org
 //===========================================================================
 
+using namespace std;
 #include <string>
 #include <vector>
 
@@ -112,7 +113,7 @@
   }
         
   numCiscos = htonl(numCiscos);
-  os.write(&numCiscos,sizeof(numCiscos));
+  os.write((char *)&numCiscos,sizeof(numCiscos));
   
   for (ciscomIter = (*this).begin(); ciscomIter != (*this).end();
        ciscomIter++) {
