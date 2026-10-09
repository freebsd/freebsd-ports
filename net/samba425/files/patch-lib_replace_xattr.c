--- lib/replace/xattr.c.orig	2026-01-23 10:53:40 UTC
+++ lib/replace/xattr.c
@@ -279,9 +279,9 @@ static ssize_t bsd_attr_list (int type, extattr_arg ar
 				errno = ERANGE;
 				return -1;
 			}
-			strncpy(list, extattr[t].name, extattr[t].len + 1);
+			memmove(list, extattr[t].name, extattr[t].len + 1);
 			list += extattr[t].len;
-			strncpy(list, buf + i + 1, len);
+			memmove(list, buf + i + 1, len);
 			list[len] = '\0';
 			list += len + 1;
 		}
