--- lib/Razor2/Client/Core.pm.orig	2002-11-25 19:07:38.000000000 +0100
+++ lib/Razor2/Client/Core.pm	2002-11-25 18:55:35.000000000 +0100
@@ -216,8 +216,10 @@
         foreach $rr ($query->answer) { 
             my $pushed = 0;
             if ($rr->type eq "A") { 
-                push @list, $rr->address; 
-                $pushed = 1;
+                if ($rr->address =~ m/^(\d+\.\d+\.\d+\.\d+)$/) {
+                    push @list, $1; 
+                    $pushed = 1;
+                }
             } elsif ($rr->type eq "CNAME") { 
                 if ($rr->cname eq 'list.terminator') { 
                     pop @list if $pushed;
