--- src/tools/cardos-tool.c.orig	2023-03-24 14:20:46 UTC
+++ src/tools/cardos-tool.c
@@ -1143,7 +1143,6 @@ int main(int argc, char *argv[])
 	int do_info = 0;
 	int do_format = 0;
 	int do_change_startkey = 0;
-	int action_count = 0;
 	const char *opt_startkey = NULL;
 	const char *opt_change_startkey = NULL;
 	sc_context_param_t ctx_param;
@@ -1155,11 +1154,9 @@ int main(int argc, char *argv[])
 			util_print_usage_and_die(app_name, options, option_help, NULL);
 		case 'i':
 			do_info = 1;
-			action_count++;
 			break;
 		case 'f':
 			do_format = 1;
-			action_count++;
 			break;
 		case 's':
 			opt_startkey = optarg;
@@ -1167,7 +1164,6 @@ int main(int argc, char *argv[])
 		case 'S':
 			do_change_startkey = 1;
 			opt_change_startkey = optarg;
-			action_count++;
 			break;
 		case 'r':
 			opt_reader = optarg;
@@ -1217,19 +1213,16 @@ int main(int argc, char *argv[])
 		if ((err = cardos_info())) {
 			goto end;
 		}
-		action_count--;
 	}
 	if (do_change_startkey) {
 		if ((err = cardos_change_startkey(opt_change_startkey))) {
 			goto end;
 		}
-		action_count--;
 	}
 	if (do_format) {
 		if ((err = cardos_format(opt_startkey))) {
 			goto end;
 		}
-		action_count--;
 	}
 end:
 	if (card) {
