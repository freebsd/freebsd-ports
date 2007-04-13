
$FreeBSD$

--- wcfxo/wcfxo.c
+++ wcfxo/wcfxo.c
@@ -1285,14 +1285,25 @@
 
 	/* Now we should set up the interrupt handler */
 
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST,
 		(void (*)(void *))wcfxo_interrupt, sc, &(sc->irq_handler));
+#else
+	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST, NULL,
+		(void (*)(void *))wcfxo_interrupt, sc, &(sc->irq_handler));
+#endif
 
 	if(error)
 	{
 		printf("Can't use fast interrupts, falling back to normal\n");
+#if __FreeBSD_version < 700031
 		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK,
 			(void (*)(void *))wcfxo_interrupt, sc, &(sc->irq_handler));
+#else
+		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK, NULL,
+			(void (*)(void *))wcfxo_interrupt, sc, &(sc->irq_handler));
+#endif
+
 	}
 
 	if (error) {
