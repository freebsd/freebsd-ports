
$FreeBSD$

--- wcfxs/wcfxs.c
+++ wcfxs/wcfxs.c
@@ -2764,12 +2764,23 @@
 
 	/* Now we should set up the interrupt handler */
 
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST,
 		(void (*)(void *))wcfxs_interrupt, sc, &(sc->irq_handler));
+#else
+	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST, NULL,
+		(void (*)(void *))wcfxs_interrupt, sc, &(sc->irq_handler));
+#endif
+
 	if (error) {
 		printf("Can't use fast interrupts, falling back to normal\n");
+#if __FreeBSD_version < 700031
 		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK,
 			(void (*)(void *))wcfxs_interrupt, sc, &(sc->irq_handler));
+#else
+		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK, NULL,
+			(void (*)(void *))wcfxs_interrupt, sc, &(sc->irq_handler));
+#endif
 		if(error)
 		{
 			printf("Couldn't set up irq\n");
