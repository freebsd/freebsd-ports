--- classes/src/CflowdTosTable.cc.orig	Fri Aug 29 22:01:28 2003
+++ classes/src/CflowdTosTable.cc	Fri Aug 29 22:01:52 2003
@@ -82,9 +82,9 @@
     (*this).erase((*this).begin(),(*this).end());
   }
 
-  is.read(&numToss,sizeof(numToss));
+  is.read((char *)&numToss,sizeof(numToss));
   for (tosNum = 0; tosNum < numToss; tosNum++) {
-    is.read(&tos,sizeof(tos));
+    is.read((char *)&tos,sizeof(tos));
     protoTraffic.read(is);
     (*this)[tos] = protoTraffic;
   }
@@ -151,11 +151,11 @@
   CflowdTosTable::const_iterator  protoIter;
   
   numToss = (*this).size();
-  os.write(&numToss,sizeof(numToss));
+  os.write((char *)&numToss,sizeof(numToss));
 
   for (protoIter = (*this).begin(); protoIter != (*this).end(); protoIter++) {
     tos = (*protoIter).first;
-    os.write(&tos,sizeof(tos));
+    os.write((char *)&tos,sizeof(tos));
     (*protoIter).second.write(os);
   }
   return(os);
