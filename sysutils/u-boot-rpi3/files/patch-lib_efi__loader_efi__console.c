--- lib/efi_loader/efi_console.c.orig	2016-11-14 16:27:11 UTC
+++ lib/efi_loader/efi_console.c
@@ -9,9 +9,9 @@
 #include <common.h>
 #include <efi_loader.h>
 
-/* If we can't determine the console size, default to 80x24 */
+/* If we can't determine the console size, default to 80x25 */
 static int console_columns = 80;
-static int console_rows = 24;
+static int console_rows = 25;
 static bool console_size_queried;
 
 const efi_guid_t efi_guid_console_control = CONSOLE_CONTROL_GUID;
@@ -165,6 +165,8 @@ static efi_status_t EFIAPI efi_cout_quer
 			unsigned long mode_number, unsigned long *columns,
 			unsigned long *rows)
 {
+	unsigned long current_mode;
+
 	EFI_ENTRY("%p, %ld, %p, %p", this, mode_number, columns, rows);
 
 	if (!console_size_queried) {
@@ -196,6 +198,16 @@ static efi_status_t EFIAPI efi_cout_quer
 	}
 
 out:
+	if (console_columns == 80 && console_rows == 25)
+		current_mode = 0;
+	else if (console_columns == 80 && console_rows == 50)
+		current_mode = 1;
+	else
+		current_mode = 2;
+
+	if (mode_number != current_mode)
+		return EFI_EXIT(EFI_UNSUPPORTED);
+
 	if (columns)
 		*columns = console_columns;
 	if (rows)
