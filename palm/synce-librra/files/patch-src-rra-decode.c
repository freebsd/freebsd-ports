--- src/rra-decode.c.orig	Thu Mar 11 22:13:04 2004
+++ src/rra-decode.c	Thu Mar 11 22:13:26 2004
@@ -218,7 +218,7 @@
 					time_t unix_time = filetime_to_unix_time(&propvals[i].val.filetime);
 					char* time_str = ctime(&unix_time);
 					time_str[strlen(time_str)-1] = '\0'; /* remove trailing newline */
-					printf("%s  (%lu)", time_str, unix_time);
+					printf("%s  (%lu)", time_str, (long unsigned)unix_time);
           db_dump(&propvals[i].val.filetime, sizeof(FILETIME));
         }
 				break;
