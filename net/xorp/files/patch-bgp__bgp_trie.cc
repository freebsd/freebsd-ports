--- bgp/bgp_trie.cc.orig	2012-01-11 17:56:10 UTC
+++ bgp/bgp_trie.cc
@@ -115,7 +115,7 @@ BgpTrie<A>::erase(const IPNet& net)
 		   net.str().c_str(),
 		   found->attributes()->str().c_str());
 	XLOG_INFO("Pathmap dump follows: \n");
-	for (pmi == _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
+	for (pmi = _pathmap.begin(); pmi != _pathmap.end(); pmi++) {
 	    XLOG_INFO("%s\n\n", pmi->second->str().c_str());
 	}
 	XLOG_FATAL("Exiting\n");
