--- pf.c.orig	Thu May 11 23:41:07 2006
+++ pf.c	Fri Jul  7 21:49:20 2006
@@ -144,23 +144,24 @@
 query_ifaces(int fd, void (*cb)(int, const char *, int, double))
 {
 	struct pfioc_iface io;
-	struct pfi_kif ifs[256];
+	struct pfi_if ifs[256];
 	int i, j;
 
 	memset(&io, 0, sizeof(io));
 	io.pfiio_buffer = ifs;
 	io.pfiio_esize = sizeof(ifs[0]);
 	io.pfiio_size = sizeof(ifs) / sizeof(ifs[0]);
+	io.pfiio_flags = PFI_FLAG_ALLMASK;
 	if (ioctl(fd, DIOCIGETIFACES, &io)) {
 		fprintf(stderr, "ioctl: DIOCIGETIFACES: %s\n", strerror(errno));
 		return (1);
 	}
 	for (i = 0; i < io.pfiio_size; ++i)
 		for (j = 0; j < 16; ++j)
-			(*cb)(COL_TYPE_IFACE, ifs[i].pfik_name,
+			(*cb)(COL_TYPE_IFACE, ifs[i].pfif_name,
 			    j, j & 4 ?
-			    ifs[i].pfik_packets[j&1?0:1][j&2?0:1][j&8?0:1] :
-			    ifs[i].pfik_bytes[j&1?0:1][j&2?0:1][j&8?0:1]);
+			    ifs[i].pfif_packets[j&1?0:1][j&2?0:1][j&8?0:1] :
+			    ifs[i].pfif_bytes[j&1?0:1][j&2?0:1][j&8?0:1]);
 	/* bytes/packets[af][dir][op] */
 	return (0);
 }
