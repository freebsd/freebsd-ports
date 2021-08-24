--- support/install.pl.orig	2021-05-18 08:50:05 UTC
+++ support/install.pl
@@ -316,7 +316,7 @@ sub rel_symlink {
    my $rel_link = $link;
    my $common_prefix = 1;
    while ($rel_link =~ s{^(/[^/]+)(?=/)}{}) {
-      if ($common_prefix && substr($target, 0, length($1)) eq $1) {
+      if ($common_prefix && substr($target, 0, length($1)+1) eq "$1/") {
          $target = substr($target, length($1));
       } else {
          $common_prefix = 0;
