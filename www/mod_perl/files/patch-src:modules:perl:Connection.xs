--- src/modules/perl/Connection.xs.orig	Fri Nov 23 06:19:44 2001
+++ src/modules/perl/Connection.xs	Fri Nov 23 10:29:44 2001
@@ -78,7 +78,11 @@
     RETVAL = newSVpv((char *)&conn->remote_addr,
                       sizeof conn->remote_addr);
     if(sv_addr) {
+#ifdef APACHE6
+        struct sockaddr_storage addr;
+#else
         struct sockaddr_in addr; 
+#endif
         STRLEN sockaddrlen; 
         char * new_addr = SvPV(sv_addr,sockaddrlen); 
         if (sockaddrlen != sizeof(addr)) { 
@@ -106,7 +110,26 @@
 #else
         conn->remote_ip = pstrdup(conn->pool, (char *)SvPV(ST(1),na));
 #endif
+#ifdef APACHE6
+	{
+	  struct addrinfo hints, *res0;
+	  int error;
+
+	  memset(&hints, 0, sizeof(hints));
+	  hints.ai_family = PF_UNSPEC;
+	  hints.ai_flags = AI_NUMERICHOST;
+	  error = getaddrinfo(conn->remote_ip, NULL, &hints, &res0);
+	  if (!error) {
+	    memcpy(&conn->remote_addr, res0->ai_addr, res0->ai_addrlen);
+	    freeaddrinfo(res0);
+	  } else {
+            croak("Bad ip address in remote_ip getaddrinfo failed %s",
+		  gai_strerror(error)); 
+	  }
+	}
+#else
         conn->remote_addr.sin_addr.s_addr = inet_addr(conn->remote_ip);
+#endif
     }
