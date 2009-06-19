--- ./Makefile.PL.orig	2009-06-18 18:18:38.664731991 -0400
+++ ./Makefile.PL	2009-06-18 18:18:23.000000000 -0400
@@ -20,7 +20,7 @@
 build_requires  'FindBin'         => undef;
 
 # Scripts I install
-prompt_script('script/Markdown.pl');
-prompt_script('script/MultiMarkdown.pl');
+#prompt_script('script/Markdown.pl');
+#prompt_script('script/MultiMarkdown.pl');
 
 WriteAll;
