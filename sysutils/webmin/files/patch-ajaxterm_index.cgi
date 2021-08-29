--- ajaxterm/index.cgi.orig
+++ ajaxterm/index.cgi
@@ -16,7 +16,7 @@
 &ui_print_header(undef, $text{'index_title'}, "", undef, 1, 1);
 
 # Check for python
-my $python = &has_command("python2") || &has_command("python");
+my $python = &has_command("python2.7") || &has_command("python");
 if (!$python) {
 	&ui_print_endpage(&text('index_epython', "<tt>python</tt>"));
 	}
