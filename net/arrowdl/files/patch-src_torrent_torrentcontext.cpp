-- fix build with libtorrent-rasterbar2-2.1.1

--- src/torrent/torrentcontext.cpp.orig	2026-09-21 02:42:24 UTC
+++ src/torrent/torrentcontext.cpp
@@ -913,14 +913,14 @@ bool TorrentContext::_addTorrent(Torrent *torrent) // 
         // QByteArray bytes = source.toUtf8();
 
         auto ptr = bytes.constData();
-        auto size = static_cast<boost::string_view::size_type>(bytes.size());
+	auto size = static_cast<std::string_view::size_type>(bytes.size());
 
         lt::string_view uri { ptr, size };
         lt::error_code ec;
-        p = lt::parse_magnet_uri(uri.to_string(), ec);
+	p = lt::parse_magnet_uri(std::string(uri), ec);
         if (ec) {
             qDebug_1 << "invalid magnet link:";
-            qDebug_1 << QString::fromStdString(uri.to_string());
+	     qDebug_1 << QString::fromUtf8(uri.data(), uri.size());
             qDebug_1 << QString::fromStdString(ec.message());
             return false;
         }
