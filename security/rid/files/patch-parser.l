--- parser.l.orig	Fri Jan 28 11:37:32 2000
+++ parser.l	Sun Feb 13 18:32:00 2000
@@ -1,4 +1,5 @@
 %{
+#include <sys/types.h>
 #include <stdio.h>
 #include <stdlib.h>
 #include <strings.h>
