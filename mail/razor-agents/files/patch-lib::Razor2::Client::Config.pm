--- lib/Razor2/Client/Config.pm.orig	2002-11-25 19:13:59.000000000 +0100
+++ lib/Razor2/Client/Config.pm	2002-11-11 19:29:17.000000000 +0100
@@ -373,6 +373,7 @@
             next unless /=/;
             my ($attribute, $value) = split /\=/, $_, 2; 
             $attribute =~ s/^\s+//; $attribute =~ s/\s+$//;
+            $value = $1  if $value =~ /^(.*)$/;  # untaint!
             $conf->{$attribute} = $self->parse_value($value);
         }
         $total++;
