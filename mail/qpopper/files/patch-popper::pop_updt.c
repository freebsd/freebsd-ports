--- popper/pop_updt.c.orig	Tue Dec 14 17:18:10 2004
+++ popper/pop_updt.c	Tue Dec 14 17:18:57 2004
@@ -531,11 +531,13 @@
             if ( fputs ( buffer, md ) == EOF )
                 break;
 
+	if ( p->bUpdate_status_hdrs ) {
             sprintf ( buffer, "X-UIDL: %s", mp->uidl_str );
             if ( fputs ( buffer, md ) == EOF )
                 break;
             length += strlen ( buffer ) + 1; /* for CRLF */
             lines  ++;
+	}
 
             for ( status_written = 0, inheader = 1;
                   fgets ( buffer, MAXMSGLINELEN, p->drop );
