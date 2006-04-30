--- config.c.orig	Tue Apr 18 15:54:34 2006
+++ config.c	Sun Apr 30 18:19:00 2006
@@ -40,6 +40,7 @@
 long long int kb_str_to_value(char *field, char *str)
 {
 	char *mult;
+	#define atoll(a) strtoll((a), (char **)NULL, 10)
 	long long int bytes = atoll(str);
 	if (bytes < -1)
 		error_exit("%s: value cannot be < -1\n", field);
