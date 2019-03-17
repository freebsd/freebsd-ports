--- sendd/snd_proto.h.orig	2019-02-27 16:25:45 UTC
+++ sendd/snd_proto.h
@@ -41,11 +41,15 @@
 #define	ND_OPT_CGA		11
 #define	ND_OPT_SIG		12
 #define	ND_OPT_TIMESTAMP	13
+#ifndef ND_OPT_NONCE
 #define	ND_OPT_NONCE		14
+#endif
 #define	ND_OPT_TRUST_ANCHOR	15
 #define	ND_OPT_CERTIFICATE	16
 
+#ifndef ND_OPT_MAX
 #define	ND_OPT_MAX		ND_OPT_CERTIFICATE
+#endif
 
 #define NDISC_OPT_SPACE(len) (((len)+2+7)&~7)
 
