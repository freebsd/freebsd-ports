--- libfreeipmi/src/driver/ipmi-kcs-driver.c.orig	2011-01-21 05:38:22.000000000 +0800
+++ libfreeipmi/src/driver/ipmi-kcs-driver.c	2011-01-24 09:49:23.000000000 +0800
@@ -484,7 +484,7 @@
 #ifdef __FreeBSD__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
-  if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
+  if (sysarch (I386_SET_IOPERM, (void *) (ctx->driver_address, 0x02, 0x01)))
     {
       KCS_ERRNO_TO_KCS_ERRNUM (ctx, errno);
       return (-1);
