--- ./cli/cli_client.cc.orig	2011-07-25 17:45:38.000000000 +0000
+++ ./cli/cli_client.cc	2014-02-26 21:17:13.000000000 +0000
@@ -832,7 +832,7 @@
     //
     // Print help
     //
-    if ((val == 'h')) {
+    if (val == 'h') {
 	if (! is_help_mode()) {
 	    set_help_mode(true);
 	    _is_page_buffer_mode = &_is_help_buffer_mode;
@@ -958,7 +958,7 @@
     // Display the output all at once instead of oen screen at a time.
     // (Same as specifying the "| no-more" command.)
     //
-    if ((val == 'N')) {
+    if (val == 'N') {
 	while (page_buffer_last_line_n() < page_buffer_lines_n()) {
 	    set_page_buffer_mode(false);
 	    cli_print(page_buffer_line(page_buffer_last_line_n()));
@@ -1021,7 +1021,7 @@
     //
     // Redraw the output of the screen
     //
-    if ((val == CHAR_TO_CTRL('l'))) {
+    if (val == CHAR_TO_CTRL('l')) {
     redisplay_screen_label:
 	size_t i, start_window_line = 0;
 	set_page_buffer_mode(false);
