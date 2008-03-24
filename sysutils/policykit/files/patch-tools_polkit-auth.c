--- tools/polkit-auth.c.orig	2007-12-05 22:30:18.000000000 -0500
+++ tools/polkit-auth.c	2007-12-23 01:43:36.000000000 -0500
@@ -37,12 +37,13 @@
 #include <stdlib.h>
 #include <string.h>
 #include <sys/types.h>
+#include <sys/wait.h>
 #include <pwd.h>
 #include <grp.h>
 #include <unistd.h>
 #include <errno.h>
 #include <termios.h>
 
 #include <polkit-dbus/polkit-dbus.h>
 #include <polkit-grant/polkit-grant.h>
 
@@ -107,7 +109,7 @@ conversation_select_admin_user (PolKitGr
         }
         printf ("\n");
         printf ("Select user: ");
-        getline (&lineptr, &linelen, stdin);
+        polkit_sysdeps_getline (&lineptr, &linelen, stdin);
         user = strdup (lineptr);
         free (lineptr);
         return user;
@@ -133,7 +135,7 @@ conversation_pam_prompt_echo_off (PolKit
                 exit (1);
         }
 
-        getline (&lineptr, &linelen, stdin);
+        polkit_sysdeps_getline (&lineptr, &linelen, stdin);
   
         /* Restore terminal. */
         tcsetattr (fileno (stdout), TCSAFLUSH, &old);
@@ -151,7 +153,7 @@ conversation_pam_prompt_echo_on (PolKitG
         size_t linelen = 0;
         char *result;
         printf ("%s", request);
-        getline (&lineptr, &linelen, stdin);
+        polkit_sysdeps_getline (&lineptr, &linelen, stdin);
         result = strdup (lineptr);
         free (lineptr);
         printf ("\n");
@@ -189,7 +191,7 @@ conversation_override_grant_type (PolKit
         case POLKIT_RESULT_ONLY_VIA_SELF_AUTH_KEEP_SESSION:
                 printf ("Keep this privilege for the session? [no/session]?\n");
         again:
-                getline (&lineptr, &linelen, stdin);
+                polkit_sysdeps_getline (&lineptr, &linelen, stdin);
                 if (g_str_has_prefix (lineptr, "no")) {
                         ;
                 } else if (g_str_has_prefix (lineptr, "session")) {
@@ -204,7 +206,7 @@ conversation_override_grant_type (PolKit
         case POLKIT_RESULT_ONLY_VIA_SELF_AUTH_KEEP_ALWAYS:
                 printf ("Keep this privilege for the session or always? [no/session/always]?\n");
         again2:
-                getline (&lineptr, &linelen, stdin);
+                polkit_sysdeps_getline (&lineptr, &linelen, stdin);
                 if (g_str_has_prefix (lineptr, "no")) {
                         ;
                 } else if (g_str_has_prefix (lineptr, "session")) {
