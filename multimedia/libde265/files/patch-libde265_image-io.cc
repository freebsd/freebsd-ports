--- libde265/image-io.cc.orig	2025-04-26 20:58:45 UTC
+++ libde265/image-io.cc
@@ -208,7 +208,7 @@ PacketSink_File::PacketSink_File()
 }
 
 
-LIBDE265_API PacketSink_File::~PacketSink_File()
+PacketSink_File::~PacketSink_File()
 {
   if (mFH) {
     fclose(mFH);
@@ -216,7 +216,7 @@ LIBDE265_API PacketSink_File::~PacketSink_File()
 }
 
 
-LIBDE265_API void PacketSink_File::set_filename(const char* filename)
+void PacketSink_File::set_filename(const char* filename)
 {
   assert(mFH==NULL);
 
@@ -224,7 +224,7 @@ LIBDE265_API void PacketSink_File::set_filename(const 
 }
 
 
-LIBDE265_API void PacketSink_File::send_packet(const uint8_t* data, int n)
+void PacketSink_File::send_packet(const uint8_t* data, int n)
 {
   uint8_t startCode[3];
   startCode[0] = 0;
