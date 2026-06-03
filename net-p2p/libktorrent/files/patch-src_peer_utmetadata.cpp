--- src/peer/utmetadata.cpp.orig	2026-04-08 19:26:42 UTC
+++ src/peer/utmetadata.cpp
@@ -34,7 +34,7 @@ void UTMetaData::handlePacket(const bt::Uint8 *packet,
         return;
     }
 
-    const auto tmp = QByteArrayView{packet, size}.sliced(2);
+    const auto tmp = QByteArrayView{packet, static_cast<qsizetype>(size)}.sliced(2);
     try {
         BDecoder dec(tmp.data(), tmp.size(), false);
         const std::unique_ptr<BDictNode> dict = dec.decodeDict();
