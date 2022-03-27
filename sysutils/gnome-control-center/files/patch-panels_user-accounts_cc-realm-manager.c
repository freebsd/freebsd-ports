Fix for Heimdal (versus MIT).

Index: panels/user-accounts/cc-realm-manager.c
--- panels/user-accounts/cc-realm-manager.c.orig
+++ panels/user-accounts/cc-realm-manager.c
@@ -22,7 +22,7 @@
 
 #include "cc-realm-manager.h"
 
-#include <krb5/krb5.h>
+#include <krb5.h>
 
 #include <glib.h>
 #include <glib/gi18n.h>
@@ -637,8 +637,10 @@ login_perform_kinit (krb5_context k5,
         code = krb5_get_init_creds_opt_alloc (k5, &opts);
         g_return_val_if_fail (code == 0, code);
 
+#ifdef HAVE_KRB5_GET_INIT_CREDS_OPT_SET_OUT_CCACHE
         code = krb5_get_init_creds_opt_set_out_ccache (k5, opts, ccache);
         g_return_val_if_fail (code == 0, code);
+#endif
 
         code = krb5_get_init_creds_password (k5, &creds, principal,
                                              (char *)password,
