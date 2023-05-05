--- src/client.c.orig	2023-05-05 18:43:35 UTC
+++ src/client.c
@@ -274,6 +274,13 @@ handle_auto(uint8_t trusted, double offset)
 }
 
 
+#ifdef SCM_TIME_INFO
+#define CMSG_MAXLEN (CMSG_SPACE(sizeof(struct timeval)) + \
+	CMSG_SPACE(sizeof(struct sock_timestamp_info)))
+#else
+#define CMSG_MAXLEN CMSG_SPACE(sizeof(struct timeval))
+#endif
+
 /*
  * -1: Not processed, not an NTP message (e.g. icmp induced  ECONNREFUSED)
  *  0: Not prrocessed due to validation issues
@@ -289,7 +296,7 @@ client_dispatch(struct ntp_peer *p, u_int8_t settime, 
 	char			 buf[NTP_MSGSIZE];
 	union {
 		struct cmsghdr	hdr;
-		char		buf[CMSG_SPACE(sizeof(tv))];
+		char		buf[CMSG_MAXLEN];
 	} cmsgbuf;
 #ifdef SO_TIMESTAMP
 	struct cmsghdr		*cmsg;
