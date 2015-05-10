--- libfreeipmi/driver/ipmi-kcs-driver.c.orig	2014-01-03 23:45:22 UTC
+++ libfreeipmi/driver/ipmi-kcs-driver.c
@@ -491,7 +491,7 @@ ipmi_kcs_ctx_io_init (ipmi_kcs_ctx_t ctx
 #ifdef __FreeBSD__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
-  if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
+  if (sysarch (I386_SET_IOPERM, (void *) (ctx->driver_address, 0x02, 0x01)))
     {
       KCS_ERRNO_TO_KCS_ERRNUM (ctx, errno);
       return (-1);
