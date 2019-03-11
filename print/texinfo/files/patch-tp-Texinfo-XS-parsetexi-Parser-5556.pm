--- tp/Texinfo/XS/parsetexi/Parser-5556.pm.orig	2019-02-16 17:11:56 UTC
+++ tp/Texinfo/XS/parsetexi/Parser-5556.pm
@@ -5438,12 +5438,12 @@ sub _parse_special_misc_command($$$$)
         }
     } elsif ($command eq 'clickstyle') {
         # REMACRO
-        if ($line =~ /^\s+@([[:alnum:]][[:alnum:]\-]*)({})?\s*/) {
+        if ($line =~ /^\s+@([[:alnum:]][[:alnum:]\-]*)(\{\})?\s*/) {
             $args = ['@'.$1];
             $self->{'clickstyle'} = $1
                 unless(_ignore_global_commands($self));
             $remaining = $line;
-            $remaining =~ s/^\s+@([[:alnum:]][[:alnum:]\-]*)({})?\s*(\@(c|comment)((\@|\s+).*)?)?//;
+            $remaining =~ s/^\s+@([[:alnum:]][[:alnum:]\-]*)(\{\})?\s*(\@(c|comment)((\@|\s+).*)?)?//;
             $has_comment = 1 if (defined($4));
         } else {
             $self->line_error (sprintf($self->__(
