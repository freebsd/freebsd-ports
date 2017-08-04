--- src/openvasmd.c	2017-06-16 03:06:07.000000000 -0500
+++ src/openvasmd.c	2017-08-03 13:21:58.536708000 -0500
@@ -634,7 +634,7 @@
     }
 #endif /* LOG */
   tracef ("   Exiting.\n");
-  if (log_config) log_config_free (log_config);
+  if (log_config) log_config_free ();
 
   /* Tear down authentication system conf, if any. */
   openvas_auth_tear_down ();
@@ -887,7 +887,7 @@
         break;
       case -2:
         g_critical ("%s: database is wrong version\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
         break;
       case -3:
@@ -895,7 +895,7 @@
       case -1:
       default:
         g_critical ("%s: failed to initialise OMP daemon\n", __FUNCTION__);
-        log_config_free (log_config);
+        log_config_free ();
         exit (EXIT_FAILURE);
     }
 
@@ -905,7 +905,7 @@
     {
       g_critical ("%s: failed to register `atexit' cleanup function\n",
                   __FUNCTION__);
-      log_config_free (log_config);
+      log_config_free ();
       exit (EXIT_FAILURE);
     }
 
@@ -1234,6 +1234,7 @@
   struct sockaddr_storage address;
   struct sockaddr_in *addr4 = (struct sockaddr_in *) &address;
   struct sockaddr_in6 *addr6 = (struct sockaddr_in6 *) &address;
+  socklen_t addrlen;
   int port, optval;
 
   if (!address_str)
@@ -1262,11 +1263,13 @@
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
@@ -1297,7 +1300,7 @@
       return -1;
     }
 
-  if (bind (*soc, (struct sockaddr *) &address, sizeof (address))
+  if (bind (*soc, (struct sockaddr *) &address, addrlen)
       == -1)
     {
       g_warning ("Failed to bind manager socket: %s", strerror (errno));
@@ -1556,25 +1559,25 @@
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
@@ -1612,7 +1615,7 @@
                                    scanner_ca_pub, scanner_key_pub,
                                    scanner_key_priv);
       g_free (stype);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1664,7 +1667,7 @@
                                    stype, scanner_ca_pub, scanner_key_pub,
                                    scanner_key_priv);
       g_free (stype);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1694,22 +1697,22 @@
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
@@ -1723,32 +1726,32 @@
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
@@ -1759,22 +1762,22 @@
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
@@ -1783,7 +1786,7 @@
     {
       /* List the users and then exit. */
       int ret = manage_get_scanners (log_config, database);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1806,7 +1809,7 @@
     {
       /* List the slaves and then exit. */
       int ret = manage_get_slaves (log_config, database);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1831,7 +1834,7 @@
 
       /* Delete the scanner and then exit. */
       ret = manage_delete_scanner (log_config, database, delete_scanner);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1859,7 +1862,7 @@
 
       /* Delete the scanner and then exit. */
       ret = manage_verify_scanner (log_config, database, verify_scanner);
-      log_config_free (log_config);
+      log_config_free ();
       switch (ret)
         {
           case 0:
@@ -1894,26 +1897,26 @@
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
@@ -1996,24 +1999,24 @@
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
 
@@ -2027,24 +2030,24 @@
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
 
@@ -2116,12 +2119,12 @@
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
@@ -2137,25 +2140,25 @@
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
 
@@ -2165,7 +2168,7 @@
     {
       g_critical ("%s: failed to register `atexit' cleanup function\n",
                   __FUNCTION__);
-      log_config_free (log_config);
+      log_config_free ();
       exit (EXIT_FAILURE);
     }
 
