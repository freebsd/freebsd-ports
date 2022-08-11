--- isboot.c.orig	2022-05-11 20:13:59 UTC
+++ isboot.c
@@ -127,13 +127,12 @@ isboot_is_v4addr(uint8_t *addr)
 int
 isboot_is_v4addr(uint8_t *addr)
 {
-	uint32_t n0, n1, n2, n3;
+	uint32_t n0, n1, n2;
 
 	/* RFC2373 2.5.4 */
 	n0 = be32toh(*(uint32_t *)(addr + 0));
 	n1 = be32toh(*(uint32_t *)(addr + 4));
 	n2 = be32toh(*(uint32_t *)(addr + 8));
-	n3 = be32toh(*(uint32_t *)(addr +12));
 	if (n0 == 0 && n1 == 0 && n2 == 0x0000ffffU)
 		return (1);	/* IPv4-mapped IPv6 */
 	else
