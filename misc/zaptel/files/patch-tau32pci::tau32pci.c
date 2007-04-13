
$FreeBSD$

--- tau32pci/tau32pci.c
+++ tau32pci/tau32pci.c
@@ -2785,10 +2785,18 @@
 	}
 
 	/* set interrupt handler */
+#if __FreeBSD_version < 700031
 	error  = bus_setup_intr (dev, board->tau32_irq, INTR_TYPE_CLK | INTR_FAST, tau32_intr, board, &board->tau32_intrhand);
+#else
+	error  = bus_setup_intr (dev, board->tau32_irq, INTR_TYPE_CLK | INTR_FAST, NULL, tau32_intr, board, &board->tau32_intrhand);
+#endif
 	if(error) {
 		printf ("tau32_%d: Can't use fast interrupts, switching to generic\n", unit);
+#if __FreeBSD_version < 700031
 		error  = bus_setup_intr (dev, board->tau32_irq, INTR_TYPE_CLK, tau32_intr, board, &(board->tau32_intrhand));
+#else
+		error  = bus_setup_intr (dev, board->tau32_irq, INTR_TYPE_CLK, NULL, tau32_intr, board, &(board->tau32_intrhand));
+#endif
 	}
 
 
