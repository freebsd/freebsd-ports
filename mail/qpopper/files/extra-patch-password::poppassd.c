--- password/poppassd.c.orig	Sat May  5 18:50:05 2001
+++ password/poppassd.c	Sat May  5 18:52:59 2001
@@ -284,6 +284,8 @@
 
 static char *P1[] =
    {
+     "changing local password for *\nold password: ",  /* FreeBSD */
+     "changing nis password for *\nold password: ",    /* FreeBSD NIS */
      "changing password for *\nold password: ",  /* shadow */
      "enter login password: ",                   /* Solaris */
      "old smb password: ",                       /* smb */
@@ -301,6 +303,7 @@
 
 static char *P3[] =
    {
+     "retype new password: ",                    /* FreeBSD */
      "re-enter new password:*",                  /* shadow */
      "re-enter new password: ",
      "retype new smb password: ",                /* smb */
@@ -309,6 +312,8 @@
     
 static char *P4[] =
    {
+     "passwd: updating the database...\npasswd: done ", /* FreeBSD */
+     "nis password has been changed * ", /* FreeBSD NIS */
      "password changed. ", /* shadow */
      "password changed ",  /* smb */
      ""
