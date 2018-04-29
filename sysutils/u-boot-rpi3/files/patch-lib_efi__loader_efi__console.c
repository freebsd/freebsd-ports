--- lib/efi_loader/efi_console.c.orig	2018-03-13 12:02:19 UTC
+++ lib/efi_loader/efi_console.c
@@ -547,8 +547,8 @@ int efi_console_register(void)
 		printf("ERROR: Failed to register console event\n");
 		return r;
 	}
-	/* 5000 ns cycle is sufficient for 2 MBaud */
-	r = efi_set_timer(console_timer_event, EFI_TIMER_PERIODIC, 50);
+	/* 100 ms */
+	r = efi_set_timer(console_timer_event, EFI_TIMER_PERIODIC, 100*1000*10);
 	if (r != EFI_SUCCESS)
 		printf("ERROR: Failed to set console timer\n");
 	return r;
