--- tests/gpg/t-eventloop.c.orig	Fri Aug 30 17:22:54 2002
+++ tests/gpg/t-eventloop.c	Fri Aug 30 17:21:50 2002
@@ -24,6 +24,7 @@
 #include <string.h>
 #include <assert.h>
 #include <errno.h>
+#include <sys/types.h>
 #include <sys/select.h>
 
 #include <gpgme.h>
