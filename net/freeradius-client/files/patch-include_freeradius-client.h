Fix vendor-specific attributes length validation: vendor-specific
attributes need additional room for the VSA header.

Obtained from: https://github.com/FreeRADIUS/freeradius-client/commit/40d5f543e8240de39f5780c99355ddc2f5726bde

--- include/freeradius-client.h.orig	2021-07-29 14:49:30 UTC
+++ include/freeradius-client.h
@@ -53,6 +53,7 @@
 #define AUTH_PASS_LEN		(7 * 16) /* multiple of 16 */
 #define AUTH_ID_LEN		64
 #define AUTH_STRING_LEN		253	 /* maximum of 253 */
+#define VSA_HEADER_LEN		6	 /* vendor-specific attribute header: type(1) + length(1) + vendor-id(4) */
 
 #define BUFFER_LEN		8192
 
