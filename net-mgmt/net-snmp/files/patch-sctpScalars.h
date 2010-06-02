--- agent/mibgroup/sctp-mib/sctpScalars.h.orig	2009-04-08 12:29:04.000000000 -0300
+++ agent/mibgroup/sctp-mib/sctpScalars.h	2010-06-01 11:02:56.000000000 -0300
@@ -7,7 +7,7 @@
 config_require(sctp-mib/sctpScalars_common)
 #if defined( linux )
 config_require(sctp-mib/sctpScalars_linux)
-#elif defined( freebsd8 ) || defined ( freebsd7 )
+#elif defined( freebsd9 ) || defined( freebsd8 ) || defined ( freebsd7 )
 config_require(sctp-mib/sctpScalars_freebsd)	 
 #else
 /*
