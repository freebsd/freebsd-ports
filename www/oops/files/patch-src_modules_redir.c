
$FreeBSD$

--- src/modules/redir.c.orig	Thu Oct 16 18:21:59 2003
+++ src/modules/redir.c	Sun Oct  3 17:23:08 2004
@@ -349,11 +349,9 @@
 
 	/* if this is not on my port */
 	while( n ) {
-	    if (    mp->port == port
-	         && (  (mp->in_addr.s_addr == INADDR_ANY)
-	             ||(mp->in_addr.s_addr == rq->my_sa.sin_addr.s_addr) ) )
-	         break;
+	    if ( mp->so == rq->accepted_so )
+		 break;
	    n--;mp++;
 	}
 	if ( !n ) return(MOD_CODE_OK);	/* not my */
     }
