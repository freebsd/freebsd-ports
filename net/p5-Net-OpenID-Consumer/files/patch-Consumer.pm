--- lib/Net/OpenID/Consumer.pm.orig	2008-10-14 12:38:16.000000000 +0800
+++ lib/Net/OpenID/Consumer.pm	2008-11-11 15:20:06.000000000 +0800
@@ -255,7 +255,7 @@
         # OpenID servers / delegated identities
         # <link rel="openid.server" href="http://www.livejournal.com/misc/openid.bml" />
         if ($type eq "link" &&
-            $val =~ /\brel=.openid\.(server|delegate)./i && ($temp = $1) &&
+            $val =~ /\brel=[\"\'][^\"\']*\bopenid\.(server|delegate)\b/i && ($temp = $1) &&
             $val =~ m!\bhref=[\"\']([^\"\']+)[\"\']!i) {
             $ret->{"openid.$temp"} = $1;
             next;
@@ -909,6 +909,7 @@
 sub hmac {
     my($data, $key, $hash_func, $block_size) = @_;
     $block_size ||= 64;
+    $key = $key . '';   # stringify for charwise ^ to work
     $key = &$hash_func($key) if length($key) > $block_size;
 
     my $k_ipad = $key ^ (chr(0x36) x $block_size);
