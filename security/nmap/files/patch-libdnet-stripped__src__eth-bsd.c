--- libdnet-stripped/src/eth-bsd.c.orig	2009-11-09 04:49:32 UTC
+++ libdnet-stripped/src/eth-bsd.c
@@ -45,7 +45,7 @@ eth_open(const char *device)
 	int i;
 
 	if ((e = calloc(1, sizeof(*e))) != NULL) {
-		for (i = 0; i < 128; i++) {
+		for (i = 0; i < 1024; i++) {
 			snprintf(file, sizeof(file), "/dev/bpf%d", i);
 			/* This would be O_WRONLY, but Mac OS X 10.6 has a bug
 			   where that prevents other users of the interface
