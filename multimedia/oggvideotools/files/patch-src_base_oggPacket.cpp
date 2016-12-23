--- src/base/oggPacket.cpp.orig	2016-01-11 07:51:37 UTC
+++ src/base/oggPacket.cpp
@@ -34,7 +34,7 @@ streamType(OggType::unknown), streamNo(2
 
 OggPacketInternal::OggPacketInternal(uint8* data, uint32 length,
                                      uint32 packetNo, int64 granulePos, PacketType packetType)
-  : oggPacket {/*packet*/data,/*bytes*/length, /*b_o_s*/0, /*e_o_s*/0, /*granualpos*/granulePos, /*packetno*/packetNo},
+  : oggPacket {/*packet*/data,/*bytes*/static_cast<long>(length), /*b_o_s*/0, /*e_o_s*/0, /*granualpos*/granulePos, /*packetno*/packetNo},
 streamType(OggType::unknown), streamNo(255), streamHeader(false)
 {
   switch (packetType) {
