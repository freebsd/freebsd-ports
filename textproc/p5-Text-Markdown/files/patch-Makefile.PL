--- Makefile.PL.orig	2009-10-14 09:56:44.000000000 +0800
+++ Makefile.PL	2009-10-14 09:57:26.000000000 +0800
@@ -22,6 +22,6 @@
 build_requires  'FindBin'         => undef;
 
 # Scripts I install
-prompt_script('script/Markdown.pl');
+#prompt_script('script/Markdown.pl');
 
 WriteAll;
