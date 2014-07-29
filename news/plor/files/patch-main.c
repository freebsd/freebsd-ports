diff -ur plor-0.3.1/main.c plor-new/main.c
--- plor-0.3.1/main.c	Thu May  1 11:38:35 1997
+++ main.c	Thu Jul  3 12:20:45 1997
@@ -28,7 +28,7 @@
 #include <stdio.h>
 #include <string.h>
 #include <stdlib.h>
-#include <getopt.h>
+#include <unistd.h>
 
 /* will be included when we will have locale support
 #include <locale.h>
