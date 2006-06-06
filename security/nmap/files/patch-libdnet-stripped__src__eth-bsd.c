#
# $FreeBSD$
#
# - nmap fails to attach to bpf when more than 128 bpfs are busy.
# PR: 98080
#
--- libdnet-stripped/src/eth-bsd.c.orig
+++ libdnet-stripped/src/eth-bsd.c
@@ -45,7 +45,7 @@
 	int i;
 
 	if ((e = calloc(1, sizeof(*e))) != NULL) {
-		for (i = 0; i < 128; i++) {
+		for (i = 0; i < 1024; i++) {
 			snprintf(file, sizeof(file), "/dev/bpf%d", i);
 			e->fd = open(file, O_WRONLY);
 			if (e->fd != -1 || errno != EBUSY)
