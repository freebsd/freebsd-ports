--- lib/Mail/SpamAssassin/Plugin/URIDNSBL.pm.orig	2025-08-27 06:17:47.000000000 -0700
+++ lib/Mail/SpamAssassin/Plugin/URIDNSBL.pm	2026-06-16 15:54:55.370330000 -0700
@@ -967,7 +967,7 @@
 
   my $nsrhsblrules = $pms->{uridnsbl_active_rules_nsrhsbl};
   my $fullnsrhsblrules = $pms->{uridnsbl_active_rules_fullnsrhsbl};
-  my $areviprules = $pms->{uridnsbl_active_rules_arevipbl};
+  my $nsreviprules = $pms->{uridnsbl_active_rules_nsrevipbl};
   my $seen_lookups = $pms->{uridnsbl_seen_lookups};
 
   my $j = 0;
@@ -998,7 +998,7 @@
       else {
         if (!$seen_lookups->{"A:$nsmatch"}) {
           $seen_lookups->{"A:$nsmatch"} = 1;
-          $self->lookup_a_record($pms, $nsmatch, [keys %$areviprules]);
+          $self->lookup_a_record($pms, $nsmatch, [keys %$nsreviprules]);
         }
         $nsrhblstr = $self->{main}->{registryboundaries}->trim_domain($nsmatch);
       }
