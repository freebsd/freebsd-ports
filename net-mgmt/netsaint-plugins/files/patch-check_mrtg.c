--- plugins/check_mrtg.c.orig	Mon May 24 22:29:35 2004
+++ plugins/check_mrtg.c	Mon May 24 22:29:52 2004
@@ -338,10 +338,10 @@
 					usage("Invalid variable number\n");
 				break;
       case 'w': /* critical time threshold */
-				value_warning_threshold=strtoul(argv[5],NULL,10);
+				value_warning_threshold=strtoul(optarg,NULL,10);
 				break;
       case 'c': /* warning time threshold */
-				value_critical_threshold=strtoul(argv[6],NULL,10);
+				value_critical_threshold=strtoul(optarg,NULL,10);
 				break;
       case 'l': /* label */
 				value_label=optarg;
