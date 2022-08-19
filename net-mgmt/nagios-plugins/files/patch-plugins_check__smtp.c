--- plugins/check_smtp.c.orig	2021-10-29 19:30:39 UTC
+++ plugins/check_smtp.c
@@ -648,6 +648,7 @@ process_arguments (int argc, char **argv)
 #else
 			usage (_("SSL support not available - install OpenSSL and recompile"));
 #endif
+			break;
 		case 's':
 		/* ssl */
 			use_ssl = TRUE;
