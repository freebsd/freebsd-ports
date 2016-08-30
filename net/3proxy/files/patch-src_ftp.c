--- src/ftp.c.orig	2016-08-24 03:43:37 UTC
+++ src/ftp.c
@@ -174,6 +174,7 @@ SOCKET ftpdata(struct clientparam *param
 	SOCKET s = INVALID_SOCKET, rem;
 	unsigned long b1, b2, b3, b4;
 	unsigned short b5, b6;
+	SASIZETYPE sasize;
 
 	if(socksend(param->remsock, (unsigned char *)"PASV\r\n", 6, conf.timeouts[STRING_S]) != 6){
 		return INVALID_SOCKET;
@@ -187,15 +188,27 @@ SOCKET ftpdata(struct clientparam *param
 	buf[i-2] = 0;
 	if(!(sb = strchr(buf+4, '(')) || !(se= strchr(sb, ')'))) return INVALID_SOCKET;
 	if(sscanf(sb+1, "%lu,%lu,%lu,%lu,%hu,%hu", &b1, &b2, &b3, &b4, &b5, &b6)!=6) return INVALID_SOCKET;
+	sasize = sizeof(param->sinsl);
+ 	if(so._getsockname(param->remsock, (struct sockaddr *)&param->sinsl, &sasize)){return INVALID_SOCKET;}
+	sasize = sizeof(param->sinsr);
+	if(so._getpeername(param->remsock, (struct sockaddr *)&param->sinsr, &sasize)){return INVALID_SOCKET;}
 	rem = param->remsock;
 	param->remsock = INVALID_SOCKET;
 	param->req = param->sinsr;
 	*SAPORT(&param->req) = *SAPORT(&param->sinsr) = htons((unsigned short)((b5<<8)^b6));
+	*SAPORT(&param->sinsl) = 0;
 	i = param->operation;
 	param->operation = FTP_DATA;
 	if((param->res = (*param->srv->authfunc)(param))) {
-		param->remsock = rem;
-		return INVALID_SOCKET;
+		if(param->remsock != INVALID_SOCKET) {
+			so._closesocket(param->remsock);
+			param->remsock = INVALID_SOCKET;
+		}
+		memset(&param->sinsl, 0, sizeof(param->sinsl));
+		if((param->res = (*param->srv->authfunc)(param))) {
+			param->remsock = rem;
+			return INVALID_SOCKET;
+		}
 	}
 	param->operation = i;
 	s = param->remsock;
