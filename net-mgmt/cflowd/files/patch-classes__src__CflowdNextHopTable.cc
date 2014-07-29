--- classes/src/CflowdNextHopTable.cc.orig	Fri Aug 29 21:52:18 2003
+++ classes/src/CflowdNextHopTable.cc	Fri Aug 29 21:53:26 2003
@@ -82,11 +82,11 @@
     (*this).erase((*this).begin(),(*this).end());
   }
 
-  is.read(&numNextHops,sizeof(numNextHops));
+  is.read((char *)&numNextHops,sizeof(numNextHops));
   numNextHops = ntohl(numNextHops);
   
   for (nextHopNum = 0; nextHopNum < numNextHops; nextHopNum++) {
-    is.read(&nextHop,sizeof(nextHop));
+    is.read((char *)&nextHop,sizeof(nextHop));
     nextHopTraffic.read(is);
     (*this)[nextHop] = nextHopTraffic;
   }
@@ -154,12 +154,12 @@
   
   numNextHops = (*this).size();
   numNextHops = htonl(numNextHops);
-  os.write(&numNextHops,sizeof(numNextHops));
+  os.write((char *)&numNextHops,sizeof(numNextHops));
 
   for (nextHopIter = (*this).begin(); nextHopIter != (*this).end();
        nextHopIter++) {
     nextHop = (*nextHopIter).first;
-    os.write(&nextHop,sizeof(nextHop));
+    os.write((char *)&nextHop,sizeof(nextHop));
     (*nextHopIter).second.write(os);
   }
   return(os);
