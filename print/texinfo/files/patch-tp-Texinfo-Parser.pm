--- tp/Texinfo/Parser.pm.orig	2017-09-12 18:49:03 UTC
+++ tp/Texinfo/Parser.pm
@@ -5478,11 +5478,11 @@ sub _parse_special_misc_command($$$$)
     }
   } elsif ($command eq 'clickstyle') {
     # REMACRO
-    if ($line =~ /^\s+@([[:alnum:]][[:alnum:]\-]*)({})?\s*/) {
+    if ($line =~ /^\s+@([[:alnum:]][[:alnum:]\-]*)(\{\})?\s*/) {
       $args = ['@'.$1];
       $self->{'clickstyle'} = $1;
       $remaining = $line;
-      $remaining =~ s/^\s+@([[:alnum:]][[:alnum:]\-]*)({})?\s*(\@(c|comment)((\@|\s+).*)?)?//;
+      $remaining =~ s/^\s+@([[:alnum:]][[:alnum:]\-]*)(\{\})?\s*(\@(c|comment)((\@|\s+).*)?)?//;
       $has_comment = 1 if (defined($4));
     } else {
       $self->line_error (sprintf($self->__(
