--- src/webserver/src/php_amule_lib.cpp.orig	2016-09-16 09:55:07.000000000 +0200
+++ src/webserver/src/php_amule_lib.cpp	2018-03-17 09:50:11.347042000 +0100
@@ -564,7 +564,7 @@
 		case 1: search_type = EC_SEARCH_GLOBAL; break;
 		case 2: search_type = EC_SEARCH_KAD; break;
 		default:
-			php_report_error(PHP_ERROR, "Invalid search type %"PRIu64, si->var->value.int_val);
+			php_report_error(PHP_ERROR, "Invalid search type %" PRIu64, si->var->value.int_val);
 			return;
 	}
 
