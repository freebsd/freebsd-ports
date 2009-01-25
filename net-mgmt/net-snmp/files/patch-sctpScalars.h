--- agent/mibgroup/sctp-mib/sctpScalars.h.orig	2009-01-23 23:43:37.000000000 +0900
+++ agent/mibgroup/sctp-mib/sctpScalars.h	2009-01-23 23:44:12.000000000 +0900
@@ -7,6 +7,8 @@
 config_require(sctp-mib/sctpScalars_common)
 #if defined( linux )
 config_require(sctp-mib/sctpScalars_linux)
+#elif defined ( freebsd7 )
+config_require(sctp-mib/sctpScalars_freebsd)
 #else
 /*
  * couldn't determine the correct file!
