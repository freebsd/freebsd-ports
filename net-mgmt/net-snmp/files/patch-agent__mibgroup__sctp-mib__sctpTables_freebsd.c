--- ./agent/mibgroup/sctp-mib/sctpTables_freebsd.c.orig	2011-11-30 18:30:17.000000000 -0500
+++ ./agent/mibgroup/sctp-mib/sctpTables_freebsd.c	2011-11-30 18:30:48.000000000 -0500
@@ -192,7 +192,6 @@
   *flags |= SCTP_TABLES_LOAD_FLAG_AUTO_LOOKUP;
   len = 0;
   if (sysctlbyname("net.inet.sctp.assoclist", 0, &len, 0, 0) < 0) {
-	printf("Error %d (%s) could not get the assoclist\n", errno, strerror(errno));
 	return(-1);
   }
   if ((buf = (caddr_t)malloc(len)) == 0) {
