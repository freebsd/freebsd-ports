--- sp_network_utils.c.orig	2017-12-21 22:34:33 UTC
+++ sp_network_utils.c
@@ -23,15 +23,8 @@ static inline bool cidr4_match(const str
 
 static inline bool cidr6_match(const struct in6_addr address,
                                const struct in6_addr network, uint8_t bits) {
-  //#ifdef LINUX
-  const uint32_t *a = address.s6_addr32;
-  const uint32_t *n = network.s6_addr32;
-  /*
-#else
   const uint32_t *a = address.__u6_addr.__u6_addr32;
   const uint32_t *n = network.__u6_addr.__u6_addr32;
-#endif
-*/
   int bits_whole = bits >> 5;         // number of whole u32
   int bits_incomplete = bits & 0x1F;  // number of bits in incomplete u32
   if (bits_whole) {
