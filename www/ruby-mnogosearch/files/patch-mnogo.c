--- mnogo.c.orig	Sat Sep 14 03:00:19 2002
+++ mnogo.c	Sun Sep 15 18:14:53 2002
@@ -92,6 +92,7 @@
 #define UDM_ISPELL_TYPE_DB	3
 #define UDM_ISPELL_TYPE_SERVER	4
 
+#include <sys/types.h>
 #include <udm_config.h>
 #include <udmsearch.h>
 
