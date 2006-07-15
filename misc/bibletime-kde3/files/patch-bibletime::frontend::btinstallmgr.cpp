--- bibletime/frontend/btinstallmgr.cpp.orig	Sat Oct  1 08:18:03 2005
+++ bibletime/frontend/btinstallmgr.cpp	Tue Jul 11 11:07:41 2006
@@ -97,7 +97,7 @@
 				continue;
 			}
 			else {
-				conf["Install"].insert( std::make_pair(!setDataPath ? SWBuf("DataPath") : SWBuf("AugmentPath"), t.local8Bit()) );
+				conf["Install"].insert( std::make_pair((const char*)(!setDataPath ? "DataPath" : "AugmentPath"), t.local8Bit()) );
 
 				setDataPath = true;
 			}
@@ -167,10 +167,10 @@
 				is->directory--; //make one char shorter
 			}
 
-			config["Sources"].insert( std::make_pair(SWBuf("FTPSource"), is->getConfEnt()) );
+			config["Sources"].insert( std::make_pair((const char*)"FTPSource", is->getConfEnt()) );
 		}
 		else if (!strcmp(is->type, "DIR")) {
-			config["Sources"].insert( std::make_pair(SWBuf("DIRSource"), is->getConfEnt()) );
+			config["Sources"].insert( std::make_pair((const char*)"DIRSource", is->getConfEnt()) );
 		}
 		config.Save();
 	}
