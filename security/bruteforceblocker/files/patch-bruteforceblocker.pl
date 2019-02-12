--- bruteforceblocker.pl.orig	2018-12-18 11:17:19 UTC
+++ bruteforceblocker.pl
@@ -79,13 +79,13 @@ my $res   = Net::DNS::Resolver->new;
 while (<>) {
     if (/.*Failed password.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
 	/.*Failed keyboard.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
-	/.*Invalid user.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
-	/.*Did not receive identification string from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
-	/.*Bad protocol version identification .* from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn})$/i ||
+	/.*Invalid user.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
+	/.*Did not receive identification string from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
+	/.*Bad protocol version identification .* from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
 	/.*User.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) not allowed because.*/i ||
-	/.*error: maximum authentication attempts exceeded for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i ||
-	/.*error: PAM: authentication error for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i ||
-	/.*fatal: Unable to negotiate with ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}).*/i) {
+	/.*error: maximum authentication attempts exceeded for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
+	/.*error: PAM: authentication error for.*from ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i ||
+	/.*Unable to negotiate with ($work->{ipv4}|$work->{ipv6}|$work->{fqdn}) port.*/i) {
 
 	my $IP = $1;
 	if ($IP =~ /$work->{fqdn}/i) {
