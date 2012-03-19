--- lib/saslutil.c.orig	2011-10-21 13:59:59.354462366 +0200
+++ lib/saslutil.c	2011-10-21 14:10:55.849675881 +0200
@@ -555,32 +555,44 @@
 		  NULL,		/* don't care abour service/port */
 		  &hints,
 		  &result) != 0) {
-	/* errno on Unix, WSASetLastError on Windows are already done by the function */
-	return (-1);
+        if (abort_if_no_fqdn) {
+	    /* errno on Unix, WSASetLastError on Windows are already done by the function */
+	    return (-1);
+	} else {
+	    goto LOWERCASE;
+	}
     }
 
-    if (abort_if_no_fqdn && (result == NULL || result->ai_canonname == NULL)) {
+    if (result == NULL || result->ai_canonname == NULL) {
 	freeaddrinfo (result);
+        if (abort_if_no_fqdn) {
 #ifdef WIN32
-	WSASetLastError (WSANO_DATA);
+	    WSASetLastError (WSANO_DATA);
 #elif defined(ENODATA)
-	errno = ENODATA;
+	    errno = ENODATA;
 #elif defined(EADDRNOTAVAIL)
-	errno = EADDRNOTAVAIL;
+	    errno = EADDRNOTAVAIL;
 #endif
-	return (-1);
+	    return (-1);
+	} else {
+	    goto LOWERCASE;
+	}
     }
 
-    if (abort_if_no_fqdn && strchr (result->ai_canonname, '.') == NULL) {
+    if (strchr (result->ai_canonname, '.') == NULL) {
 	freeaddrinfo (result);
+        if (abort_if_no_fqdn) {
 #ifdef WIN32
-	WSASetLastError (WSANO_DATA);
+	    WSASetLastError (WSANO_DATA);
 #elif defined(ENODATA)
-	errno = ENODATA;
+	    errno = ENODATA;
 #elif defined(EADDRNOTAVAIL)
-	errno = EADDRNOTAVAIL;
+	    errno = EADDRNOTAVAIL;
 #endif
-	return (-1);
+	    return (-1);
+	} else {
+	    goto LOWERCASE;
+	}
     }
 
 
