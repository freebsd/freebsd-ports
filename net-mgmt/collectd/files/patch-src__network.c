--- src/network.c.orig	2011-07-14 15:41:32.000000000 +0200
+++ src/network.c	2011-07-14 15:41:37.000000000 +0200
@@ -58,7 +58,9 @@
 #endif
 
 #if HAVE_LIBGCRYPT
+#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
 # include <gcrypt.h>
+#pragma GCC diagnostic warning "-Wdeprecated-declarations"
 GCRY_THREAD_OPTION_PTHREAD_IMPL;
 #endif
 
--- src/network.c
+++ src/network.c
@@ -704,7 +704,7 @@ static int parse_part_values (void **ret_buffer, size_t *ret_buffer_len,
 
 	exp_size = 3 * sizeof (uint16_t)
 		+ pkg_numval * (sizeof (uint8_t) + sizeof (value_t));
-	if ((buffer_len < 0) || (buffer_len < exp_size))
+	if (buffer_len < exp_size)
 	{
 		WARNING ("network plugin: parse_part_values: "
 				"Packet too short: "
@@ -789,7 +789,7 @@ static int parse_part_number (void **ret_buffer, size_t *ret_buffer_len,
 
 	uint16_t pkg_length;
 
-	if ((buffer_len < 0) || ((size_t) buffer_len < exp_size))
+	if (buffer_len < exp_size)
 	{
 		WARNING ("network plugin: parse_part_number: "
 				"Packet too short: "
@@ -828,7 +828,7 @@ static int parse_part_string (void **ret_buffer, size_t *ret_buffer_len,
 
 	uint16_t pkg_length;
 
-	if ((buffer_len < 0) || (buffer_len < header_size))
+	if (buffer_len < header_size)
 	{
 		WARNING ("network plugin: parse_part_string: "
 				"Packet too short: "
