--- aoecmd.c.orig	2006-05-25 17:13:09 UTC
+++ aoecmd.c
@@ -44,6 +44,7 @@ __FBSDID("$FreeBSD: src/sys/dev/aoe/aoecmd.c,v 1.23.2.
 #include <sys/mutex.h>
 #include <sys/mbuf.h>
 #include <sys/sysctl.h>
+#include <sys/endian.h>
 
 #include <dev/aoe/aoe.h>
 
@@ -197,12 +198,11 @@ rexmit(struct aoedev *d, struct frame *f)
 {
 	/* struct mbuf *m; */
 	struct aoe_hdr *h;
-	struct aoe_atahdr *ah;
 
 	h = (struct aoe_hdr *) f->f_hdr;
-	ah = (struct aoe_atahdr *) (h+1);
 
 #ifdef AOE_DEBUG
+	struct aoe_atahdr *ah = (struct aoe_atahdr *) (h+1);
 
 	IPRINTK("mlen=%ld verfl=%X major=%X minor=%X cmd=%X\n"
 		"\ttag=%lX aflags=%X errfeat=%X scnt=%X cmdstat=%X\n"
@@ -427,29 +427,6 @@ loop:
 	goto loop;
 }
 
-static u_short
-lhget16(u_char *p)
-{
-        u_short n;
-
-        n = p[1];
-        n <<= 8;
-	n |= p[0];
-        return (n);
-}
-
-static u_long
-lhget32(u_char *p)
-{
-        u_long n;
-
-        n = lhget16(p+2);
-        n <<= 16;
-        n |= lhget16(p);
-        return (n);
-}
-
-
 static void
 ataid_complete(struct aoedev *d, char *id)
 {
@@ -457,13 +434,13 @@ ataid_complete(struct aoedev *d, char *id)
 
 	memcpy(d->ad_ident, id, sizeof d->ad_ident);
 
-	n = lhget16(id + (83<<1));		/* Command set supported. */
+	n = le16toh(*(uint16_t *) (id + (83<<1)));		/* Command set supported. */
 	if (n & (1<<10)) {			/* Lba48 */
 		atomic_set_32(&d->ad_flags, DEVFL_EXT);
-		d->ad_nsectors = lhget32(id + (100<<1));	/* n lba48 sectors. */
+		d->ad_nsectors = le64toh(*(uint64_t *) (id + (100<<1)));	/* n lba48 sectors. */
 	} else {
 		atomic_clear_32(&d->ad_flags, DEVFL_EXT);
-		d->ad_nsectors = lhget32(id + (60<<1));	/* n lba28 sectors. */
+		d->ad_nsectors = le32toh(*(uint32_t *) (id + (60<<1)));	/* n lba28 sectors. */
 	}
 	if (aoeblk_register(d) != 0)
 		IPRINTK("could not register disk\n");
@@ -614,7 +591,7 @@ aoecmd_ata_smart(struct aoedev *d, struct ata_ioc_requ
 	struct aoe_hdr *h;
 	struct aoe_atahdr *ah;
 	register daddr_t lba;
-	int timeout;
+	int error, timeout;
 
 	timeout = iocmd->ata_ioc_request_timeout;
 
@@ -664,10 +641,12 @@ aoecmd_ata_smart(struct aoedev *d, struct ata_ioc_requ
 	iocmd->ata_ioc_request_ata.lba = lba;
 
 	if (iocmd->ata_ioc_request_flags == ATA_CMD_READ)
-		copyout(ah+1, iocmd->ata_ioc_request_data, iocmd->ata_ioc_request_count);
+		error = copyout(ah+1, iocmd->ata_ioc_request_data, iocmd->ata_ioc_request_count);
+	else
+		error = 0;
 
 	f->f_tag = FREETAG;
-	return (0);
+	return (error);
 }
 
 /* Set the write caching. */
