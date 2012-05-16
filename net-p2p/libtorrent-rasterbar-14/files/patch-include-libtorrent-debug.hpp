--- include/libtorrent/debug.hpp.orig	2012-01-27 20:16:02.000000000 +0300
+++ include/libtorrent/debug.hpp	2012-01-27 20:16:23.000000000 +0300
@@ -64,7 +64,7 @@
 			try
 			{
 #endif
-				fs::path dir(fs::complete(logpath / ("libtorrent_logs" + boost::lexical_cast<std::string>(instance))));
+				fs::path dir(fs::absolute(logpath / ("libtorrent_logs" + boost::lexical_cast<std::string>(instance))));
 				if (!fs::exists(dir)) fs::create_directories(dir);
 				m_file.open((dir / filename).string().c_str(), std::ios_base::out | (append ? std::ios_base::app : std::ios_base::out));
 				*this << "\n\n\n*** starting log ***\n";
