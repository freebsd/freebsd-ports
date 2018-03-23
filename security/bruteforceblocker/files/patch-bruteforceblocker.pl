--- bruteforceblocker.pl.orig	2018-02-05 04:11:53 UTC
+++ bruteforceblocker.pl
@@ -82,7 +82,8 @@ while (<>) {
 	/.*Did not receive identification string from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
 	/.*Bad protocol version identification .* from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
 	/.*User.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) not allowed because.*/i ||
-	/.*error: maximum authentication attempts exceeded for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i) {
+	/.*error: maximum authentication attempts exceeded for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i ||
+	/.*fatal: Unable to negotiate with ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i) {
 
 	my $IP = $1;
 	if ($IP =~ /$work->{fqdn}/i) {
