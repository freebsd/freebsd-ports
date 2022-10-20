--- ibft.c.orig	2021-05-18 18:37:58 UTC
+++ ibft.c
@@ -146,13 +146,12 @@ ibft_print_address(uint8_t *addr)
 void
 ibft_print_address(uint8_t *addr)
 {
-	uint32_t n0, n1, n2, n3;
+	uint32_t n0, n1, n2;
 
 	/* RFC2373 2.5.4 */
 	n0 = be32toh(*(uint32_t *)(addr + 0));
 	n1 = be32toh(*(uint32_t *)(addr + 4));
 	n2 = be32toh(*(uint32_t *)(addr + 8));
-	n3 = be32toh(*(uint32_t *)(addr +12));
 	if (n0 == 0 && n1 == 0 && n2 == 0x0000ffffU) {
 		/* IPv4-mapped IPv6 */
 		printf("%d.%d.%d.%d",
@@ -188,7 +187,7 @@ ibft_parse_structure(uint8_t *ibft)
 	struct ibft_nic *n0h, *n1h;
 	struct ibft_target *t0h, *t1h;
 	char oemid[6+1], oemtableid[8+1];
-	int id, version, length, index, flags;
+	int id, length, index, flags;
 	int revision, checksum;
 	int name_length, name_offset;
 	int sum, i;
@@ -226,7 +225,6 @@ ibft_parse_structure(uint8_t *ibft)
 	/* Control Structure (18 bytes or more) */
 	ch = (struct ibft_control *)(ibft + 48);
 	id = ch->id;
-	version = ch->version;
 	length = le16toh(ch->length);
 	index = ch->index;
 	flags = ch->flags;
@@ -258,7 +256,6 @@ ibft_parse_structure(uint8_t *ibft)
 	if (ibft_initiator_offset != 0) {
 		ih = (struct ibft_initiator *)(ibft + ibft_initiator_offset);
 		id = ih->id;
-		version = ih->version;
 		length = le16toh(ih->length);
 		index = ih->index;
 		flags = ih->flags;
@@ -307,7 +304,6 @@ ibft_parse_structure(uint8_t *ibft)
 	if (ibft_nic0_offset != 0) {
 		n0h = (struct ibft_nic *)(ibft + ibft_nic0_offset);
 		id = n0h->id;
-		version = n0h->version;
 		length = le16toh(n0h->length);
 		index = n0h->index;
 		flags = n0h->flags;
@@ -396,7 +392,6 @@ ibft_parse_structure(uint8_t *ibft)
 	if (ibft_target0_offset != 0) {
 		t0h = (struct ibft_target *)(ibft + ibft_target0_offset);
 		id = t0h->id;
-		version = t0h->version;
 		length = le16toh(t0h->length);
 		index = t0h->index;
 		flags = t0h->flags;
@@ -480,7 +475,6 @@ ibft_parse_structure(uint8_t *ibft)
 	if (ibft_nic1_offset != 0) {
 		n1h = (struct ibft_nic *)(ibft + ibft_nic1_offset);
 		id = n1h->id;
-		version = n1h->version;
 		length = le16toh(n1h->length);
 		index = n1h->index;
 		flags = n1h->flags;
@@ -499,7 +493,6 @@ ibft_parse_structure(uint8_t *ibft)
 	if (ibft_target1_offset != 0) {
 		t1h = (struct ibft_target *)(ibft + ibft_target1_offset);
 		id = t1h->id;
-		version = t1h->version;
 		length = le16toh(t1h->length);
 		index = t1h->index;
 		flags = t1h->flags;
@@ -556,7 +549,11 @@ ibft_init(void)
 			if (ibft_verbose) {
 				printf("iBFT error\n");
 			}
+#if __FreeBSD_version >= 1400070
+			pmap_unmapdev(vaddr,
+#else
 			pmap_unmapdev((vm_offset_t)vaddr,
+#endif
 			    (vm_size_t)IBFT_HIGH_ADDR);
 			return (error);
 		}
