--- src/manage_sql.c	2022-07-21 02:20:24.000000000 -0500
+++ src/manage_sql.c	2022-10-30 17:32:08.342879000 -0500
@@ -54,7 +54,6 @@
 #include <errno.h>
 #include <glib/gstdio.h>
 #include <gnutls/x509.h>
-#include <malloc.h>
 #include <pwd.h>
 #include <stdlib.h>
 #include <sys/socket.h>
@@ -71,7 +70,6 @@
 #include <gvm/base/hosts.h>
 #include <gvm/base/pwpolicy.h>
 #include <gvm/base/logging.h>
-#include <bsd/unistd.h>
 #include <gvm/util/fileutils.h>
 #include <gvm/util/gpgmeutils.h>
 #include <gvm/util/serverutils.h>
@@ -6997,7 +6995,7 @@
 
       if (strcmp (name, "tp_sms_hostname") == 0)
         {
-          if (g_regex_match_simple ("^[0-9A-Za-z][0-9A-Za-z.-]*$",
+          if (g_regex_match_simple ("^[0-9A-Za-z][0-9A-Za-z.\\-]*$",
                                     *data, 0, 0)
               == FALSE)
             {
@@ -9122,7 +9120,7 @@
   g_debug ("   HTTP_GET %s", url);
 
   cmd = (gchar **) g_malloc (5 * sizeof (gchar *));
-  cmd[0] = g_strdup ("/usr/bin/wget");
+  cmd[0] = g_strdup ("%%LOCALBASE%%/bin/wget");
   cmd[1] = g_strdup ("-O");
   cmd[2] = g_strdup ("-");
   cmd[3] = g_strdup (url);
@@ -15349,8 +15347,6 @@
     }
 
   cleanup_iterator (&nvts);
-
-  malloc_trim (0);
 }
 
 /**
@@ -49740,8 +49736,8 @@
            */
           languages_regex
             = g_regex_new ("^(Browser Language|"
-                           "([a-z]{2,3})(_[A-Z]{2})?(@[[:alnum:]_-]+)?"
-                           "(:([a-z]{2,3})(_[A-Z]{2})?(@[[:alnum:]_-]+)?)*)$",
+                           "([a-z]{2,3})(_[A-Z]{2})?(@[[:alnum:]_\\-]+)?"
+                           "(:([a-z]{2,3})(_[A-Z]{2})?(@[[:alnum:]_\\-]+)?)*)$",
                            0, 0, NULL);
           match = g_regex_match (languages_regex, value, 0, NULL);
           g_regex_unref (languages_regex);
@@ -50309,7 +50305,7 @@
   if (strcmp (uuid, SETTING_UUID_LSC_DEB_MAINTAINER) == 0)
     {
       if (g_regex_match_simple
-            ("^([[:alnum:]-_]*@[[:alnum:]-_][[:alnum:]-_.]*)?$",
+            ("^([[:alnum:]\\-_]*@[[:alnum:]\\-_][[:alnum:]\\-_.]*)?$",
             value, 0, 0) == FALSE)
         return 1;
     }
