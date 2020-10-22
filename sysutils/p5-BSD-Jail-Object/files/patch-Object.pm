! 
! - Plug a memory used after free.
! - Try to make things work basically with modern jails
!   (read "make work" as "compile").
!   Ideally one would change the internal API and return arrayrefs
!   of IPs per address family as well as jailname, ... for the new
!   version and keep compat. Most likely one would need to keep the
!   version information along with the cached data.
!   Look at usr.sbin/{jail,jls,jexec} sources for the right ideas.
! 
--- Object.pm.orig	2006-08-08 04:54:29 UTC
+++ Object.pm
@@ -317,21 +317,56 @@ struct xprison
         return NULL;
     }
 
-    free( sxp );
     return xp;
 }
 
+static int
+_is_jail_ip4(char *string, struct xprison *xp)
+{
+	struct in_addr in;
+	struct in_addr *iap;
+	char *q;
+	int i;
+
+	if (inet_pton(AF_INET, string, &in) != 1)
+		return (0);
+	
+	if (xp->pr_ip4s == 0)
+		return (0);
+	q = (char *)(xp + 1);
+	iap = (struct in_addr *)(void *)q;
+	for (i=0; i < xp->pr_ip4s; i++)
+		if (in.s_addr == iap[i].s_addr)
+			return (1);
+	return (0);
+}
+
+static void
+_get_jail_ip4(struct xprison *xp, struct in_addr *ia)
+{
+	struct in_addr *iap;
+	char *q;
+
+	if (xp->pr_ip4s == 0)
+		ia->s_addr = 0;
+	else {
+		q = (char *)(xp + 1);
+		iap = (struct in_addr *)(void *)q;
+		ia->s_addr = iap[0].s_addr;
+	}
+}
+
 // fetch a specific jail's information
 void
 _find_jail( int compare, char *string )
 { 
-    struct xprison *xp;
+    struct xprison *sxp, *xp;
     struct in_addr in;
     size_t i, len;
     Inline_Stack_Vars;
 
     Inline_Stack_Reset;
-    xp  = get_xp();
+    sxp = xp  = get_xp();
     len = sysctl_len();
 
     /*
@@ -341,15 +376,15 @@ _find_jail( int compare, char *string )
     */
 
     for (i = 0; i < len / sizeof(*xp); i++) {
-        in.s_addr = ntohl(xp->pr_ip);
         if (
                 ( compare == 0 && xp->pr_id == atoi(string) )
                 ||
-                ( compare == 1 && strcmp( string, inet_ntoa(in) ) == 0 )
+                ( compare == 1 && _is_jail_ip4(string, xp) )
                 ||
                 ( compare == 2 && strcmp( string, xp->pr_host ) == 0 )
            ) {
             Inline_Stack_Push( sv_2mortal( newSViv( xp->pr_id ) ));
+	    _get_jail_ip4(xp, &in);
             Inline_Stack_Push( sv_2mortal( newSVpvf( inet_ntoa(in) ) ));
             Inline_Stack_Push( sv_2mortal( newSVpvf( xp->pr_host ) ));
             Inline_Stack_Push( sv_2mortal( newSVpvf( xp->pr_path ) ));
@@ -360,6 +395,7 @@ _find_jail( int compare, char *string )
         }
     }
 
+    free ( sxp );
     Inline_Stack_Done;
 }
 
@@ -367,12 +403,12 @@ _find_jail( int compare, char *string )
 void
 _find_jids()
 { 
-    struct xprison *xp;
+    struct xprison *sxp, *xp;
     size_t i, len;
     Inline_Stack_Vars;
 
     Inline_Stack_Reset;
-    xp  = get_xp();
+    sxp = xp  = get_xp();
     len = sysctl_len();
 
     for (i = 0; i < len / sizeof(*xp); i++) {
@@ -380,6 +416,7 @@ _find_jids()
         xp++;
     }
 
+    free ( sxp );
     Inline_Stack_Done;
 }
 
@@ -402,8 +439,9 @@ _create( char *path, char *hostname, char *ipaddr )
     
     j.path      = path;
     j.hostname  = hostname;
-    j.ip_number = ntohl( ip.s_addr );
-    j.version   = 0;
+    j.version   = JAIL_API_VERSION;
+    j.ip4s	= 1;
+    j.ip4	= &ip;
 
     if ( (jid = jail( &j )) == -1 ) return 0;
 
