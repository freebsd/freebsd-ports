--- lib/Net/Server.pm.orig	2012-06-21 07:44:58.000000000 +0900
+++ lib/Net/Server.pm	2013-01-03 16:13:30.000000000 +0900
@@ -587,7 +587,10 @@
 
     # if the addr or host matches a deny, reject it immediately
     foreach (@{ $prop->{'deny'} }) {
-        return 0 if $prop->{'peerhost'} =~ /^$_$/ && defined $prop->{'reverse_lookups'};
+        return 0
+            if defined($prop->{'reverse_lookups'})
+            && defined($prop->{peerhost})
+            && $prop->{'peerhost'} =~ /^$_$/;
         return 0 if $peeraddr =~ /^$_$/;
     }
     if (@{ $prop->{'cidr_deny'} }) {
@@ -597,7 +600,10 @@
 
     # if the addr or host isn't blocked yet, allow it if it is allowed
     foreach (@{ $prop->{'allow'} }) {
-        return 1 if $prop->{'peerhost'} =~ /^$_$/ && defined $prop->{'reverse_lookups'};
+        return 1
+            if defined($prop->{'reverse_lookups'})
+            && defined($prop->{peerhost})
+            && $prop->{'peerhost'} =~ /^$_$/;
         return 1 if $peeraddr =~ /^$_$/;
     }
     if (@{ $prop->{'cidr_allow'} }) {
