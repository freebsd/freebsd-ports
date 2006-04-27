--- Format.pm.orig	Thu Apr 27 00:47:37 2006
+++ Format.pm	Thu Apr 27 21:59:09 2006
@@ -643,8 +643,8 @@
     $decimal .= '0'x($precision - length $decimal);
 
     # Combine it all back together and return it.
-    $self->{int_curr_symbol} =~ s/\s+$/ /;
-    my $result = ($self->{int_curr_symbol} .
+    $self->{int_curr_symbol} =~ s/\s+$//;
+    my $result = ($self->{int_curr_symbol} . ' ' .
                   ($precision ?
                    join($self->{mon_decimal_point}, $integer, $decimal) :
                    $integer));
