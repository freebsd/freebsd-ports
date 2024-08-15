--- src/lib/winbind_idmap_sss/winbind_idmap_sss.h.orig	2020-03-17 13:31:28 UTC
+++ src/lib/winbind_idmap_sss/winbind_idmap_sss.h
@@ -29,6 +29,8 @@
 #include <stdbool.h>
 
 #include <core/ntstatus.h>
+#include <unistd.h>
+#include <time.h>
 #include <ndr.h>
 #include <gen_ndr/security.h>
 
