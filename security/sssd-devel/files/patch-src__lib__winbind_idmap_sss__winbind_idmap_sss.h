--- src/lib/winbind_idmap_sss/winbind_idmap_sss.h.orig	2023-06-05 04:01:16 UTC
+++ src/lib/winbind_idmap_sss/winbind_idmap_sss.h
@@ -29,6 +29,8 @@
 #include <stdbool.h>
 
 #include <core/ntstatus.h>
+#include <unistd.h>
+#include <time.h>
 #include <ndr.h>
 #include <gen_ndr/security.h>
 
