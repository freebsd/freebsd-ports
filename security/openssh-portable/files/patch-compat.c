Avoid a heap overflow. Upstream did not deem this a security issue. It appears
to be mostly harmless too.

http://www.openwall.com/lists/oss-security/2015/05/16/3
https://anongit.mindrot.org/openssh.git/commit/?id=77199d6ec8986d470487e66f8ea8f4cf43d2e20c

--- compat.c	2015-03-17 06:49:20.000000000 +0100
+++ compat.c	2015-05-03 17:51:32.251293388 +0200
@@ -229,7 +229,7 @@
 	buffer_init(&b);
 	tmp = orig_prop = xstrdup(proposal);
 	while ((cp = strsep(&tmp, ",")) != NULL) {
-		if (match_pattern_list(cp, filter, strlen(cp), 0) != 1) {
+		if (match_pattern_list(cp, filter, strlen(filter), 0) != 1) {
 			if (buffer_len(&b) > 0)
 				buffer_append(&b, ",", 1);
 			buffer_append(&b, cp, strlen(cp));
