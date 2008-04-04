--- Makefile.PL.orig	2008-04-03 21:43:19.000000000 -0300
+++ Makefile.PL	2008-04-03 21:43:29.000000000 -0300
@@ -19,8 +19,8 @@
 build_requires  'FindBin'         => undef;
 
 # Scripts I install
-prompt_script('script/Markdown.pl');
-prompt_script('script/MultiMarkdown.pl');
+#prompt_script('script/Markdown.pl');
+#prompt_script('script/MultiMarkdown.pl');
 
 auto_install;
 WriteAll;
