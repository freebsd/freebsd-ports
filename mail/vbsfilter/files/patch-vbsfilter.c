--- vbsfilter-1.9.c.orig	Mon Aug 13 21:11:36 2001
+++ vbsfilter-1.9.c	Mon Aug 13 21:15:05 2001
@@ -9,6 +9,10 @@
 #include <stdio.h>
 #include <string.h>
 #include <sysexits.h>
+#include <ctype.h>
+#include <stdlib.h>
+#include <netdb.h>
+#include <unistd.h>
 #include "libmilter/mfapi.h"
 
 /*
