--- lib/Swatchdog/Throttle.pm.orig	2015-09-29 16:39:26 UTC
+++ lib/Swatchdog/Throttle.pm
@@ -95,6 +95,7 @@ sub throttle {
 	      @_
 	     );
 
+  my @delay = split(/:/, "0:$opts{DELAY}");
   my @dmyhms;
   my $key;
   my $cur_rec;
@@ -134,30 +135,61 @@ sub throttle {
     $rec->{FIRST} = [ @dmyhms ];
     $rec->{LAST} = [ @dmyhms ];
     $rec->{HOLD_DHMS} = $opts{HOLD_DHMS} if defined $opts{HOLD_DHMS};
-    $rec->{COUNT} = 1;
+    $rec->{COUNT} = 0;
     $LogRecords{$key} = $rec;
-    return $msg;
-  } else {
-    $cur_rec = $LogRecords{$key};
-    $cur_rec->{COUNT}++;
-    if (defined $opts{THRESHOLD} and $cur_rec->{COUNT} == $opts{THRESHOLD}) {
-      ## threshold exceeded ##
-      chomp $msg;
-      $msg = "$msg (threshold $opts{THRESHOLD} exceeded)";
-      $cur_rec->{COUNT} = 0;
-    } elsif (defined $opts{HOLD_DHMS} 
-	     and past_hold_time($cur_rec->{LAST},
-				\@dmyhms, $opts{HOLD_DHMS})) {
+  }
+
+  ## Get current record ##
+  $cur_rec = $LogRecords{$key};
+  $cur_rec->{COUNT}++;
+
+  ## delay only ##
+  if( defined $opts{DELAY} and not defined $opts{THRESHOLD} ) {
+    if( past_hold_time($cur_rec->{LAST}, [ @dmyhms ], [ @delay ]) ) {
       ## hold time exceeded ##
       chomp $msg;
       $msg = "$msg (seen $cur_rec->{COUNT} times)";
-      $cur_rec->{COUNT} = 0;
+      $cur_rec->{COUNT} = 1;
       $cur_rec->{LAST} = [ @dmyhms ];
     } else {
       $msg = '';
     }
-    $LogRecords{$key} = $cur_rec if exists($LogRecords{$key});  ## save any new values ##
+
+  ## threshold only ##
+  } elsif( defined $opts{THRESHOLD} and not defined $opts{DELAY} ) {
+    if( $cur_rec->{COUNT} == $opts{THRESHOLD}) {
+      ## threshold exceeded ##
+      chomp $msg;
+      $msg = "$msg (threshold $opts{THRESHOLD} exceeded)";
+      $cur_rec->{COUNT} = 0;
+    } else {
+      $msg = '';
+    }
+
+  ## threshold AND delay ##
+  } elsif( defined $opts{THRESHOLD} and defined $opts{DELAY} ) {
+    if( not past_hold_time($cur_rec->{LAST}, [ @dmyhms ], [ @delay ]) ) {
+      if( $cur_rec->{COUNT} == $opts{THRESHOLD} ) {
+        ## threshold exceeded during delay ##
+       chomp $msg;
+       $msg = "$msg (threshold $opts{THRESHOLD} exceeded during delay $opts{DELAY})";
+
+       ## TODO: Tenir compte du parametre repeat ici ##
+       $cur_rec->{COUNT} = 0;
+       $cur_rec->{LAST} = [ @dmyhms ];
+      } else {
+        $msg = '';
+      }
+    } else {
+      $cur_rec->{COUNT} = 1;
+      $cur_rec->{LAST} = [ @dmyhms ];
+      $msg = '';
+    }
   }
+
+  ## save any new values ##
+  $LogRecords{$key} = $cur_rec if exists($LogRecords{$key});
+
   return $msg;
 }
 
