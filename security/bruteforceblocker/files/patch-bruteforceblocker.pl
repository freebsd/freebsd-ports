--- bruteforceblocker.pl.orig	2017-08-17 13:42:11.038416000 +0100
+++ bruteforceblocker.pl	2017-08-17 13:46:39.555246000 +0100
@@ -81,7 +81,8 @@
 	/.*Invalid user.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
 	/.*Did not receive identification string from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
 	/.*Bad protocol version identification .* from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
-	/.*User.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) not allowed because.*/i ) {
+	/.*User.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) not allowed because.*/i ||
+	/.*error: maximum authentication attempts exceeded for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i) {
 
 	my $IP = $1;
 	if ($IP =~ /$work->{fqdn}/i) {
