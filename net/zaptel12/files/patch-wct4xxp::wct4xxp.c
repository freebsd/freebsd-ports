
$FreeBSD$

--- wct4xxp/wct4xxp.c
+++ wct4xxp/wct4xxp.c
@@ -3800,15 +3800,29 @@
 	    return ENXIO;
 	}
 
+#if __FreeBSD_version < 700031
 	error = bus_setup_intr(dev, wc->wc_irq, INTR_TYPE_CLK | INTR_FAST,
 	    (void (*)(void *)) ((ident->device_info->flags & FLAG_2NDGEN) ?  
 	    t4_interrupt_gen2 : t4_interrupt), wc, &(wc->irq_handler));
+#else
+	error = bus_setup_intr(dev, wc->wc_irq, INTR_TYPE_CLK | INTR_FAST, NULL,
+	    (void (*)(void *)) ((ident->device_info->flags & FLAG_2NDGEN) ?
+	    t4_interrupt_gen2 : t4_interrupt), wc, &(wc->irq_handler));
+#endif
+
 	if(error)
 	{
 		printf("Can't use fast interrupts falling back to normal\n");
+#if __FreeBSD_version < 700031
 		error = bus_setup_intr(dev, wc->wc_irq, INTR_TYPE_CLK,
 	    		(void (*)(void *)) ((ident->device_info->flags & FLAG_2NDGEN) ?  
 	    		t4_interrupt_gen2 : t4_interrupt), wc, &(wc->irq_handler));
+#else
+		error = bus_setup_intr(dev, wc->wc_irq, INTR_TYPE_CLK, NULL,
+			(void (*)(void *)) ((ident->device_info->flags & FLAG_2NDGEN) ?
+			t4_interrupt_gen2 : t4_interrupt), wc, &(wc->irq_handler));
+#endif
+
 
 	}
 
