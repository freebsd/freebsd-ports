--- lib/Razor2/Client/Config.pm.orig	2002-11-25 19:13:59.000000000 +0100
+++ lib/Razor2/Client/Config.pm	2002-11-11 19:29:17.000000000 +0100
@@ -323,9 +323,11 @@
         if ($fn =~ /^(.*)\/([^\/]+)$/) {
             my $dir = $1;
             $fn = readlink $fn;
+            $fn = $1 if $fn =~ /^(\S+)$/; # untaint readlink
             $fn = "$dir/$fn" unless $fn =~ /^\//;
         } else {
             $fn = readlink $fn;
+            $fn = $1 if $fn =~ /^(\S+)$/; # untaint readlink
         }
     }
 }
@@ -366,13 +368,13 @@
         chomp; 
         next if /^\s*#/;
         if ($nothash) {
-            s/^\s+//; s/\s+$//;
+            next unless s/^\s*(.+?)\s*$/$1/; # untaint
             $conf->{$_} = 7;
             push @lines, $_;
         } else { 
             next unless /=/;
-            my ($attribute, $value) = split /\=/, $_, 2; 
-            $attribute =~ s/^\s+//; $attribute =~ s/\s+$//;
+            my ($attribute, $value) = /^\s*(.+?)\s*=\s*(.+?)\s*$/; # untaint
+            next unless (defined $attribute && defined $value);
             $conf->{$attribute} = $self->parse_value($value);
         }
         $total++;
