--- src/radiusd.c.old	Wed Sep 13 23:45:42 2000
+++ src/radiusd.c	Thu Jan 25 17:51:17 2001
@@ -429,7 +429,7 @@
 		if(pid > 0) {
 			exit(0);
 		}
-#if defined(__linux__) || defined(__svr4__) || defined(__hpux__)
+#if defined(__linux__) || defined(__svr4__) || defined(__hpux__) || defined(__FreeBSD__)
 		setsid();
 #endif
 	}
@@ -577,6 +577,10 @@
  *				Relay reply back to original NAS.
  *
  */
+int rad_accounting_sql(AUTH_REQ *, int, char *, SQLSOCK *);
+int rad_accounting_file(AUTH_REQ *, int, char *);
+
+
 int radrespond(AUTH_REQ *authreq, int activefd, SQLSOCK *acctsock) {
 	int 		dospawn;
 	FUNP 		fun;
@@ -603,8 +607,22 @@
 		namepair = pairfind(authreq->request, PW_USER_NAME);
 		if (namepair == NULL)
 			break;
-		if (proxy_send(authreq, activefd) != 0)
+		if ((e = proxy_send(authreq, activefd)) != 0){
+			REALM *realm = NULL;
+			
+			if( (authreq->code == PW_ACCOUNTING_REQUEST) && 
+			    (e != -1) && (realm = realm_find(authreq->realm)) ) {
+				if( realm->loglocal ){
+					extern char *accounting_method;
+					
+					if(strchr(accounting_method, 'f') != NULL) 
+						rad_accounting_file(authreq, 1, NULL);
+					if(strchr(accounting_method, 's') != NULL)
+						rad_accounting_sql(authreq, 1, NULL, acctsock);
+				}
+			}
 			return 0;
+		}
 		break;
 
 	case PW_AUTHENTICATION_ACK:
