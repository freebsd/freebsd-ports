--- net/quic/quic_network_transaction_unittest.cc.orig	2025-08-07 06:57:29 UTC
+++ net/quic/quic_network_transaction_unittest.cc
@@ -5203,10 +5203,10 @@ TEST_P(QuicNetworkTransactionTest, RstStreamBeforeHead
 
 TEST_P(QuicNetworkTransactionTest, BrokenAlternateProtocol) {
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
@@ -5249,10 +5249,10 @@ TEST_P(QuicNetworkTransactionTest,
   http_server_properties_ = std::make_unique<HttpServerProperties>();
 
   // Alternate-protocol job
-  std::unique_ptr<quic::QuicEncryptedPacket> close(
+  std::unique_ptr<quic::QuicEncryptedPacket> test_close(
       ConstructServerConnectionClosePacket(1));
   MockRead quic_reads[] = {
-      MockRead(ASYNC, close->data(), close->length()),
+      MockRead(ASYNC, test_close->data(), test_close->length()),
       MockRead(ASYNC, ERR_IO_PENDING),  // No more data to read
       MockRead(ASYNC, OK),              // EOF
   };
