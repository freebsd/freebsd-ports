
$FreeBSD$

--- wcte11xp/wcte11xp.c
+++ wcte11xp/wcte11xp.c
@@ -1953,14 +1953,24 @@
 
 	/* Now we should set up the interrupt handler */
 
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST,
 		(void (*)(void *))wcte11xp_interrupt, sc, &(sc->irq_handler));
+#else
+	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST, NULL,
+		(void (*)(void *))wcte11xp_interrupt, sc, &(sc->irq_handler));
+#endif
 
 	if(error)
 	{
 		printf("Can not use fast interrupts, switching to generic\n");
+#if __FreeBSD_version < 700031
 		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK,
 			(void (*)(void *))wcte11xp_interrupt, sc, &(sc->irq_handler));
+#else
+		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK, NULL,
+			(void (*)(void *))wcte11xp_interrupt, sc, &(sc->irq_handler));
+#endif
 	}
 
 	if (error) {
