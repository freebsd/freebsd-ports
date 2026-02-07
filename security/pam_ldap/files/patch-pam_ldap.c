--- pam_ldap.c.orig	2010-12-17 14:36:11.105528000 -0500
+++ pam_ldap.c	2010-12-17 14:38:42.000000000 -0500
@@ -131,12 +131,7 @@
 #include "pam_ldap.h"
 #include "md5.h"
 
-#if defined(HAVE_SECURITY_PAM_MISC_H) || defined(HAVE_PAM_PAM_MISC_H) || defined(OPENPAM)
- /* FIXME: is there something better to check? */
 #define CONST_ARG const
-#else
-#define CONST_ARG
-#endif
 
 #ifndef HAVE_LDAP_MEMFREE
 #define ldap_memfree(x)	free(x)
@@ -3411,7 +3406,7 @@ pam_sm_authenticate (pam_handle_t * pamh
   int rc;
   const char *username;
   char *p;
-  int use_first_pass = 0, try_first_pass = 0, ignore_flags = 0;
+  int use_first_pass = 0, try_first_pass = 0, ignore_flags = 0, migrate = 0;
   int i;
   pam_ldap_session_t *session = NULL;
   const char *configFile = NULL;
@@ -3432,6 +3427,8 @@ pam_sm_authenticate (pam_handle_t * pamh
 	;
       else if (!strcmp (argv[i], "debug"))
 	;
+      else if (!strcmp (argv[i], "migrate"))
+        migrate = 1;
       else
 	syslog (LOG_ERR, "illegal option %s", argv[i]);
     }
@@ -3445,6 +3442,22 @@ pam_sm_authenticate (pam_handle_t * pamh
     return rc;
 
   rc = pam_get_item (pamh, PAM_AUTHTOK, (CONST_ARG void **) &p);
+  /* start of migrate facility in "pam_ldap authentication" */
+  if (migrate==1 && rc==PAM_SUCCESS)
+    {
+      /* check if specified username exists in LDAP */
+      if (_get_user_info(session,username)==PAM_SUCCESS)
+        {
+          /*
+             overwrite old LDAP userPassword with a new password
+             obtained during pam authentication process
+             - rootbinddn and ldap.secret must be set
+          */
+          rc=_update_authtok(pamh,session,username,NULL,p);
+          return PAM_IGNORE;
+        }
+    }
+  /* end of migrate facility in "pam_ldap authentication" */
   if (rc == PAM_SUCCESS && (use_first_pass || try_first_pass))
     {
       rc = _do_authentication (pamh, session, username, p);
@@ -3721,7 +3734,7 @@ pam_sm_chauthtok (pam_handle_t * pamh, i
 	  if (curpass == NULL)
 	    return PAM_MAXTRIES;	/* maximum tries exceeded */
 	  else
-	    pam_set_item (pamh, PAM_OLDAUTHTOK, (void *) curpass);
+	    pam_set_item (pamh, PAM_OLDAUTHTOK, (void *) strdup(curpass));
 	}
       else
 	{
