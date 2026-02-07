--- nslcd/passwd.c.orig	2025-02-09 14:17:17 UTC
+++ nslcd/passwd.c
@@ -63,6 +63,7 @@ const char *attmap_passwd_loginShell    = "loginShell"
 const char *attmap_passwd_gecos         = "\"${gecos:-$cn}\"";
 const char *attmap_passwd_homeDirectory = "homeDirectory";
 const char *attmap_passwd_loginShell    = "loginShell";
+const char *attmap_passwd_loginClass    = "loginClass";
 
 /* special properties for objectSid-based searches
    (these are already LDAP-escaped strings) */
@@ -150,6 +151,7 @@ void passwd_init(void)
   attmap_add_attributes(set, attmap_passwd_gecos);
   attmap_add_attributes(set, attmap_passwd_homeDirectory);
   attmap_add_attributes(set, attmap_passwd_loginShell);
+  attmap_add_attributes(set, attmap_passwd_loginClass);
   passwd_attrs = set_tolist(set);
   if (passwd_attrs == NULL)
   {
@@ -436,6 +438,7 @@ static int write_passwd(TFILE *fp, MYLDAP_ENTRY *entry
   char gecos[1024];
   char homedir[256];
   char shell[64];
+  char lclass[256];
   char passbuffer[BUFLEN_PASSWORDHASH];
   int i, j;
   /* get the usernames for this entry */
@@ -549,6 +552,8 @@ static int write_passwd(TFILE *fp, MYLDAP_ENTRY *entry
             myldap_get_dn(entry), attmap_passwd_homeDirectory);
   /* get the shell for this entry */
   attmap_get_value(entry, attmap_passwd_loginShell, shell, sizeof(shell));
+  /* get the login class for this entry */
+  attmap_get_value(entry, attmap_passwd_loginClass, lclass, sizeof(lclass));
   /* write the entries */
   for (i = 0; usernames[i] != NULL; i++)
   {
@@ -573,6 +578,7 @@ static int write_passwd(TFILE *fp, MYLDAP_ENTRY *entry
             WRITE_STRING(fp, gecos);
             WRITE_STRING(fp, homedir);
             WRITE_STRING(fp, shell);
+            WRITE_STRING(fp, lclass);
           }
         }
       }
