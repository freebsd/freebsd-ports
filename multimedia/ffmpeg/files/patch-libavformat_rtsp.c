--- libavformat/rtsp.c.orig	2016-11-26 17:12:14 UTC
+++ libavformat/rtsp.c
@@ -1598,7 +1598,12 @@ int ff_rtsp_make_setup_request(AVFormatC
             }
             if (ttl > 0)
                 snprintf(optbuf, sizeof(optbuf), "?ttl=%d", ttl);
-            getnameinfo((struct sockaddr*) &addr, sizeof(addr),
+            getnameinfo((struct sockaddr*) &addr,
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                        ((struct sockaddr*) &addr)->sa_len,
+#else
+                        sizeof(addr),
+#endif
                         namebuf, sizeof(namebuf), NULL, 0, NI_NUMERICHOST);
             ff_url_join(url, sizeof(url), "rtp", NULL, namebuf,
                         port, "%s", optbuf);
@@ -1806,8 +1811,13 @@ redirect:
         goto fail;
     }
     if (!getpeername(tcp_fd, (struct sockaddr*) &peer, &peer_len)) {
-        getnameinfo((struct sockaddr*) &peer, peer_len, host, sizeof(host),
-                    NULL, 0, NI_NUMERICHOST);
+        getnameinfo((struct sockaddr*) &peer, 
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                    ((struct sockaddr*) &peer)->sa_len,
+#else
+                    peer_len,            
+#endif
+		    host, sizeof(host), NULL, 0, NI_NUMERICHOST);
     }
 
     /* request options supported by the server; this also detects server
@@ -2283,7 +2293,12 @@ static int sdp_read_header(AVFormatConte
         if (!(rt->rtsp_flags & RTSP_FLAG_CUSTOM_IO)) {
             AVDictionary *opts = map_to_opts(rt);
 
-            getnameinfo((struct sockaddr*) &rtsp_st->sdp_ip, sizeof(rtsp_st->sdp_ip),
+            getnameinfo((struct sockaddr*) &rtsp_st->sdp_ip,
+#if HAVE_STRUCT_SOCKADDR_SA_LEN
+                        ((struct sockaddr*) &rtsp_st->sdp_ip)->sa_len,
+#else
+                        sizeof(rtsp_st->sdp_ip),
+#endif
                         namebuf, sizeof(namebuf), NULL, 0, NI_NUMERICHOST);
             ff_url_join(url, sizeof(url), "rtp", NULL,
                         namebuf, rtsp_st->sdp_port,
