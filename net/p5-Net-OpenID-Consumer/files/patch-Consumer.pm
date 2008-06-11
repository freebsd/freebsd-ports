--- Consumer.pm	2007-08-04 02:38:53.000000000 +0400
+++ lib/Net/OpenID/Consumer.pm	2008-06-04 19:10:37.000000000 +0400
@@ -235,7 +235,7 @@
         # OpenID servers / delegated identities
         # <link rel="openid.server" href="http://www.livejournal.com/misc/openid.bml" />
         if ($type eq "link" &&
-            $val =~ /\brel=.openid\.(server|delegate)./i && ($temp = $1) &&
+            $val =~ /\brel=[\"\'][^\"\']*\bopenid\.(server|delegate)\b/i && ($temp = $1) &&
             $val =~ m!\bhref=[\"\']([^\"\']+)[\"\']!i) {
             $ret->{"openid.$temp"} = $1;
             next;
@@ -301,7 +301,8 @@
         $ret->{$k} =~ s/&(\w+);/$emap->{$1} || ""/eg;
     }
 
-    $self->_debug("semantic info ($url) = " . join(", ", %$ret));
+    $self->_debug("semantic info ($url) = " . join(", ", 
+        map { defined($ret->{$_}) ? ($_ => $ret->{$_}) : () } keys %$ret));
 
     return $ret;
 }
@@ -543,6 +544,7 @@
 sub hmac {
     my($data, $key, $hash_func, $block_size) = @_;
     $block_size ||= 64;
+    $key = $key . '';   # stringify for charwise ^ to work
     $key = &$hash_func($key) if length($key) > $block_size;
 
     my $k_ipad = $key ^ (chr(0x36) x $block_size);
