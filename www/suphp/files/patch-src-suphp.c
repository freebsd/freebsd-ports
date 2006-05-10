--- src/suphp.c.orig	Tue Jul 13 02:43:41 2004
+++ src/suphp.c	Tue May  9 08:59:46 2006
@@ -55,7 +55,7 @@
  
  // Set secure PATH
  
- suphp_setenv("PATH", "/bin:/usr/bin", 1);
+ suphp_setenv("PATH", "%%SUPHP_PATH%%", 1);
  
  // Check for PHP_CONFIG environment variable
  
