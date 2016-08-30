--- src/common.c.orig	2016-08-24 03:41:59 UTC
+++ src/common.c
@@ -692,8 +692,8 @@ int doconnect(struct clientparam * param
 #else
 		fcntl(param->remsock,F_SETFL,O_NONBLOCK);
 #endif
-		size = sizeof(param->sinsl);
 	}
+	size = sizeof(param->sinsl);
 	if(so._getsockname(param->remsock, (struct sockaddr *)&param->sinsl, &size)==-1) {return (15);}
  }
  return 0;
