--- pam_pgsql.c.orig	Tue Aug 13 18:31:40 2002
+++ pam_pgsql.c	Tue Aug 13 18:33:05 2002
@@ -23,7 +23,7 @@
 #define PAM_SM_ACCOUNT
 #define PAM_SM_PASSWORD
 #include <security/pam_modules.h>
-#include "pam_mod_misc.h"
+#include <security/pam_mod_misc.h>
 
 #define PASSWORD_PROMPT         "Password: "
 #define PASSWORD_PROMPT_NEW	    "New password: "
@@ -31,16 +31,15 @@
 #define CONF                    "/etc/pam_pgsql.conf"
 
 #define DBGLOG(x...)  if(options->debug) {                          \
-                          openlog("PAM_pgsql", LOG_PID, LOG_AUTH);  \
                           syslog(LOG_DEBUG, ##x);                   \
-                          closelog();                               \
                       }
 #define SYSLOG(x...)  do {                                          \
-                          openlog("PAM_pgsql", LOG_PID, LOG_AUTH);  \
                           syslog(LOG_INFO, ##x);                    \
-                          closelog();                               \
                       } while(0);
 
+int pam_get_confirm_pass(pam_handle_t *, const char **, const char *, const char *, int);
+
+
 typedef enum {
     PW_CLEAR = 1,
     PW_MD5,
@@ -61,32 +60,36 @@
     int debug;
 };
 
-/* private: parse and set the specified string option */
-static void
-set_module_option(const char *option, struct module_options *options)
-{
-    char *buf, *eq;
-    char *val, *end;
-
-    if(!option || !*option)
-        return;
+enum {
+    PAM_DATABASE = PAM_OPT_STD_MAX,
+    PAM_TABLE,
+    PAM_DB_HOST,
+    PAM_DB_USER,
+    PAM_DB_PASSWORD,
+    PAM_USER_COLUMN,
+    PAM_PWD_COLUMN,
+    PAM_EXPIRED_COLUMN,
+    PAM_NEWTOK_COLUMN,
+    PAM_PW_TYPE
+};
 
-    buf = strdup(option);
+static struct opttab other_options[] = {
+    {"database", PAM_DATABASE},
+    {"table", PAM_TABLE},
+    {"host", PAM_DB_HOST},
+    {"user", PAM_DB_USER},
+    {"password", PAM_DB_PASSWORD},
+    {"user_column", PAM_USER_COLUMN},
+    {"pwd_column", PAM_PWD_COLUMN},
+    {"expired_column", PAM_EXPIRED_COLUMN},
+    {"newtok_column", PAM_NEWTOK_COLUMN},
+    {"pw_type", PAM_PW_TYPE},
+    {NULL, 0}
+};
 
-    if((eq = strchr(buf, '='))) {
-        end = eq - 1;
-        val = eq + 1;
-        if(end <= buf || !*val)
-            return;
-        while(end > buf && isspace(*end))
-            end--;
-        end++;
-        *end = '\0';
-        while(*val && isspace(*val))
-            val++;
-    } else {
-        val = NULL;
-    }
+/* set the specified string option */
+static void
+set_option_val(struct module_options * options, const char * buf, char * val) {
 
     DBGLOG("setting option: %s=>%s\n", buf, val);
 
@@ -118,17 +121,48 @@
     } else if(!strcmp(buf, "debug")) {
         options->debug = 1;
     }
+}
+
+/* private: parse the specified string option */
+static void
+set_module_option(const char *option, struct module_options *options)
+{
+    char *buf, *eq;
+    char *val, *end;
+
+    if(!option || !*option)
+        return;
+
+    buf = strdup(option);
+
+    if((eq = strchr(buf, '='))) {
+        end = eq - 1;
+        val = eq + 1;
+        if(end <= buf || !*val)
+            return;
+        while(end > buf && isspace(*end))
+            end--;
+        end++;
+        *end = '\0';
+        while(*val && isspace(*val))
+            val++;
+    } else {
+        val = NULL;
+    }
+
+    set_option_val(options, buf, val);
 
     free(buf);
 }
 
 /* private: read module options from file or commandline */
 static int 
-get_module_options(int argc, const char **argv, struct module_options **options)
+get_module_options(int argc, const char **argv, struct module_options **options, struct options * pam_options)
 {
     int i, rc;
     FILE *fp;
     struct module_options *opts;
+    char *c;
 
     opts = (struct module_options *)malloc(sizeof *opts);
     bzero(opts, sizeof(*opts));
@@ -154,11 +188,11 @@
         fclose(fp);
     }
 
-    for(i = 0; i < argc; i++) {
-        if(pam_std_option(&rc, argv[i]) == 0)
-            continue;
-        set_module_option(argv[i], opts);
+    for(i = PAM_OPT_STD_MAX; i <= PAM_PW_TYPE; i++) {
+	if (pam_test_option(pam_options, i, &c))
+	    set_option_val(opts, other_options[i - PAM_OPT_STD_MAX].name, c);
     }
+
     *options = opts;
 
     return rc;
@@ -257,7 +291,7 @@
     free(conn_str);
 
     if(PQstatus(conn) != CONNECTION_OK) {
-        SYSLOG("PostgreSQL connection failed: '%s'", PQerrorMessage(conn));
+        SYSLOG("PostgreSQL connection failed: '%s' '%s'", PQerrorMessage(conn), conn_str);
         return NULL;
     }
 
@@ -412,7 +446,6 @@
     user_s = malloc(ulen);
 
     sqlescape(user, user_s, strlen(user));
-DBGLOG(user_s);
 
     DBGLOG("query: SELECT %s FROM %s WHERE %s='%s'", options->pwd_column, options->table, options->user_column, user);
     if(pg_exec(options, conn, &res, "SELECT %s FROM %s WHERE %s='%s'",
@@ -463,13 +496,17 @@
 pam_sm_authenticate(pam_handle_t *pamh, int flags, int argc, const char **argv)
 {
     struct module_options *options;
+    struct options  pam_options;
     const char *user, *password;
     int rc, std_flags;
 
     if((rc = pam_get_user(pamh, &user, NULL)) != PAM_SUCCESS)
         return rc;
 
-    std_flags = get_module_options(argc, argv, &options);
+    pam_std_option(&pam_options, other_options, argc, argv);
+
+    std_flags = get_module_options(argc, argv, &options, &pam_options);
+    
     if(options_valid(options) != 0) {
         free_module_options(options);
         return PAM_AUTH_ERR;
@@ -477,18 +514,19 @@
 
     DBGLOG("attempting to authenticate: %s", user);
 
-    if((rc = pam_get_pass(pamh, &password, PASSWORD_PROMPT, std_flags) 
+    if((rc = pam_get_pass(pamh, &password, PASSWORD_PROMPT, &pam_options) 
         != PAM_SUCCESS)) {
         free_module_options(options);
         return rc;
     }
+    DBGLOG("received : user: '%s', pass: '%s'", user, password);
 
     if((rc = auth_verify_password(user, password, options)) != PAM_SUCCESS) {
         free_module_options(options);
         return rc;
     }
 
-    SYSLOG("(%s) user %s authenticated.", pam_get_service(pamh), user);
+    SYSLOG("user %s authenticated.", user);
     free_module_options(options);
 
     return PAM_SUCCESS;
@@ -500,13 +538,16 @@
                             const char **argv)
 {
     struct module_options *options;
+    struct options  pam_options;
     const char *user;
     char *user_s;
     int rc, ulen;
     PGconn *conn;
     PGresult *res;
 
-    get_module_options(argc, argv, &options);
+    pam_std_option(&pam_options, other_options, argc, argv);
+
+    get_module_options(argc, argv, &options, &pam_options);
     if(options_valid(options) != 0) {
         free_module_options(options);
         return PAM_AUTH_ERR;
@@ -590,13 +631,16 @@
 pam_sm_chauthtok(pam_handle_t *pamh, int flags, int argc, const char **argv)
 {
     struct module_options *options;
+    struct options  pam_options;
     int rc, std_flags, ulen;
     const char *user, *pass, *newpass;
     char *newpass_crypt, *user_s;
     PGconn *conn;
     PGresult *res;
 
-    std_flags = get_module_options(argc, argv, &options);
+    pam_std_option(&pam_options, other_options, argc, argv);
+
+    std_flags = get_module_options(argc, argv, &options, &pam_options);
     if(options_valid(options) != 0) {
         free_module_options(options);
         return PAM_AUTH_ERR;
@@ -614,7 +658,7 @@
 
     if(flags & PAM_PRELIM_CHECK) {
         /* at this point, this is the first time we get called */
-        if((rc = pam_get_pass(pamh, &pass, PASSWORD_PROMPT, std_flags)) == PAM_SUCCESS) {
+        if((rc = pam_get_pass(pamh, &pass, PASSWORD_PROMPT, &pam_options)) == PAM_SUCCESS) {
             if((rc = auth_verify_password(user, pass, options)) == PAM_SUCCESS) {
                 rc = pam_set_item(pamh, PAM_OLDAUTHTOK, (const void *)pass);
                 if(rc != PAM_SUCCESS) {
@@ -640,7 +684,7 @@
         }
         rc = auth_verify_password(user, pass, options);
         if(rc != PAM_SUCCESS) {
-            SYSLOG("(%s) user '%s' not authenticated.", pam_get_service(pamh), user);
+            SYSLOG("user '%s' not authenticated.", user);
             free_module_options(options);
             return rc;
         }
@@ -698,7 +742,7 @@
 
     free_module_options(options);
     free(user_s);
-    SYSLOG("(%s) password for '%s' was changed.", pam_get_service(pamh), user);
+    SYSLOG("password for '%s' was changed.", user);
     return PAM_SUCCESS;
 }
 
@@ -707,4 +751,6 @@
 pam_sm_setcred(pam_handle_t *pamh, int flags, int argc, const char **argv)
 {
 	return PAM_SUCCESS;
-}
+}  
+
+PAM_MODULE_ENTRY("pam_pgsql");
