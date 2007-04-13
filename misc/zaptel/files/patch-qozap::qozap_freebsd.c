
$FreeBSD$

--- qozap/qozap_freebsd.c
+++ qozap/qozap_freebsd.c
@@ -175,9 +175,15 @@
 		qozap_free(sc);
 		return (ENXIO);
 	}
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(
 	    dev, sc->irq_res, INTR_TYPE_CLK | INTR_FAST, qoz_interrupt,
 	    sc, &sc->irq_handle);
+#else
+	error = bus_setup_intr(
+	    dev, sc->irq_res, INTR_TYPE_CLK | INTR_FAST, NULL, qoz_interrupt,
+	    sc, &sc->irq_handle);
+#endif
 	if (error) {
 		device_printf(dev, "Can't setup interrupt handler (error %d)\n",
 		    error);
