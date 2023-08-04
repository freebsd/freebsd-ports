--- stubs.inc.orig	2023-08-04 08:14:08 UTC
+++ stubs.inc
@@ -355,13 +355,11 @@
 #pragma message( "Warning: the function pcap_open() is not available" )
 #endif
 
-#if PERL_PCAP_VERSION < 1009000
 struct pcap_rmtauth {
     int type;
     char *username;
     char *password;
 };
-#endif
 
 pcap_t * pcap_open(const char *source, int snaplen, int flags, int read_timeout, struct pcap_rmtauth *auth, char *err);
 pcap_t * pcap_open(const char *source, int snaplen, int flags, int read_timeout, struct pcap_rmtauth *auth, char *err) {
