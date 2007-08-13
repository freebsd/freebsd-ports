--- lib/Mail/SpamAssassin/Plugin/ImageInfo.pm.orig	2007-08-08 05:19:14.000000000 -0800
+++ lib/Mail/SpamAssassin/Plugin/ImageInfo.pm	2007-08-11 12:20:22.000000000 -0800
@@ -49,6 +49,11 @@
 #     body LARGE_IMAGE_AREA  eval:pixel_coverage('all',150000)
 #     body SMALL_GIF_AREA  eval:pixel_coverage('gif',1,40000)
 #
+#  image_name_regex() examples
+#
+#     body CG_DOUBLEDOT_GIF  eval:image_name_regex('/^\w{2,9}\.\.gif$/i') # catches double dot gifs  abcd..gif
+#
+#
 #  See the ruleset for ways to meta image_count() 
 #  and pixel_coverage() together.  
 #
@@ -80,6 +85,7 @@
   $self->register_eval_rule ("image_size_exact");
   $self->register_eval_rule ("image_size_range");
   $self->register_eval_rule ("image_named");
+  $self->register_eval_rule ("image_name_regex");
   $self->register_eval_rule ("image_to_text_ratio");
 
   return $self;
@@ -275,6 +281,33 @@
 }
 
 # -----------------------------------------
+sub image_name_regex {
+  my ($self,$pms,$body,$re) = @_;
+  return unless (defined $re);
+
+  # make sure we have image data read in.
+  if (!exists $pms->{'imageinfo'}) {
+    $self->_get_images($pms);
+  }
+
+  return 0 unless (exists $pms->{'imageinfo'}->{"names_all"});
+
+  my $hit = 0;
+  foreach my $name (keys %{$pms->{'imageinfo'}->{"names_all"}}) {
+    dbg("imageinfo: checking image named $name against regex $re");
+    my $eval = 'if (q{'.$name.'} =~  ' . $re . ') {  $hit = 1; } ';
+    eval $eval;
+    dbg("imageinfo: error in regex $re - $@") if $@;
+    if ($hit) {
+      dbg("imageinfo: image_name_regex hit on $name");
+      return 1;
+    }
+  }
+  return 0;
+
+   }
+
+# -----------------------------------------
 
 sub image_to_text_ratio {
   my ($self,$pms,$body,$type,$min,$max) = @_;
