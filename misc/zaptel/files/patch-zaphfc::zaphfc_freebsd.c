
$FreeBSD$

--- zaphfc/zaphfc_freebsd.c
+++ zaphfc/zaphfc_freebsd.c
@@ -328,14 +328,26 @@
 		zaphfc_free(sc);
 		return (ENXIO);
 	}
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(
 	    dev, sc->irq_res, INTR_TYPE_CLK | INTR_FAST,
 	    hfc_interrupt, sc, &sc->irq_handle);
+#else
+	error = bus_setup_intr(
+	    dev, sc->irq_res, INTR_TYPE_CLK | INTR_FAST, NULL,
+	    hfc_interrupt, sc, &sc->irq_handle);
+#endif
 
     if(error)
+#if __FreeBSD_version < 700031
 	    error = bus_setup_intr(
 	        dev, sc->irq_res, INTR_TYPE_CLK,
 	        hfc_interrupt, sc, &sc->irq_handle);
+#else
+	     error = bus_setup_intr(
+		dev, sc->irq_res, INTR_TYPE_CLK, NULL,
+		hfc_interrupt, sc, &sc->irq_handle);
+#endif
 
 	if (error) {
 		device_printf(dev, "Can't setup interrupt handler (error %d)\n",
