--- sys/dev/bnxt/if_bnxt.c.orig	2016-11-24 08:48:18 UTC
+++ sys/dev/bnxt/if_bnxt.c
@@ -273,7 +273,7 @@ static driver_t bnxt_iflib_driver = {
  * iflib shared context
  */
 
-char bnxt_driver_version[] = "FreeBSD base";
+char bnxt_driver_version[] = "FreeBSD port %%PORTVERSION%%";
 extern struct if_txrx bnxt_txrx;
 static struct if_shared_ctx bnxt_sctx_init = {
 	.isc_magic = IFLIB_MAGIC,
