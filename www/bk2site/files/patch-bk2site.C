--- bk2site.C.orig	Fri Feb 18 21:54:52 2005
+++ bk2site.C	Fri Feb 18 21:57:13 2005
@@ -448,10 +448,11 @@
 			cout << "Reading " << varValues[URLLOGFILE] << endl;
 			time_t curTime;
 			time_t cutoffTime = time(0) - atoi(varValues[HITSTIMECUTOFF].c_str());
-			string currentURL = "";
+			string currentURL = "", scurTime = "";
 			while (!(istream.eof())){
-				istream >> curTime;
+				istream >> scurTime;
 				istream >> currentURL;
+				curTime = atoi(scurTime.c_str());
 				//if url starts with a number (its a time) or url is null
 				//  keep trying to read a time/url pair.
 				while (((currentURL[0] >= '0' && currentURL[0] <= '9') || currentURL == "") && !istream.eof()){
