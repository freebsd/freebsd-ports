--- filter/mupdftoraster.c.orig	2016-11-23 21:36:11 UTC
+++ filter/mupdftoraster.c
@@ -50,6 +50,8 @@ MIT Open Source License  -  http://www.o
 #include <unistd.h>
 #include <errno.h>
 
+#define execvpe(a, b, c) execvp(a, b)
+
 #define PDF_MAX_CHECK_COMMENT_LINES	20
 
 #define CUPS_IPTEMPFILE "/tmp/ip-XXXXXX"
