Fixes the following build error with clang:

ag-manager.c:503:16: error: implicit conversion from enumeration type 'AgAccountsError' to different enumeration type 'AgError' [-Werror,-Wenum-conversion]
        code = AG_ACCOUNTS_ERROR_DB_LOCKED;
             ~ ^~~~~~~~~~~~~~~~~~~~~~~~~~~
ag-manager.c:508:16: error: implicit conversion from enumeration type 'AgAccountsError' to different enumeration type 'AgError' [-Werror,-Wenum-conversion]
        code = AG_ACCOUNTS_ERROR_DB;
             ~ ^~~~~~~~~~~~~~~~~~~~

Sent upstream: https://gitlab.com/accounts-sso/libaccounts-glib/merge_requests/3
--- libaccounts-glib/ag-manager.c
+++ libaccounts-glib/ag-manager.c
@@ -490,7 +490,7 @@ static void
 set_error_from_db (AgManager *manager)
 {
     AgManagerPrivate *priv = manager->priv;
-    AgError code;
+    AgAccountsError code;
     GError *error;
 
     switch (sqlite3_errcode (priv->db))
