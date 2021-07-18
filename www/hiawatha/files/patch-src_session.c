--- src/session.c.orig	2021-04-27 07:15:50 UTC
+++ src/session.c
@@ -33,15 +33,15 @@
 static const struct {
 	const char *text;
 } sqli_detection[] = {
-	{"'\\s*(;\\s*)?--(\\s|')"},
-	{"\\s+(and|or|xor|&&|\\|\\|)\\s*\\(?\\s*('|[0-9]|`?[a-z\\._-]+`?\\s*(=|like)|[a-z]+\\s*\\()"},
-	{"\\s+(not\\s+)?in\\s*\\(\\s*['0-9]"},
-	{"union(\\s+all)?(\\s*\\(\\s*|\\s+)select(`|\\s)"},
-	{"select(\\s*`|\\s+)(\\*|[a-z0-9_\\, ]*)(`\\s*|\\s+)from(\\s*`|\\s+)[a-z0-9_\\.]*"},
-	{"insert\\s+into(\\s*`|\\s+).*(`\\s*|\\s+)(values\\s*)?\\(.*\\)"},
-	{"update(\\s*`|\\s+)[a-z0-9_\\.]*(`\\s*|\\s+)set(\\s*`|\\s+).*="},
-	{"delete\\s+from(\\s*`|\\s+)[a-z0-9_\\.]*`?"},
-	{"extractvalue\\s*\\(\\s*[0-9'\"@]"},
+	{"'[[:space:]]*(;[[:space:]]*)?--([[:space:]]|')"},
+	{"[[:space:]]+(and|or|xor|&&|\\|\\|)[[:space:]]*\\(?[[:space:]]*('|[0-9]|`?[a-z\\._-]+`?[[:space:]]*(=|like)|[a-z]+[[:space:]]*\\()"},
+	{"[[:space:]]+(not[[:space:]]+)?in[[:space:]]*\\([[:space:]]*['0-9]"},
+	{"union([[:space:]]+all)?([[:space:]]*\\([[:space:]]*|[[:space:]]+)select(`|[[:space:]])"},
+	{"select([[:space:]]*`|[[:space:]]+)(\\*|[a-z0-9_\\, ]*)(`[[:space:]]*|[[:space:]]+)from([[:space:]]*`|[[:space:]]+)[a-z0-9_\\.]*"},
+	{"insert[[:space:]]+into([[:space:]]*`|[[:space:]]+).*(`[[:space:]]*|[[:space:]]+)(values[[:space:]]*)?\\(.*\\)"},
+	{"update([[:space:]]*`|[[:space:]]+)[a-z0-9_\\.]*(`[[:space:]]*|[[:space:]]+)set([[:space:]]*`|[[:space:]]+).*="},
+	{"delete[[:space:]]+from([[:space:]]*`|[[:space:]]+)[a-z0-9_\\.]*`?"},
+	{"extractvalue[[:space:]]*\\([[:space:]]*[0-9'\"@]"},
 	{NULL}
 };
 
