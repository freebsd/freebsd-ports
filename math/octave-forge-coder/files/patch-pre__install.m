--- pre_install.m.orig	2025-03-30 17:42:54 UTC
+++ pre_install.m
@@ -1,6 +1,6 @@ function pre_install (in)
 function pre_install (in)
 
-  disp ('Installing package coder. It may take a while. Please wait ...')
+  disp ('Building package coder. It may take a while. Please wait ...')
 
   basedir = fileparts(mfilename ('fullpath'));
   sourcedir = format_path(fullfile(basedir, 'src'));
