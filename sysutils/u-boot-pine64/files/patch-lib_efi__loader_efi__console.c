--- lib/efi_loader/efi_console.c
+++ lib/efi_loader/efi_console.c
@@ -167,6 +167,9 @@ static efi_status_t EFIAPI efi_cout_query_mode(
 {
 	EFI_ENTRY("%p, %ld, %p, %p", this, mode_number, columns, rows);
 
+	if (mode_number != 0)
+		return EFI_EXIT(EFI_INVALID_PARAMETER);
+
 	if (!console_size_queried) {
 		/* Ask the terminal about its size */
 		int n[3];
