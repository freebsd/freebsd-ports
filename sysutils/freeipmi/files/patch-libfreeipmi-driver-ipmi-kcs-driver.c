--- libfreeipmi/driver/ipmi-kcs-driver.c.orig	2018-07-30 23:07:27 UTC
+++ libfreeipmi/driver/ipmi-kcs-driver.c
@@ -148,6 +148,9 @@
 #if defined(__FreeBSD__)
 # include <machine/cpufunc.h>
 # include <machine/sysarch.h>
+#if defined(__powerpc__)
+# include <machine/pio.h>               /* inb/outb */
+#endif
 #elif defined(__NetBSD__) || defined(__OpenBSD__)
 # include <machine/pio.h>               /* inb/outb */
 # include <machine/sysarch.h>   /* sysarch call */
@@ -495,7 +498,7 @@ ipmi_kcs_ctx_io_init (ipmi_kcs_ctx_t ctx
 #ifdef __FreeBSD__
 #ifdef USE_IOPERM
   /* i386_set_ioperm has known problems on FBSD 5.x (bus errors). */
-  if (i386_set_ioperm (ctx->driver_address, 0x02, 0x01))
+  if (sysarch (I386_SET_IOPERM, (void *) (ctx->driver_address, 0x02, 0x01)))
     {
       KCS_ERRNO_TO_KCS_ERRNUM (ctx, errno);
       return (-1);
