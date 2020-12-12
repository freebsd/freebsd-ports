diff --git src/lib/winbind_idmap_sss/winbind_idmap_sss.h src/lib/winbind_idmap_sss/winbind_idmap_sss.h
index 868049fff..cb1604ef1 100644
--- src/lib/winbind_idmap_sss/winbind_idmap_sss.h
+++ src/lib/winbind_idmap_sss/winbind_idmap_sss.h
@@ -29,6 +29,8 @@
 #include <stdbool.h>
 
 #include <core/ntstatus.h>
+#include <unistd.h>
+#include <time.h>
 #include <ndr.h>
 #include <gen_ndr/security.h>
 
