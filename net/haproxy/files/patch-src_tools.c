--- src/tools.c.orig	2021-12-23 16:47:51 UTC
+++ src/tools.c
@@ -1015,12 +1015,14 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 	} else {
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 
 	if (strncmp(str2, "stream+", 7) == 0) {
 		str2 += 7;
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "dgram+", 6) == 0) {
 		str2 += 6;
@@ -1032,6 +1034,7 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		str2 += 5;
 		proto_type = PROTO_TYPE_DGRAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 
 	if (strncmp(str2, "unix@", 5) == 0) {
@@ -1050,6 +1053,7 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		ss.ss_family = AF_UNIX;
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "abns@", 5) == 0) {
 		str2 += 5;
@@ -1076,6 +1080,7 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		ss.ss_family = AF_INET;
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "mptcp4@", 7) == 0) {
 		str2 += 7;
@@ -1096,6 +1101,7 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		ss.ss_family = AF_INET6;
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "mptcp6@", 7) == 0) {
 		str2 += 7;
@@ -1116,6 +1122,7 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		ss.ss_family = AF_UNSPEC;
 		proto_type = PROTO_TYPE_STREAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "mptcp@", 6) == 0) {
 		str2 += 6;
@@ -1136,12 +1143,14 @@ struct sockaddr_storage *str2sa_range(const char *str, int *port, int *low, int
 		ss.ss_family = AF_INET;
 		proto_type = PROTO_TYPE_DGRAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "quic6@", 6) == 0) {
 		str2 += 6;
 		ss.ss_family = AF_INET6;
 		proto_type = PROTO_TYPE_DGRAM;
 		ctrl_type = SOCK_STREAM;
+		alt_proto = 0;
 	}
 	else if (strncmp(str2, "fd@", 3) == 0) {
 		str2 += 3;
