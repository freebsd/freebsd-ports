--- src/openvasmd.c.orig	2015-12-08 07:09:32 UTC
+++ src/openvasmd.c
@@ -629,7 +629,7 @@ cleanup ()
     }
 #endif /* LOG */
   tracef ("   Exiting.\n");
-  if (log_config) log_config_free (log_config);
+  if (log_config) log_config_free ();
 
   /* Tear down authentication system conf, if any. */
   openvas_auth_tear_down ();
@@ -831,7 +831,7 @@ update_or_rebuild_nvt_cache (int update_
         break;
       case -2:
         g_critical ("%s: database is wrong version\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
         break;
       case -3:
@@ -839,7 +839,7 @@ update_or_rebuild_nvt_cache (int update_
       case -1:
       default:
         g_critical ("%s: failed to initialise OMP daemon\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
     }
 
@@ -849,7 +849,7 @@ update_or_rebuild_nvt_cache (int update_
     {
       g_critical ("%s: failed to register `atexit' cleanup function\n",
                   __FUNCTION__);
-      log_config_free (log_config);
+      log_config_free ();
       exit (EXIT_FAILURE);
     }
 
@@ -1148,6 +1148,7 @@ manager_listen (const char *address_str,
   struct sockaddr_storage address;
   struct sockaddr_in *addr4 = (struct sockaddr_in *) &address;
   struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *) &address;
+  socklen_t addrlen;
   int port, optval;
 
   if (!address_str)
@@ -1176,11 +1177,13 @@ manager_listen (const char *address_str,
     {
       address.ss_family = AF_INET6;
       addr6->sin6_port = port;
+      addrlen = sizeof (*addr6);
     }
   else if (inet_pton (AF_INET, address_str, &addr4->sin_addr) > 0)
     {
       address.ss_family = AF_INET;
       addr4->sin_port = port;
+      addrlen = sizeof (*addr4);
     }
   else
     {
@@ -1211,7 +1214,7 @@ manager_listen (const char *address_str,
       return -1;
     }
 
-  if (bind (*soc, (struct sockaddr *) &address, sizeof (address))
+  if (bind (*soc, (struct sockaddr *) &address, addrlen)
       == -1)
     {
       g_warning ("Failed to bind manager socket: %s", strerror (errno));
@@ -1468,25 +1471,25 @@ main (int argc, char** argv)
       switch (manage_optimize (log_config, database, optimize))
         {
           case 0:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_SUCCESS;
           case 1:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
       return EXIT_SUCCESS;
@@ -1524,7 +1527,7 @@ main (int argc, char** argv)
                                    scanner_ca_pub, scanner_key_pub,
                                    scanner_key_priv);
       g_free (stype);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1576,7 +1579,7 @@ main (int argc, char** argv)
                                    stype, scanner_ca_pub, scanner_key_pub,
                                    scanner_key_priv);
       g_free (stype);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1606,22 +1609,22 @@ main (int argc, char** argv)
       switch (manage_create_user (log_config, database, create_user, role))
         {
           case 0:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_SUCCESS;
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
       return EXIT_SUCCESS;
@@ -1635,32 +1638,32 @@ main (int argc, char** argv)
       switch (manage_delete_user (log_config, database, delete_user))
         {
           case 0:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_SUCCESS;
           case 2:
             g_critical ("%s: failed to find user '%s'\n",
                         __FUNCTION__,
                         delete_user);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case 4:
             g_critical ("%s: user has active tasks\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
     }
@@ -1671,22 +1674,22 @@ main (int argc, char** argv)
       switch (manage_get_users (log_config, database, role))
         {
           case 0:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_SUCCESS;
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
     }
@@ -1695,7 +1698,7 @@ main (int argc, char** argv)
     {
       /* List the users and then exit. */
       int ret = manage_get_scanners (log_config, database);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1720,7 +1723,7 @@ main (int argc, char** argv)
 
       /* Delete the scanner and then exit. */
       ret = manage_delete_scanner (log_config, database, delete_scanner);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1748,7 +1751,7 @@ main (int argc, char** argv)
 
       /* Delete the scanner and then exit. */
       ret = manage_verify_scanner (log_config, database, verify_scanner);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1783,26 +1786,26 @@ main (int argc, char** argv)
       switch (manage_set_password (log_config, database, user, new_password))
         {
           case 0:
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_SUCCESS;
           case 1:
             g_critical ("%s: failed to find user\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
     }
@@ -1885,24 +1888,24 @@ main (int argc, char** argv)
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
       fprintf (stderr, "Encryption succeeded.\n");
-      log_config_free (log_config);
+      log_config_free ();
       return EXIT_SUCCESS;
     }
 
@@ -1916,24 +1919,24 @@ main (int argc, char** argv)
           case -2:
             g_critical ("%s: database is wrong version\n", __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -3:
             g_critical ("%s: database must be initialised"
                         " (with --update or --rebuild)\n",
                         __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
           case -1:
           default:
             g_critical ("%s: internal error\n", __FUNCTION__);
             fprintf (stderr, "Decryption failed.\n");
-            log_config_free (log_config);
+            log_config_free ();
             return EXIT_FAILURE;
         }
       fprintf (stderr, "Decryption succeeded.\n");
-      log_config_free (log_config);
+      log_config_free ();
       return EXIT_SUCCESS;
     }
 
@@ -2005,12 +2008,12 @@ main (int argc, char** argv)
             g_critical ("%s: failed to fork into background: %s\n",
                         __FUNCTION__,
                         strerror (errno));
-            log_config_free (log_config);
+            log_config_free ();
             exit (EXIT_FAILURE);
             break;
           default:
             /* Parent. */
-            log_config_free (log_config);
+            log_config_free ();
             exit (EXIT_SUCCESS);
             break;
         }
@@ -2026,25 +2029,25 @@ main (int argc, char** argv)
         break;
       case -2:
         g_critical ("%s: database is wrong version\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
         break;
       case -3:
         g_critical ("%s: database must be initialised"
                     " (with --update or --rebuild)\n",
                     __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
         break;
       case -4:
         g_critical ("%s: --max-ips-per-target out of range\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
         break;
       case -1:
       default:
         g_critical ("%s: failed to initialise OMP daemon\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
     }
 
@@ -2054,7 +2057,7 @@ main (int argc, char** argv)
     {
       g_critical ("%s: failed to register `atexit' cleanup function\n",
                   __FUNCTION__);
-      log_config_free (log_config);
+      log_config_free ();
       exit (EXIT_FAILURE);
     }
 
