--- src/util.c.orig	2022-12-31 19:17:17 UTC
+++ src/util.c
@@ -878,7 +878,7 @@ int handle_dynname_internal_strings(char *new, int new
   char proto_string[] = "$proto", in_iface_string[] = "$in_iface";
 
   char buf[newlen], *ptr_start, *ptr_end, *ptr_var, *ptr_substr, *last_char;
-  int oldlen, var_num, var_len, rem_len, sub_len; 
+  int oldlen, var_len, rem_len, sub_len; 
 
   if (!new || !old || !prim_ptrs) return ERR;
 
@@ -886,7 +886,7 @@ int handle_dynname_internal_strings(char *new, int new
   if (oldlen <= newlen) strcpy(new, old);
   else return ERR;
 
-  for (var_num = 0, ptr_substr = new, ptr_var = strchr(ptr_substr, '$'); ptr_var; var_num++) {
+  for (ptr_substr = new, ptr_var = strchr(ptr_substr, '$'); ptr_var;) {
     rem_len = newlen - (ptr_var - new);
 
     /* tokenizing: valid charset: a-z, A-Z, 0-9, _ */
@@ -2422,8 +2422,8 @@ void compose_timestamp(char *buf, int buflen, struct t
   if (buflen < VERYSHORTBUFLEN) return; 
 
   if (since_epoch) {
-    if (usec) snprintf(buf, buflen, "%ld.%.6ld", tv->tv_sec, (long)tv->tv_usec);
-    else snprintf(buf, buflen, "%ld", tv->tv_sec);
+    if (usec) snprintf(buf, buflen, "%ld.%.6ld", (long)tv->tv_sec, (long)tv->tv_usec);
+    else snprintf(buf, buflen, "%ld", (long)tv->tv_sec);
   }
   else {
     time1 = tv->tv_sec;
