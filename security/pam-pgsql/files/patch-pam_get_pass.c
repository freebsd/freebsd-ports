--- pam_get_pass.c.orig	Mon Jan 14 17:45:55 2002
+++ pam_get_pass.c	Sat Nov 23 20:26:10 2002
@@ -34,68 +34,5 @@
 #include <stdlib.h>
 #include <security/pam_modules.h>
-#include "pam_mod_misc.h"
-
-static int   pam_conv_pass(pam_handle_t *, const char *, int);
-
-static int
-pam_conv_pass(pam_handle_t *pamh, const char *prompt, int options)
-{
-    int retval;
-    const void *item;
-    const struct pam_conv *conv;
-    struct pam_message msg;
-    const struct pam_message *msgs[1];
-    struct pam_response *resp;
-
-    if ((retval = pam_get_item(pamh, PAM_CONV, &item)) !=
-        PAM_SUCCESS)
-        return retval;
-    conv = (const struct pam_conv *)item;
-    msg.msg_style = options & PAM_OPT_ECHO_PASS ?
-        PAM_PROMPT_ECHO_ON : PAM_PROMPT_ECHO_OFF;
-    msg.msg = prompt;
-    msgs[0] = &msg;
-    if ((retval = conv->conv(1, msgs, &resp, conv->appdata_ptr)) !=
-        PAM_SUCCESS)
-        return retval;
-    if ((retval = pam_set_item(pamh, PAM_AUTHTOK, resp[0].resp)) !=
-        PAM_SUCCESS)
-        return retval;
-    memset(resp[0].resp, 0, strlen(resp[0].resp));
-    free(resp[0].resp);
-    free(resp);
-    return PAM_SUCCESS;
-}
-
-int
-pam_get_pass(pam_handle_t *pamh, const char **passp, const char *prompt,
-    int options)
-{
-    int retval;
-    const void *item = NULL;
-
-    /*
-     * Grab the already-entered password if we might want to use it.
-     */
-    if (options & (PAM_OPT_TRY_FIRST_PASS | PAM_OPT_USE_FIRST_PASS)) {
-        if ((retval = pam_get_item(pamh, PAM_AUTHTOK, &item)) !=
-            PAM_SUCCESS)
-            return retval;
-    }
-
-    if (item == NULL) {
-        /* The user hasn't entered a password yet. */
-        if (options & PAM_OPT_USE_FIRST_PASS)
-            return PAM_AUTH_ERR;
-        /* Use the conversation function to get a password. */
-        if ((retval = pam_conv_pass(pamh, prompt, options)) !=
-            PAM_SUCCESS ||
-            (retval = pam_get_item(pamh, PAM_AUTHTOK, &item)) !=
-            PAM_SUCCESS)
-            return retval;
-    }
-    *passp = (const char *)item;
-    return PAM_SUCCESS;
-}
+#include <security/pam_mod_misc.h>
 
 int
@@ -125,8 +62,11 @@
         return retval;
 
+#ifdef PAM_AUTHTOK_RECOVER_ERR
+#define PAM_AUTHTOK_RECOVERY_ERR PAM_AUTHTOK_RECOVER_ERR
+#endif
     if(!resp)
-        return PAM_AUTHTOK_RECOVER_ERR;
+        return PAM_AUTHTOK_RECOVERY_ERR;
     if(strcmp(resp[0].resp, resp[1].resp) != 0)
-        return PAM_AUTHTOK_RECOVER_ERR;
+        return PAM_AUTHTOK_RECOVERY_ERR;
 
     retval = pam_set_item(pamh, PAM_AUTHTOK, resp[0].resp);
