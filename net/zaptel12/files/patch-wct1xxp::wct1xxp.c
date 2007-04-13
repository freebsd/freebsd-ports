
$FreeBSD$

--- wct1xxp/wct1xxp.c
+++ wct1xxp/wct1xxp.c
@@ -1746,14 +1746,24 @@
 
 	/* Now we should set up the interrupt handler */
 
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST,
 		(void (*)(void *))wct1xxp_interrupt, sc, &(sc->irq_handler));
+#else
+	error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK | INTR_FAST, NULL,
+		(void (*)(void *))wct1xxp_interrupt, sc, &(sc->irq_handler));
+#endif
 
 	if(error)
 	{
 		printf("Can not use fast interrupts, switching to generic\n");
+#if __FreeBSD_version < 700031
 		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK,
 			(void (*)(void *))wct1xxp_interrupt, sc, &(sc->irq_handler));
+#else
+		error = bus_setup_intr(dev, sc->wc_irq, INTR_TYPE_CLK, NULL,
+			(void (*)(void *))wct1xxp_interrupt, sc, &(sc->irq_handler));
+#endif
 	}
 
 
