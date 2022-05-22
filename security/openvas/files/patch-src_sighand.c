--- src/sighand.c	2022-05-19 23:34:53.324417000 -0500
+++ src/sighand.c	2022-05-19 23:35:02.138680000 -0500
@@ -119,7 +119,7 @@
   strings = backtrace_symbols (array, ret);
   g_warning ("%s", message);
 
-  for (left = 0; left < 10; left++)
+  for (left = 0; left < ret; left++)
     g_warning ("%s\n", strings[left]);
 
   g_free (strings);
