--- Reflow.pm.orig	2009-02-07 14:24:01 UTC
+++ Reflow.pm
@@ -32,7 +32,7 @@
 
 $Text::Reflow::VERSION = "1.06";
 
-bootstrap Text::Reflow $Text::Reflow::VERSION;
+#bootstrap Text::Reflow $Text::Reflow::VERSION;
 
 # Preloaded methods go here.
 
@@ -41,17 +41,17 @@
 # bootstrap Text::Reflow $VERSION;
 # above, and take the _ from the front of this perl version:
 
-sub _reflow_trial($$$$$$$$$$) {
+sub reflow_trial($$$$$$$$$$) {
   my ($optimum, $maximum, $wordcount,
       $penaltylimit, $semantic, $shortlast,
       $word_len, $space_len, $extra, $result) = @_;
   my ($lastbreak, @linkbreak);
   my ($j, $k, $interval, $penalty, @totalpenalty, $bestsofar);
   my (@best_linkbreak, $best_lastbreak, $opt);
-  my @optimum	= unpack("N*", pack("H*", $optimum));
-  my @word_len	= unpack("N*", pack("H*", $word_len));
-  my @space_len	= unpack("N*", pack("H*", $space_len));
-  my @extra	= unpack("N*", pack("H*", $extra));
+  my @optimum	= unpack("j*", pack("H*", $optimum));
+  my @word_len	= unpack("j*", pack("H*", $word_len));
+  my @space_len	= unpack("j*", pack("H*", $space_len));
+  my @extra	= unpack("j*", pack("H*", $extra));
   my $best = $penaltylimit * 21;
   foreach $opt (@optimum) {
     @linkbreak = ();
@@ -101,7 +101,7 @@
     }
   } # Next $opt
   # Return the best breaks:
-  $result = unpack("H*", pack("N*", ($best_lastbreak, @best_linkbreak)));
+  $result = unpack("H*", pack("j*", ($best_lastbreak, @best_linkbreak)));
   return($result);
 }
 
@@ -511,14 +511,14 @@
   $linkbreak[$wordcount] = 0;
   # Create space for the result:
   my $result = " " x (($wordcount + 2) * 8);
-  $result = reflow_trial(unpack("H*", pack("N*", @$optimum)),
+  $result = reflow_trial(unpack("H*", pack("j*", @$optimum)),
 			 $maximum, $wordcount,
 			 $penaltylimit, $semantic, $shortlast,
-			 unpack("H*", pack("N*", @word_len)),
-			 unpack("H*", pack("N*", @space_len)),
-			 unpack("H*", pack("N*", @extra)),
+			 unpack("H*", pack("j*", @word_len)),
+			 unpack("H*", pack("j*", @space_len)),
+			 unpack("H*", pack("j*", @extra)),
 			 $result);
-  @linkbreak = unpack("N*", pack("H*", $result));
+  @linkbreak = unpack("j*", pack("H*", $result));
   # Convert @linkbreak from unsigned to signed:
   @linkbreak = map { $_ > 0xF0000000 ? -((0xFFFFFFFF - $_) + 1) : $_ + 0 } @linkbreak;
   $lastbreak = shift(@linkbreak);
