--- misc/openvas-krb5.c	2024-12-22 00:19:01.961816000 -0800
+++ misc/openvas-krb5.c	2024-12-22 00:20:50.556489000 -0800
@@ -3,7 +3,11 @@
 #include <ctype.h>
 #include <gssapi/gssapi.h>
 #include <gssapi/gssapi_krb5.h>
+#if defined(__FreeBSD__)
+#include <krb5.h>
+#else
 #include <krb5/krb5.h>
+#endif
 #include <stdbool.h>
 #include <stdio.h>
 #include <stdlib.h>
