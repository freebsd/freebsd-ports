--- avidemux_plugins/ADM_demuxers/MpegTS/dmxTSPacket.cpp.orig	2016-01-29 08:47:25 UTC
+++ avidemux_plugins/ADM_demuxers/MpegTS/dmxTSPacket.cpp
@@ -144,7 +144,7 @@ bool    tsPacket::setPos(uint64_t pos)
 {
     if(!_file->setpos(pos))
     {
-        printf("[tsPacket] Cannot seek to %"PRIx64"\n", pos);
+        printf("[tsPacket] Cannot seek to %" PRIx64"\n", pos);
         return false;
     }
     return true;
@@ -387,7 +387,7 @@ nextPack3:
     zprintf("[TS Demuxer] Code=0x%x pid=0x%x\n",code,pes->pid);
     if((code&0xffffff00)!=0x100)
     {
-        printf("[Ts Demuxer] No PES startcode at 0x%"PRIx64"\n",pkt.startAt);
+        printf("[Ts Demuxer] No PES startcode at 0x%" PRIx64"\n",pkt.startAt);
         printf("0x:%02x %02x %02x %02x\n",pkt.payload[4],pkt.payload[5],pkt.payload[6],pkt.payload[7]);
         goto nextPack3;
     }
@@ -433,7 +433,7 @@ nextPack3:
 /**
     \fn decodePesHeader
 */
-#define fail(x) {printf("[Ts Demuxer]*********"x"*******\n");return false;}
+#define fail(x) {printf("[Ts Demuxer]*********" x"*******\n");return false;}
 bool tsPacket::decodePesHeader(TS_PESpacket *pes)
 {
     uint8_t  *start=pes->payload+6;
@@ -735,7 +735,7 @@ bool    tsPacketLinear::read(uint32_t le
 */
 bool    tsPacketLinear::getInfo(dmxPacketInfo *info)
 {
-#warning FIXME
+//#warning FIXME
     if(pesPacket->offset<4)
     {
         info->startAt=this->oldStartAt;
@@ -780,12 +780,12 @@ bool    tsPacketLinear::seek(uint64_t pa
 {
     if(!_file->setpos(packetStart))
     {
-        printf("[tsPacket] Cannot seek to %"PRIx64"\n",packetStart);
+        printf("[tsPacket] Cannot seek to %" PRIx64"\n",packetStart);
         return 0;
     }
     if(!refill())
     {
-        printf("[tsPacketLinear] Seek to %"PRIx64":%"PRIx32" failed\n",packetStart,offset);
+        printf("[tsPacketLinear] Seek to %" PRIx64":%" PRIx32" failed\n",packetStart,offset);
         return false;
     }
     ADM_assert(offset<pesPacket->payloadSize);
