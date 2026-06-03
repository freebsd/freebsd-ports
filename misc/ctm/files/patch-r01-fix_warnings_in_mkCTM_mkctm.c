--- mkCTM/mkctm.c.ORI	2023-12-24 08:11:59.287756000 +0100
+++ mkCTM/mkctm.c	2023-12-24 08:14:49.514747000 +0100
@@ -113,7 +113,7 @@
 }
 
 int
-dirselect(struct dirent *de)
+dirselect(const struct dirent *de)
 {
 	if (!strcmp(de->d_name, "."))	return 0;
 	if (!strcmp(de->d_name, ".."))	return 0;
@@ -221,7 +221,7 @@
 
 		{
 			u_long l = s2.st_size + 2;
-			u_char *cmd = alloca(strlen(buf1)+strlen(buf2)+100);
+			char *cmd = alloca(strlen(buf1)+strlen(buf2)+100);
 			u_char *ob = malloc(l), *p;
 			int j;
 			FILE *F;
