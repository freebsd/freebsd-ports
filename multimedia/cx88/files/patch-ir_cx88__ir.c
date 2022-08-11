--- ir/cx88_ir.c.orig	2022-07-26 16:20:13 UTC
+++ ir/cx88_ir.c
@@ -70,8 +70,6 @@ static unsigned int cx88_ir_biphase_decode(uint32_t *s
 static int cx88_ir_request_reconfig(device_t dev);
 static unsigned int cx88_ir_biphase_decode(uint32_t *samples, unsigned int num_samples);
 
-static devclass_t cx88_ir_devclass;
-
 static d_open_t cx88_ir_open;
 static d_close_t cx88_ir_close;
 static d_read_t cx88_ir_read;
@@ -401,7 +399,12 @@ static driver_t cx88_ir_driver =
    0
 };
 
+#if __FreeBSD_version >= 1400058
+DRIVER_MODULE(cx88ir, pci, cx88_ir_driver, NULL, NULL);
+#else
+static devclass_t cx88_ir_devclass;
+
 DRIVER_MODULE(cx88ir, pci, cx88_ir_driver, cx88_ir_devclass, NULL, NULL);
-DRIVER_MODULE(cx88ir, cardbus, cx88_ir_driver, cx88_ir_devclass, NULL, NULL);
+#endif
 CX88_DRIVER_MODULE(cx88ir);
 MODULE_VERSION(cx88ir, 1);
