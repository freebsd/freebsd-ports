--- scan/sane/http.c.orig	2023-06-02 08:02:36 UTC
+++ scan/sane/http.c
@@ -36,6 +36,7 @@
 #include <string.h>
 #include <syslog.h>
 #include <ctype.h>
+#include <unistd.h>
 #include "hpmud.h"
 #include "http.h"
 
