--- dev/ptx/ptx_proc.c.orig	2022-05-19 22:27:03 UTC
+++ dev/ptx/ptx_proc.c
@@ -108,7 +108,6 @@ read_dmabuf(struct ptx_softc *scp, uint32_t *dataptr)
 	} micro;
 
 	uint8_t id;
-	uint8_t count;
 	uint8_t st;
 	uint8_t er;
 
@@ -116,7 +115,7 @@ read_dmabuf(struct ptx_softc *scp, uint32_t *dataptr)
 		micro.val = *dataptr;
 
 		id    = (micro.packet.head >> 5) & 0x7;
-		count = (micro.packet.head >> 2) & 0x7;
+		// count = (micro.packet.head >> 2) & 0x7;
 		st    = (micro.packet.head >> 1) & 0x1;
 		er    = (micro.packet.head >> 0) & 0x1;
 
