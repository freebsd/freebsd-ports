--- src/mod_extforward.c.orig	2010-02-19 11:34:37.000000000 +0100
+++ src/mod_extforward.c	2010-02-19 11:40:02.000000000 +0100
@@ -240,14 +240,14 @@ static array *extract_forward_array(buff
 		int in_str = 0;
 		for (base = pbuffer->ptr, curr = pbuffer->ptr; *curr; curr++) {
 			if (in_str) {
-				if ((*curr > '9' || *curr < '0') && *curr != '.' && *curr != ':') {
+				if ((*curr < '0' || *curr > '9') && *curr != '.' && *curr != ':' && (*curr < 'a' || *curr > 'f') && (*curr < 'A' || *curr > 'F')) {
 					/* found an separator , insert value into result array */
 					put_string_into_array_len(result, base, curr - base);
 					/* change state to not in string */
 					in_str = 0;
 				}
 			} else {
-				if (*curr >= '0' && *curr <= '9') {
+				if ((*curr >= '0' && *curr <= '9') || (*curr >= 'a' && *curr <= 'f') || (*curr >= 'A' && *curr <= 'F')) {
 					/* found leading char of an IP address, move base pointer and change state */
 					base = curr;
 					in_str = 1;
