--- src/pflib/NATCompiler_ipf.h.orig	2006-05-16 16:00:17.000000000 -0700
+++ src/pflib/NATCompiler_ipf.h	2007-09-19 10:33:40.000000000 -0700
@@ -33,6 +33,8 @@
 
 #define FTP_PORT    21
 #define RCMD_PORT   514
+#define KRCMD_PORT  544
+#define EKSHELL_PORT 2106
 #define H323_PORT   1720
 #define RAUDIO_PORT 5050
 #define ISAKMP_PORT 500
