--- misc/openvas-krb5.h	2024-12-22 00:19:13.309593000 -0800
+++ misc/openvas-krb5.h	2024-12-22 00:20:45.473987000 -0800
@@ -1,4 +1,8 @@
+#if defined(__FreeBSD__)
+#include <krb5.h>
+#else
 #include <krb5/krb5.h>
+#endif
 #include <stdbool.h>
 #ifndef OPENVAS_KRB5
 #define OPENVAS_KRB5 1
