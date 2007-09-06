--- dev/cxm/cxm.c.orig	2007-09-05 19:08:24.707875447 +0200
+++ dev/cxm/cxm.c	2007-09-05 19:08:17.000000000 +0200
@@ -1799,7 +1799,7 @@
 	}
 
 	error = bus_setup_intr(dev, sc->irq_res, INTR_TYPE_TTY,
-			       cxm_intr, sc, &sc->ih_cookie);
+			       NULL, cxm_intr, sc, &sc->ih_cookie);
 	if (error) {
 		device_printf(dev, "could not setup irq\n");
 		goto fail;
