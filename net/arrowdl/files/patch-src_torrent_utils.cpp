-- fix build with libtorrent-rasterbar2-2.1.1

-- lt::string_view::to_string() was removed; use Qt's fromUtf8() on the raw
-- data instead. lt::aux::to_hex()/from_hex() are not exported from the shared
-- library with ABI version 2, so replace them with QByteArray hex conversion.

--- src/torrent/utils.cpp.orig	2025-03-23 11:56:15 UTC
+++ src/torrent/utils.cpp
@@ -17,7 +17,6 @@
 #include "utils.h"

 #include "libtorrent/add_torrent_params.hpp"
-#include "libtorrent/hex.hpp"               // to_hex, from_hex
 #include "libtorrent/magnet_uri.hpp"
 #include "libtorrent/torrent_info.hpp"

@@ -25,21 +24,19 @@
 UniqueId TorrentUtils::toUniqueId(const lt::sha1_hash &hash)
 {
     if (!hash.is_all_zeros()) {
-        auto hex = lt::aux::to_hex(hash);
-        return QString::fromStdString(hex).toUpper();
+        return QString::fromLatin1(QByteArray(hash.data(), hash.size()).toHex()).toUpper();
     }
     return {};
 }

 lt::sha1_hash TorrentUtils::fromUniqueId(const UniqueId &uuid)
 {
-    lt::span<char const> in(uuid.toStdString());
-    lt::sha1_hash out;
-    if (!lt::aux::from_hex(in, out.data())) {
+    const QByteArray bin = QByteArray::fromHex(uuid.toLatin1());
+    if (bin.size() != lt::sha1_hash::size()) {
         qWarning() << "invalid info-hash";
         return lt::sha1_hash();
     }
-    return out;
+    return lt::sha1_hash(lt::span<char const>(bin.constData(), bin.size()));
 }

 /******************************************************************************
@@ -376,14 +373,13 @@

 QString TorrentUtils::toString(const lt::string_view &s)
 {
-    return QString::fromStdString(s.to_string()).toUpper();
+    return QString::fromUtf8(s.data(), s.size()).toUpper();
 }

 QString TorrentUtils::toString(const lt::sha1_hash &hash)
 {
     if (!hash.is_all_zeros()) {
-        auto hex = lt::aux::to_hex(hash);
-        return QString::fromStdString(hex).toUpper();
+        return QString::fromLatin1(QByteArray(hash.data(), hash.size()).toHex()).toUpper();
     }
     return {};
 }
