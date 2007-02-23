--- src/libopensc/reader-pcsc.c.orig	Fri Feb 23 22:13:56 2007
+++ src/libopensc/reader-pcsc.c	Fri Feb 23 22:14:40 2007
@@ -60,7 +60,6 @@
 #undef SCARD_PROTOCOL_ANY
 #define SCARD_PROTOCOL_ANY (SCARD_PROTOCOL_T0 | SCARD_PROTOCOL_T1)
 #ifdef _WIN32
-#define SCARD_SCOPE_GLOBAL SCARD_SCOPE_USER
 
 /* Error printing */
 #define PCSC_ERROR(ctx, desc, rv) sc_error(ctx, desc ": %lx\n", rv);
@@ -717,7 +716,7 @@
 	struct pcsc_global_private_data *gpriv;
 	scconf_block *conf_block;
 
-	rv = SCardEstablishContext(SCARD_SCOPE_GLOBAL,
+	rv = SCardEstablishContext(SCARD_SCOPE_USER,
                               NULL, NULL, &pcsc_ctx);
 	if (rv != SCARD_S_SUCCESS)
 		return pcsc_ret_to_error(rv);
