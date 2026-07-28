--- plugins/check_smtp.c.orig	2026-07-27 09:49:59 UTC
+++ plugins/check_smtp.c
@@ -793,7 +793,7 @@ check_smtp_config_wrapper process_arguments(int argc, 
 			usage(_("SSL support not available - install OpenSSL and recompile"));
 #endif
 			implicit_tls = true;
-			// fallthrough
+			break;
 		case 's':
 			/* ssl */
 			result.config.use_ssl = true;
