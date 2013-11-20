$OpenBSD: patch-src_ck-manager_c,v 1.3 2011/04/28 13:08:33 ajacoutot Exp $

XXX revert 4f88228f31a63c026c424a92827f26ad7535275c
The Kit people assume the world runs Linux and PAM, see
https://bugs.freedesktop.org/show_bug.cgi?id=28377

--- src/ck-manager.c.orig	Tue Oct 26 16:34:03 2010
+++ src/ck-manager.c	Sat Dec  4 12:18:29 2010
@@ -1659,175 +1659,13 @@ open_session_for_leader (CkManager             *manage
         dbus_g_method_return (context, cookie);
 }
 
-enum {
-        PROP_STRING,
-        PROP_BOOLEAN,
-};
-
-#define CK_TYPE_PARAMETER_STRUCT (dbus_g_type_get_struct ("GValueArray", \
-                                                          G_TYPE_STRING,  \
-                                                          G_TYPE_VALUE, \
-                                                          G_TYPE_INVALID))
-
-static gboolean
-_get_parameter (GPtrArray  *parameters,
-                const char *name,
-                int         prop_type,
-                gpointer   *value)
-{
-        gboolean ret;
-        int      i;
-
-        if (parameters == NULL) {
-                return FALSE;
-        }
-
-        ret = FALSE;
-
-        for (i = 0; i < parameters->len && ret == FALSE; i++) {
-                gboolean    res;
-                GValue      val_struct = { 0, };
-                char       *prop_name;
-                GValue     *prop_val;
-
-                g_value_init (&val_struct, CK_TYPE_PARAMETER_STRUCT);
-                g_value_set_static_boxed (&val_struct, g_ptr_array_index (parameters, i));
-
-                res = dbus_g_type_struct_get (&val_struct,
-                                              0, &prop_name,
-                                              1, &prop_val,
-                                              G_MAXUINT);
-                if (! res) {
-                        g_debug ("Unable to extract parameter input");
-                        goto cont;
-                }
-
-                if (prop_name == NULL) {
-                        g_debug ("Skipping NULL parameter");
-                        goto cont;
-                }
-
-                if (strcmp (prop_name, name) != 0) {
-                        goto cont;
-                }
-
-                switch (prop_type) {
-                case PROP_STRING:
-                        if (value != NULL) {
-                                *value = g_value_dup_string (prop_val);
-                        }
-                        break;
-                case PROP_BOOLEAN:
-                        if (value != NULL) {
-                                *(gboolean *)value = g_value_get_boolean (prop_val);
-                        }
-                        break;
-                default:
-                        g_assert_not_reached ();
-                        break;
-                }
-
-                ret = TRUE;
-
-        cont:
-                g_free (prop_name);
-                if (prop_val != NULL) {
-                        g_value_unset (prop_val);
-                        g_free (prop_val);
-                }
-        }
-
-        return ret;
-}
-
-static gboolean
-_verify_login_session_id_is_local (CkManager  *manager,
-                                   const char *login_session_id)
-{
-        GHashTableIter iter;
-        const char    *id;
-        CkSession     *session;
-
-        g_return_val_if_fail (CK_IS_MANAGER (manager), FALSE);
-
-        /* If any local session exists for the given login session id
-           then that means a trusted party has vouched for the
-           original login */
-
-        g_debug ("Looking for local sessions for login-session-id=%s", login_session_id);
-
-        session = NULL;
-        g_hash_table_iter_init (&iter, manager->priv->sessions);
-        while (g_hash_table_iter_next (&iter, (gpointer *)&id, (gpointer *)&session)) {
-                if (session != NULL) {
-                        gboolean is_local;
-                        char    *sessid;
-
-                        sessid = NULL;
-                        g_object_get (session,
-                                      "login-session-id", &sessid,
-                                      "is-local", &is_local,
-                                      NULL);
-                        if (g_strcmp0 (sessid, login_session_id) == 0 && is_local) {
-                                g_debug ("CkManager: found is-local=true on %s", id);
-                                return TRUE;
-                        }
-                }
-        }
-
-        return FALSE;
-}
-
 static void
-add_param_boolean (GPtrArray  *parameters,
-                   const char *key,
-                   gboolean    value)
-{
-        GValue   val = { 0, };
-        GValue   param_val = { 0, };
-
-        g_value_init (&val, G_TYPE_BOOLEAN);
-        g_value_set_boolean (&val, value);
-        g_value_init (&param_val, CK_TYPE_PARAMETER_STRUCT);
-        g_value_take_boxed (&param_val,
-                            dbus_g_type_specialized_construct (CK_TYPE_PARAMETER_STRUCT));
-        dbus_g_type_struct_set (&param_val,
-                                0, key,
-                                1, &val,
-                                G_MAXUINT);
-        g_value_unset (&val);
-
-        g_ptr_array_add (parameters, g_value_get_boxed (&param_val));
-}
-
-static void
 verify_and_open_session_for_leader (CkManager             *manager,
                                     CkSessionLeader       *leader,
-                                    GPtrArray             *parameters,
+                                    const GPtrArray       *parameters,
                                     DBusGMethodInvocation *context)
 {
-        /* Only allow a local session if originating from an existing
-           local session.  Effectively this means that only trusted
-           parties can create local sessions. */
-
-        g_debug ("CkManager: verifying session for leader");
-
-        if (parameters != NULL && ! _get_parameter (parameters, "is-local", PROP_BOOLEAN, NULL)) {
-                gboolean is_local;
-                char    *login_session_id;
-
-                g_debug ("CkManager: is-local has not been set, will inherit from existing login-session-id if available");
-
-                is_local = FALSE;
-
-                if (_get_parameter (parameters, "login-session-id", PROP_STRING, (gpointer *) &login_session_id)) {
-                        is_local = _verify_login_session_id_is_local (manager, login_session_id);
-                        g_debug ("CkManager: found is-local=%s", is_local ? "true" : "false");
-                }
-
-                add_param_boolean (parameters, "is-local", is_local);
-        }
-
+        /* for now don't bother verifying since we protect OpenSessionWithParameters */
         open_session_for_leader (manager,
                                  leader,
                                  parameters,
