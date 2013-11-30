--- libgrive/src/drive/State.cc.orig	2013-05-03 00:40:04.000000000 +0800
+++ libgrive/src/drive/State.cc	2013-11-27 15:17:50.000000000 +0800
@@ -248,12 +248,12 @@ void State::Read( const fs::path& filena
 void State::Write( const fs::path& filename ) const
 {
 	Json last_sync ;
-	last_sync.Add( "sec",	Json(m_last_sync.Sec() ) );
-	last_sync.Add( "nsec",	Json(m_last_sync.NanoSec() ) );
+	last_sync.Add( "sec",	Json((boost::uint64_t)m_last_sync.Sec() ) );
+	last_sync.Add( "nsec",	Json((boost::uint64_t)m_last_sync.NanoSec() ) );
 	
 	Json result ;
 	result.Add( "last_sync", last_sync ) ;
-	result.Add( "change_stamp", Json(m_cstamp) ) ;
+	result.Add( "change_stamp", Json((boost::uint64_t)m_cstamp) ) ;
 	
 	std::ofstream fs( filename.string().c_str() ) ;
 	fs << result ;
