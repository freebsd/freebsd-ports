--- src/kademlia/dht_tracker.cpp.orig	2016-08-23 04:28:09 UTC
+++ src/kademlia/dht_tracker.cpp
@@ -224,7 +224,8 @@ namespace libtorrent { namespace dht
 	void dht_tracker::get_peers(sha1_hash const& ih
 		, boost::function<void(std::vector<tcp::endpoint> const&)> f)
 	{
-		m_dht.get_peers(ih, f, NULL, false);
+		boost::function<void(std::vector<std::pair<node_entry, std::string> > const&)> empty;
+		m_dht.get_peers(ih, f, empty, false);
 	}
 
 	void dht_tracker::announce(sha1_hash const& ih, int listen_port, int flags
