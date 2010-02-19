--- src/stsession.cpp.orig	2009-07-06 01:40:21.000000000 +0400
+++ src/stsession.cpp	2010-02-17 19:01:03.000000000 +0300
@@ -501,7 +501,7 @@
 	for (std::vector<peer_info>::const_iterator i = peers.begin();
 						i != peers.end(); ++i, _icount++)
 	{
-		asio::ip::address _address =  i->ip.address();
+		libtorrent::asio::ip::address _address =  i->ip.address();
 
 		m_map_peers[_icount].append( QString("%1").arg(_icount)  );
 		m_map_peers[_icount].append( QString(_address.to_string().c_str()) );
