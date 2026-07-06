--- main.c.orig	2026-06-03 17:54:41 UTC
+++ main.c
@@ -480,7 +480,7 @@ void print_version(void)
 
 void print_version(void)
 {
-	printf("RPIBOOT: build-date %s pkg-version %s %s\n", BUILD_DATE, PKG_VER, GIT_VER);
+	printf("RPIBOOT: FreeBSD package version %s\n", PKG_VER);
 }
 
 void get_options(int argc, char *argv[])
