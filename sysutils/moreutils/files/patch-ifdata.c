--- ifdata.c.orig	2015-06-03 16:04:42 UTC
+++ ifdata.c
@@ -1,4 +1,4 @@
-#include <error.h>
+#include <err.h>
 #include <stdlib.h>
 #include <sys/types.h>
 #include <sys/socket.h>
@@ -19,7 +19,7 @@
 	#include <net/if.h>
 #endif
 
-#if defined(__APPLE__)
+#if defined(__FreeBSD__)
 	#define s6_addr16 __u6_addr.__u6_addr16
 	#include <net/if.h>
 #endif
@@ -130,7 +130,7 @@ static int do_socket_ioctl(const char *i
 			*ioctl_errno = errno;
 		if (print_error == PRINT_ERROR) {
 			if (errno == ENODEV)
-				error(EXIT_FAILURE, 0,
+				err(EXIT_FAILURE,
 				      "No such network interface: %s", ifname);
 			else
 				fprintf(stderr, "ioctl on %s: %s\n", ifname,
@@ -392,7 +392,7 @@ void please_do(int ndo, int *todo, const
 	for (i=0; i<ndo; i++) {
 		if (!exists &&
 		    (todo[i] != DO_EXISTS) && (todo[i] != DO_PEXISTS))
-			error(EXIT_FAILURE, 0, "No such network interface: %s",
+			err(EXIT_FAILURE, "No such network interface: %s",
 			      ifname);
 
 		switch (todo[i]) {
