--- classes/src/CflowdProtocolTable.cc.orig	Fri Aug 29 20:37:48 2003
+++ classes/src/CflowdProtocolTable.cc	Fri Aug 29 20:39:55 2003
@@ -82,9 +82,9 @@
     (*this).erase((*this).begin(),(*this).end());
   }
 
-  is.read(&numProtocols,sizeof(numProtocols));
+  is.read((char *)&numProtocols,sizeof(numProtocols));
   for (protocolNum = 0; protocolNum < numProtocols; protocolNum++) {
-    is.read(&protocol,sizeof(protocol));
+    is.read((char *)&protocol,sizeof(protocol));
     protoTraffic.read(is);
     (*this)[protocol] = protoTraffic;
   }
@@ -151,11 +151,11 @@
   CflowdProtocolTable::const_iterator  protoIter;
   
   numProtocols = (*this).size();
-  os.write(&numProtocols,sizeof(numProtocols));
+  os.write((char *)&numProtocols,sizeof(numProtocols));
 
   for (protoIter = (*this).begin(); protoIter != (*this).end(); protoIter++) {
     protocol = (*protoIter).first;
-    os.write(&protocol,sizeof(protocol));
+    os.write((const char *)&protocol,sizeof(protocol));
     (*protoIter).second.write(os);
   }
   return(os);
