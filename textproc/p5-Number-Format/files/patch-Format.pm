--- Format.pm.orig	Fri Sep 22 08:43:28 2006
+++ Format.pm	Fri Sep 22 08:43:35 2006
@@ -644,7 +644,7 @@
 
     # Combine it all back together and return it.
     $self->{int_curr_symbol} =~ s/\s*$/ /;
-    my $result = ($self->{int_curr_symbol} .
+    my $result = ($self->{int_curr_symbol} . ' '
                   ($precision ?
                    join($self->{mon_decimal_point}, $integer, $decimal) :
                    $integer));
