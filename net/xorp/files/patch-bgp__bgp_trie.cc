--- ./bgp/bgp_trie.cc.orig	2010-07-19 21:10:33.000000000 +0000
+++ ./bgp/bgp_trie.cc	2014-02-26 21:17:13.000000000 +0000
@@ -115,7 +115,7 @@
 		   net.str().c_str(),
 		   found->attributes()->str().c_str());
 	XLOG_INFO("Pathmap dump follows: \n");
-	for (pmi == _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
+	for (pmi = _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
 	    XLOG_INFO("%s\n\n", pmi->second->str().c_str());
 	}
 	XLOG_FATAL("Exiting\n");
