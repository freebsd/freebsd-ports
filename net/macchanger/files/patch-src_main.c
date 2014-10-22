--- src/main.c	2014-01-01 11:23:39.000000000 +0200
+++ src/main.c	2014-10-17 12:15:02.254848839 +0300
@@ -40,9 +40,6 @@
 #include "maclist.h"
 #include "netinfo.h"
 
-#define EXIT_OK    0
-#define EXIT_ERROR 1
-
 static void
 print_help (void)
 {
@@ -54,7 +51,9 @@
 		"  -e,  --ending                 Don't change the vendor bytes\n"
 		"  -a,  --another                Set random vendor MAC of the same kind\n"
 		"  -A                            Set random vendor MAC of any kind\n"
+#if defined(HAVE_ETHTOOL)
 		"  -p,  --permanent              Reset to original, permanent hardware MAC\n"
+#endif
 		"  -r,  --random                 Set fully random MAC\n"
 		"  -l,  --list[=keyword]         Print known vendors\n"
 		"  -b,  --bia                    Pretend to be a burned-in-address\n"
@@ -116,7 +115,9 @@
 	char ending       = 0;
 	char another_any  = 0;
 	char another_same = 0;
+#if defined(HAVE_ETHTOOL)
 	char permanent    = 0;
+#endif
 	char print_list   = 0;
 	char show         = 0;
 	char set_bia      = 0;
@@ -131,7 +132,9 @@
 		{"ending",      no_argument,       NULL, 'e'},
 		{"endding",     no_argument,       NULL, 'e'}, /* kept for backwards compatibility */
 		{"another",     no_argument,       NULL, 'a'},
+#if defined(HAVE_ETHTOOL)
 		{"permanent",   no_argument,       NULL, 'p'},
+#endif
 		{"show",        no_argument,       NULL, 's'},
 		{"another_any", no_argument,       NULL, 'A'},
 		{"bia",         no_argument,       NULL, 'b'},
@@ -142,7 +145,9 @@
 
 	net_info_t *net;
 	mac_t      *mac;
+#if defined(HAVE_ETHTOOL)
 	mac_t      *mac_permanent;
+#endif
 	mac_t      *mac_faked;
 	char       *device_name;
 	int         val;
@@ -158,7 +163,7 @@
 				"This is free software; see the source for copying conditions.  There is NO\n"
 				"warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.\n",
 				VERSION);
-			exit (EXIT_OK);
+			exit (EXIT_SUCCESS);
 			break;
 		case 'l':
 			print_list = 1;
@@ -182,9 +187,11 @@
 		case 'A':
 			another_any = 1;
 			break;
+#if defined(HAVE_ETHTOOL)
 		case 'p':
 			permanent = 1;
 			break;
+#endif
 		case 'm':
 			set_mac = optarg;
 			break;
@@ -192,26 +199,26 @@
 		case '?':
 		default:
 			print_help();
-			exit (EXIT_OK);
+			exit (EXIT_SUCCESS);
 			break;
 		}
 	}
 
 	/* Read the MAC lists */
 	if (mc_maclist_init() < 0) {
-		exit (EXIT_ERROR);
+		exit (EXIT_FAILURE);
 	}
 
 	/* Print list? */
 	if (print_list) {
 		mc_maclist_print(search_word);
-		exit (EXIT_OK);
+		exit (EXIT_SUCCESS);
 	}
 
 	/* Get device name argument */
 	if (optind >= argc) {
 		print_usage();
-		exit (EXIT_OK);
+		exit (EXIT_SUCCESS);
 	}
 	device_name = argv[optind];
 
@@ -220,10 +227,12 @@
 
 	/* Read the MAC */
 	if ((net = mc_net_info_new(device_name)) == NULL) {
-		exit (EXIT_ERROR);
+		exit (EXIT_FAILURE);
 	}
 	mac = mc_net_info_get_mac(net);
+#if defined(HAVE_ETHTOOL)
 	mac_permanent = mc_net_info_get_permanent_mac(net);
+#endif
 
 	/* --bia can only be used with --random */
 	if (set_bia  &&  !random) {
@@ -232,16 +241,18 @@
 
 	/* Print the current MAC info */
 	print_mac ("Current MAC:   ", mac);
+#if defined(HAVE_ETHTOOL)
 	print_mac ("Permanent MAC: ", mac_permanent);
+#endif
 
 	/* Change the MAC */
 	mac_faked = mc_mac_dup (mac);
 
 	if (show) {
-		exit (EXIT_OK);
+		exit (EXIT_SUCCESS);
 	} else if (set_mac) {
 		if (mc_mac_read_string (mac_faked, set_mac) < 0) {
-			exit (EXIT_ERROR);
+			exit (EXIT_FAILURE);
 		}
 	} else if (random) {
 		mc_mac_random (mac_faked, 6, set_bia);
@@ -254,10 +265,12 @@
 	} else if (another_any) {
 		mc_maclist_set_random_vendor(mac_faked, mac_is_anykind);
 		mc_mac_random (mac_faked, 3, 1);
+#if defined(HAVE_ETHTOOL)
 	} else if (permanent) {
 		mac_faked = mc_mac_dup (mac_permanent);
+#endif
 	} else {
-		exit (EXIT_OK); /* default to show */
+		exit (EXIT_SUCCESS); /* default to show */
 	}
 
 	/* Set the new MAC */
@@ -279,9 +292,11 @@
 	/* Memory free */
 	mc_mac_free (mac);
 	mc_mac_free (mac_faked);
+#if defined(HAVE_ETHTOOL)
 	mc_mac_free (mac_permanent);
+#endif
 	mc_net_info_free (net);
 	mc_maclist_free();
 
-	return (ret == 0) ? EXIT_OK : EXIT_ERROR;
+	return (ret == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
 }
