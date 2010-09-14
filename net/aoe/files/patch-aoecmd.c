--- aoecmd.c.orig	2006-05-26 00:13:09.000000000 +0700
+++ aoecmd.c	2010-09-13 20:15:55.000000000 +0700
@@ -44,6 +44,7 @@
 #include <sys/mutex.h>
 #include <sys/mbuf.h>
 #include <sys/sysctl.h>
+#include <sys/endian.h>
 
 #include <dev/aoe/aoe.h>
 
@@ -427,29 +428,6 @@
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
@@ -457,13 +435,13 @@
 
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
