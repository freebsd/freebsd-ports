--- src/common/user_auth.c.orig	Fri Nov 14 05:05:33 2003
+++ src/common/user_auth.c	Sat Feb 28 17:09:30 2004
@@ -1043,8 +1043,8 @@
 			DEBUG1("Pgp_get_pgppassfd: PGPPASS '%s'", s );
 			*pgppass = s;
 		} else if( (s = getenv( "PGPPASSFD" )) ){
-			t = 0;
 			char buffer[128];
+			t = 0;
 			pgppassfd = strtol(s,&t,10);
 			if( pgppassfd <= 0 || !t || *t || fstat(pgppassfd, &statb)  ){
 				Errorcode = JABORT;
