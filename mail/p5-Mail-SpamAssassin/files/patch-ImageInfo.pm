--- ImageInfo.pm.orig	Tue May  1 09:54:09 2007
+++ lib/Mail/SpamAssassin/Plugin/ImageInfo.pm	Thu May  3 16:08:29 2007
@@ -1,10 +1,9 @@
 # <@LICENSE>
-# Licensed to the Apache Software Foundation (ASF) under one or more
-# contributor license agreements.  See the NOTICE file distributed with
-# this work for additional information regarding copyright ownership.
-# The ASF licenses this file to you under the Apache License, Version 2.0
-# (the "License"); you may not use this file except in compliance with
-# the License.  You may obtain a copy of the License at:
+# Copyright 2004 Apache Software Foundation
+# 
+# Licensed under the Apache License, Version 2.0 (the "License");
+# you may not use this file except in compliance with the License.
+# You may obtain a copy of the License at
 # 
 #     http://www.apache.org/licenses/LICENSE-2.0
 # 
@@ -16,6 +15,36 @@
 # </@LICENSE>
 #
 # -------------------------------------------------------
+# ImageInfo Plugin for SpamAssassin
+# Version: 0.7
+# Current Home: http://www.rulesemporium.com/plugins.htm#imageinfo
+# Created: 2006-08-02
+# Modified: 2007-01-17
+# By: Dallas Engelken <dallase@uribl.com>
+#
+# Changes: 
+#   0.7 - added image_name_regex to allow pattern matching on the image name
+#       - added support for image/pjpeg content types (progressive jpeg)
+#       - updated imageinfo.cf with a few sample rules for using image_name_regex()
+#   0.6 - fixed dems_ bug in image_size_range_
+#   0.5 - added image_named and image_to_text_ratio
+#   0.4 - added image_size_exact and image_size_range
+#   0.3 - added jpeg support
+#   0.2 - optimized by theo
+#   0.1 - added gif/png support
+#
+# Files:
+#   ImageInfo.pm (plugin)  - http://www.rulesemporium.com/plugins/ImageInfo.pm
+#   imageinfo.cf (ruleset) - http://www.rulesemporium.com/plugins/imageinfo.cf
+#   
+# Install:
+#   1) place ruleset in your local config dir
+#   2) place plugin in your plugins dir 
+#   3) add to init.pre (or v310.pre) the following line
+#      loadplugin Mail::SpamAssassin::Plugin::ImageInfo
+#           or if not in plugin dir..
+#      loadplugin Mail::SpamAssassin::Plugin::ImageInfo /path/to/plugin
+#    4) restart spamd (if necessary)
 #
 # Usage:
 #  image_count()
@@ -27,7 +56,7 @@
 #        max: optional, if specified, message must not 
 #             contain more than this number of images
 #
-#  examples
+#  image_count() examples
 # 
 #     body ONE_IMAGE  eval:image_count('all',1,1) 
 #     body ONE_OR_MORE_IMAGES  eval:image_count('all',1)
@@ -44,13 +73,24 @@
 #        max: optional, if specified, message must not
 #             contain more than this much pixel area
 #
-#  examples
+#   pixel_coverage() examples
+#
+#     body LARGE_IMAGE_AREA  eval:pixel_coverage('all',150000)  # catches any images that are 150k pixel/sq or higher
+#     body SMALL_GIF_AREA  eval:pixel_coverage('gif',1,40000)   # catches only gifs that 1 to 40k pixel/sql
+#
+#  image_name_regex()
+# 
+#     body RULENAME  eval:image_name_regex(<regex>) 
+#        regex: full quoted regexp, see examples below
+#
+#  image_name_regex() examples
+#
+#     body CG_DOUBLEDOT_GIF  eval:image_name_regex('/^\w{2,9}\.\.gif$/i') # catches double dot gifs  abcd..gif
 #
-#     body LARGE_IMAGE_AREA  eval:pixel_coverage('all',150000)
-#     body SMALL_GIF_AREA  eval:pixel_coverage('gif',1,40000)
+#  See the ruleset for more examples that arent documented here.
 #
-#  See the ruleset for ways to meta image_count() 
-#  and pixel_coverage() together.  
+#  New functions added in v0.5+ need some documentation here.  Or just 
+#  see .cf for sample rules.
 #
 # -------------------------------------------------------
 
@@ -80,6 +120,7 @@
   $self->register_eval_rule ("image_size_exact");
   $self->register_eval_rule ("image_size_range");
   $self->register_eval_rule ("image_named");
+  $self->register_eval_rule ("image_name_regex");
   $self->register_eval_rule ("image_to_text_ratio");
 
   return $self;
@@ -244,6 +285,34 @@
 
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
+}
+
+# -----------------------------------------
+
 sub image_count {
   my ($self,$pms,$body,$type,$min,$max) = @_;
   
@@ -323,7 +392,8 @@
     $self->_get_images($pms);
   }
 
-  return unless (exists $pms->{'imageinfo'}->{"dems_$type"});
+  my $name = 'dems_'.$type;
+  return unless (exists $pms->{'imageinfo'}->{$name});
 
   foreach my $dem ( keys %{$pms->{'imageinfo'}->{"dems_$type"}}) {
     my ($h,$w) = split(/x/,$dem);
