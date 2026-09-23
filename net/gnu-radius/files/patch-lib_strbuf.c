--- lib/strbuf.c.orig	2026-09-23 08:58:09 UTC
+++ lib/strbuf.c
@@ -23,6 +23,7 @@
 #include <stdlib.h>
 #include <stdio.h>
 #include <ctype.h>
+#include <sys/types.h>
 #include <radius/mem.h>
 #include <radius/list.h>
 #include <radius/strbuf.h>
