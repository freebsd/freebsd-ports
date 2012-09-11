--- lib/ivykis/lib/iv_tls.c.old
+++ lib/ivykis/lib/iv_tls.c
@@ -25,7 +25,7 @@
 #include "iv_private.h"
 
 static int inited;
-static off_t last_offset;
+static int last_offset = (sizeof(struct iv_state) + 15) & ~15;
 static struct iv_list_head iv_tls_users = IV_LIST_HEAD_INIT(iv_tls_users);
 
 void iv_tls_user_register(struct iv_tls_user *itu)
