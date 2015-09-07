--- cli/cli_client.cc.orig	2012-01-11 17:56:10 UTC
+++ cli/cli_client.cc
@@ -832,7 +832,7 @@ CliClient::process_char_page_mode(uint8_
     //
     // Print help
     //
-    if ((val == 'h')) {
+    if (val == 'h') {
 	if (! is_help_mode()) {
 	    set_help_mode(true);
 	    _is_page_buffer_mode = &_is_help_buffer_mode;
@@ -958,7 +958,7 @@ CliClient::process_char_page_mode(uint8_
     // Display the output all at once instead of oen screen at a time.
     // (Same as specifying the "| no-more" command.)
     //
-    if ((val == 'N')) {
+    if (val == 'N') {
 	while (page_buffer_last_line_n() < page_buffer_lines_n()) {
 	    set_page_buffer_mode(false);
 	    cli_print(page_buffer_line(page_buffer_last_line_n()));
@@ -1021,7 +1021,7 @@ CliClient::process_char_page_mode(uint8_
     //
     // Redraw the output of the screen
     //
-    if ((val == CHAR_TO_CTRL('l'))) {
+    if (val == CHAR_TO_CTRL('l')) {
     redisplay_screen_label:
 	size_t i, start_window_line = 0;
 	set_page_buffer_mode(false);
