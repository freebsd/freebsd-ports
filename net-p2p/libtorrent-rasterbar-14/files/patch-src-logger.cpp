--- src/logger.cpp.orig	2012-01-27 20:49:39.000000000 +0300
+++ src/logger.cpp	2012-01-27 20:49:56.000000000 +0300
@@ -63,7 +63,7 @@
 	{
 		logger_peer_plugin(std::string const& filename)
 		{
-			fs::path dir(fs::complete("libtorrent_ext_logs"));
+			fs::path dir(fs::absolute("libtorrent_ext_logs"));
 			if (!fs::exists(dir)) fs::create_directories(dir);
 			m_file.open((dir / filename).string().c_str(), std::ios_base::out | std::ios_base::out);
 			m_file << "\n\n\n";
