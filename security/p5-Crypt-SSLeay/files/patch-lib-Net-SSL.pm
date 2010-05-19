--- lib/Net/SSL.pm.orig	2007-09-17 12:56:52.000000000 -0700
+++ lib/Net/SSL.pm	2010-05-19 11:23:50.000000000 -0700
@@ -361,8 +361,15 @@
 
     $connect_string .= $CRLF;
     $self->SUPER::send($connect_string);
-    my $header;
-    my $n = $self->SUPER::sysread($header, 8192);
+    my $header = "";
+    my $timeout;
+    while ($header !~ m{HTTP/\d+\.\d+\s+200\s+.*\r\n\r\n}s) {
+	$timeout = $self->timeout(5) unless length $header;
+	my $n = $self->SUPER::sysread($header, 8192, length $header);
+	last if $n <= 0;
+    }
+    $self->timeout($timeout) if defined $timeout;
+
     my $conn_ok = ($header =~ /HTTP\/\d+\.\d+\s+200\s+/is) ? 1 : 0;
 
     if (not $conn_ok) {
