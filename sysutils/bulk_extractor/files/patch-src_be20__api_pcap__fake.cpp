--- src/be20_api/pcap_fake.cpp.orig	2026-08-23 08:06:22 UTC
+++ src/be20_api/pcap_fake.cpp
@@ -109,7 +109,7 @@ pcap_t* pcap_fopen_offline(FILE* fp, char* errbuf) {
 
     pcap_t* ret = (pcap_t*)calloc(1, sizeof(pcap_t));
     if (ret == 0) {
-        snprintf(errbuf, PCAP_ERRBUF_SIZE, "Cannot calloc %lu bytes", sizeof(pcap_t));
+        snprintf(errbuf, PCAP_ERRBUF_SIZE, "Cannot calloc %zu bytes", sizeof(pcap_t));
         return 0;
     }
     ret->pktbuf = (uint8_t*)malloc(header.snaplen);
