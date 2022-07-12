--- src/jump.c.orig	2022-06-28 06:17:34 UTC
+++ src/jump.c
@@ -207,11 +207,11 @@ save_jumpdb(void)
 		}
 
 		jump_num++;
-#ifndef __OpenBSD__
+#ifndef __i386__
 		fprintf(fp, "%zu:%ld:%ld:%s\n", jump_db[i].visits, jump_db[i].first_visit,
 			jump_db[i].last_visit, jump_db[i].path);
 #else
-		fprintf(fp, "%zu:%lld:%lld:%s\n", jump_db[i].visits, jump_db[i].first_visit,
+		fprintf(fp, "%zu:%d:%d:%s\n", jump_db[i].visits, jump_db[i].first_visit,
 			jump_db[i].last_visit, jump_db[i].path);
 #endif
 	}
