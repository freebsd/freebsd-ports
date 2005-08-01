--- src/rra-decode.c.orig	Thu May 12 16:57:53 2005
+++ src/rra-decode.c	Fri Jul 29 19:26:36 2005
@@ -202,7 +202,7 @@
 					time_t unix_time = filetime_to_unix_time(&propvals[i].val.filetime);
 					char* time_str = asctime(gmtime(&unix_time));
 					time_str[strlen(time_str)-1] = '\0'; /* remove trailing newline */
-					printf("%s  (%lu)", time_str, unix_time);
+					printf("%s  (%lu)", time_str, (long unsigned)unix_time);
 #else
           TIME_FIELDS time_fields;
           time_fields_from_filetime(&propvals[i].val.filetime, &time_fields);
