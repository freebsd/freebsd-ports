--- igmp.c.orig	1999-11-30 17:58:53 UTC
+++ igmp.c
@@ -115,7 +115,7 @@ igmp_read(i, rfd)
     fd_set *rfd;
 {
     register int igmp_recvlen;
-    int dummy = 0;
+    socklen_t dummy = 0;
     
     igmp_recvlen = recvfrom(igmp_socket, igmp_recv_buf, RECV_BUF_SIZE,
 			    0, NULL, &dummy);
@@ -168,7 +168,11 @@ accept_igmp(recvlen)
 #ifdef RAW_INPUT_IS_RAW
     ipdatalen = ntohs(ip->ip_len) - iphdrlen;
 #else
+ #if __FreeBSD_version >= 1000000
+	ipdatalen = ip->ip_len - iphdrlen;
+ #else
     ipdatalen = ip->ip_len;
+ #endif
 #endif
     if (iphdrlen + ipdatalen != recvlen) {
 	log(LOG_WARNING, 0,
@@ -257,11 +261,11 @@ accept_igmp(recvlen)
 	    return;
 	    
 	case DVMRP_INFO_REQUEST:
-	    dvmrp_accept_info_request(src, dst, (char *)(igmp+1), igmpdatalen);
+	    dvmrp_accept_info_request(src, dst, (u_char *)(igmp+1), igmpdatalen);
 	    return;
 
 	case DVMRP_INFO_REPLY:
-	    dvmrp_accept_info_reply(src, dst, (char *)(igmp+1), igmpdatalen);
+	    dvmrp_accept_info_reply(src, dst, (u_char *)(igmp+1), igmpdatalen);
 	    return;
 	    
 	default:
