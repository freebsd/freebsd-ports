--- main_u.c.orig	Thu Nov  4 08:31:50 2004
+++ main_u.c	Thu Nov  4 08:32:08 2004
@@ -29,9 +29,7 @@
 #include <fcntl.h>
 #include <io.h>
 #endif /* __dos */
-#if defined(__STDC_ISO_10646__)
 #include <locale.h>
-#endif /* __STDC_ISO_10646__ */
 #if defined(N_PLAT_NLM)
 #if !defined(_VA_LIST)
 #include "NW-only/nw_os.h"
