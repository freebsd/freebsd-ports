--- ccxstream.c.orig	Mon Mar 17 11:29:15 2003
+++ ccxstream.c	Tue May 15 15:02:31 2007
@@ -1004,7 +1004,7 @@
 	for (fh = 0; fh < CC_XSTREAM_MAX_OPEN_FILES; fh++)
 	  if (conn->open_file_handle[fh] == handle)
 	    break;
-	if (fh >= CC_XSTREAM_MAX_OPEN_FILES)
+	if ( (fh >= CC_XSTREAM_MAX_OPEN_FILES) || (conn->open_file_handle[fh] <= 0) )
 	  {
 	    cc_xstream_send_error(conn, id, CC_XSTREAM_XBMSP_ERROR_INVALID_HANDLE, "Invalid file handle.");
 	    return 1;
@@ -1016,10 +1016,19 @@
 	  }
 	hlp = cc_xmalloc(rlen);
 	sz = fread(hlp, 1, rlen, conn->f[fh]);
+	if ( (sz < rlen) && ( (ferror(conn->f[fh]) != 0) || (feof(conn->f[fh]) == 0) ) )
+	  {
+	    fclose(conn->f[fh]);
+	    conn->f[fh] = NULL;
+	    cc_xstream_send_error(conn, id, CC_XSTREAM_XBMSP_ERROR_ILLEGAL_SEEK, "File read failed.");
+	  }
+	else
+	  {
 	cc_xstream_write_int(conn, 1 + 4 + 4 + sz);
 	cc_xstream_write_byte(conn, (int)CC_XSTREAM_XBMSP_PACKET_FILE_CONTENTS);
 	cc_xstream_write_int(conn, id);
 	cc_xstream_write_data_string(conn, (unsigned char *)hlp, sz);
+	  }
 	cc_xfree(hlp);
 	return 1;
       }
@@ -1661,6 +1670,16 @@
   setsockopt(prog->s, SOL_SOCKET, SO_REUSEPORT, (char *)&c, sizeof (c));
 #endif /* SO_REUSEPORT */
 
+#ifdef TCP_NODELAY
+  c = 1;
+  setsockopt(prog->s, IPPROTO_TCP, TCP_NODELAY, (char *)&c, sizeof (c));
+#endif /* TCP_NODELAY */
+
+#ifdef SO_KEEPALIVE
+  c = 1;
+  setsockopt(prog->s, SOL_SOCKET, SO_KEEPALIVE, (char *)&c, sizeof (c));
+#endif /* SO_KEEPALIVE */
+
   memset(&sa, 0, sizeof (sa));
   sa.sin_family = AF_INET;
   sa.sin_addr = la;
@@ -1693,6 +1712,10 @@
       c = 1;
       setsockopt(prog->bs, SOL_SOCKET, SO_BROADCAST, (char *)&c, sizeof (c));
 #endif /* SO_BROADCAST */
+#ifdef SO_KEEPALIVE
+      c = 1;
+      setsockopt(prog->bs, SOL_SOCKET, SO_KEEPALIVE, (char *)&c, sizeof (c));
+#endif /* SO_KEEPALIVE */
 
       memset(&sa, 0, sizeof (sa));
       sa.sin_family = AF_INET;
