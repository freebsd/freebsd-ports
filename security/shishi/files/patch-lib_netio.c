--- lib/netio.c.orig	2010-04-01 23:36:30.000000000 +0200
+++ lib/netio.c	2010-04-01 23:36:37.000000000 +0200
@@ -241,9 +241,11 @@ sendrecv_host (Shishi * handle,
 	{
 	  if (transport == TCP)
 	    rc = sendrecv_tcp (handle, ai, indata, inlen, outdata, outlen);
+#ifdef	USE_STARTTLS
 	  else if (transport == TLS)
 	    rc = _shishi_sendrecv_tls (handle, ai, indata, inlen,
 				       outdata, outlen);
+#endif
 	  else
 	    rc = sendrecv_udp (handle, ai, indata, inlen, outdata, outlen);
 
