--- agent/mibgroup/sctp-mib/sctpTables.h.orig	2010-06-01 10:57:14.000000000 -0300
+++ agent/mibgroup/sctp-mib/sctpTables.h	2010-06-01 10:17:28.000000000 -0300
@@ -15,7 +15,7 @@
 #if defined( linux )
 config_require(sctp-mib/sctpTables_linux)
 config_require(util_funcs/get_pid_from_inode)
-#elif defined( freebsd7 ) || defined( freebsd8 )
+#elif defined( freebsd7 ) || defined( freebsd8 ) || defined( freebsd9 )
 config_require(sctp-mib/sctpTables_freebsd)
 #else
 config_error(SCTP-MIB is not available in tihs environment)
