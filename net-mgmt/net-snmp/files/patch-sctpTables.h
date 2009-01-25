--- agent/mibgroup/sctp-mib/sctpTables.h.orig	2009-01-23 23:46:39.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpTables.h	2009-01-23 23:47:35.000000000 +0900
@@ -14,6 +14,8 @@
 config_require(sctp-mib/sctpAssocTable)
 #if defined( linux )
 config_require(sctp-mib/sctpTables_linux)
+#elif defined( freebsd7 )
+config_require(sctp-mib/sctpTables_freebsd)
 #else
 /*
 * couldn't determine the correct file!
