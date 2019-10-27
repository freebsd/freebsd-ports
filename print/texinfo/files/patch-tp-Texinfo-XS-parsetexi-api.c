--- tp/Texinfo/XS/parsetexi/api.c.orig	2019-08-25 17:11:45 UTC
+++ tp/Texinfo/XS/parsetexi/api.c
@@ -25,7 +25,9 @@
 
 #undef context
 
+#if defined(HAVE_LIBINTL_H)
 #include <libintl.h>
+#endif
 
 #include <stdlib.h>
 #include <stdio.h>
