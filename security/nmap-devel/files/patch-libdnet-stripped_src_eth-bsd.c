--- libdnet-stripped/src/eth-bsd.c.orig	2025-06-05 15:22:27.000000000 -0700
+++ libdnet-stripped/src/eth-bsd.c	2026-02-02 15:33:01.105641000 -0800
@@ -46,7 +46,7 @@
 
 	if ((e = calloc(1, sizeof(*e))) != NULL) {
 		char file[32] = "/dev/bpf";
-		for (i = 0; i <= 128; i++) {
+		for (i = 0; i <= 1024; i++) {
 			/* This would be O_WRONLY, but Mac OS X 10.6 has a bug
 			   where that prevents other users of the interface
 			   from seeing incoming traffic, even in other
