--- bibletime/frontend/btinstallmgr.cpp.orig	Mon Aug 23 09:45:16 2004
+++ bibletime/frontend/btinstallmgr.cpp	Mon Aug 23 09:44:10 2004
@@ -104,7 +104,7 @@
     }
     else {
 //      conf["Install"][!setDataPath ? "DataPath" : "AugmentPath"] = t.local8Bit();
-	    conf["Install"].insert( std::make_pair(!setDataPath ? "DataPath" : "AugmentPath", t.local8Bit()) );
+	    conf["Install"].insert( std::make_pair((const char*)(!setDataPath ? "DataPath" : "AugmentPath"), t.local8Bit()) );
 
       setDataPath = true;
     }
@@ -176,10 +176,10 @@
 			is->directory--; //make one char shorter
 		}
 
-    config["Sources"].insert( std::make_pair("FTPSource", is->getConfEnt()) );
+    config["Sources"].insert( std::make_pair((const char*)"FTPSource", is->getConfEnt()) );
   }
   else if (!strcmp(is->type, "DIR")) {
-    config["Sources"].insert( std::make_pair("DIRSource", is->getConfEnt()) );
+    config["Sources"].insert( std::make_pair((const char*)"DIRSource", is->getConfEnt()) );
   }
   config.Save();
 }
