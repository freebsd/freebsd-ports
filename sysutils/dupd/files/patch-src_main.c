--- src/main.c.orig	2018-04-08 20:02:52 UTC
+++ src/main.c
@@ -141,19 +141,8 @@ static void show_help()
  */
 static void show_usage()
 {
+  system("/usr/bin/man dupd");
   show_banner();
-
-#ifndef __APPLE__
-  char * p = &_binary_man_dupd_start;
-  while (p != &_binary_man_dupd_end) {
-    putchar(*p++);
-  }
-#else
-  printf("Usage documentation not available on Darwin!\n");
-  printf("\n");
-  printf("Alternatively, refer to the document here:\n");
-  printf("https://github.com/jvirkki/dupd\n");
-#endif
 }
 
 
