--- nslcd/passwd.c.orig	2021-11-15 20:40:49.000000000 +0100
+++ nslcd/passwd.c	2023-05-29 19:22:02.234797000 +0200
@@ -63,6 +63,7 @@
 const char *attmap_passwd_gecos         = "\"${gecos:-$cn}\"";
 const char *attmap_passwd_homeDirectory = "homeDirectory";
 const char *attmap_passwd_loginShell    = "loginShell";
+const char *attmap_passwd_loginClass    = "loginClass";
 
 /* special properties for objectSid-based searches
    (these are already LDAP-escaped strings) */
@@ -150,6 +151,7 @@
   attmap_add_attributes(set, attmap_passwd_gecos);
   attmap_add_attributes(set, attmap_passwd_homeDirectory);
   attmap_add_attributes(set, attmap_passwd_loginShell);
+  attmap_add_attributes(set, attmap_passwd_loginClass);
   passwd_attrs = set_tolist(set);
   if (passwd_attrs == NULL)
   {
@@ -428,6 +430,7 @@
   char gecos[1024];
   char homedir[256];
   char shell[64];
+  char lclass[256];
   char passbuffer[BUFLEN_PASSWORDHASH];
   int i, j;
   /* get the usernames for this entry */
@@ -541,6 +544,8 @@
             myldap_get_dn(entry), attmap_passwd_homeDirectory);
   /* get the shell for this entry */
   attmap_get_value(entry, attmap_passwd_loginShell, shell, sizeof(shell));
+  /* get the login class for this entry */
+  attmap_get_value(entry, attmap_passwd_loginClass, lclass, sizeof(lclass));
   /* write the entries */
   for (i = 0; usernames[i] != NULL; i++)
   {
@@ -565,6 +570,7 @@
             WRITE_STRING(fp, gecos);
             WRITE_STRING(fp, homedir);
             WRITE_STRING(fp, shell);
+            WRITE_STRING(fp, lclass);
           }
         }
       }
