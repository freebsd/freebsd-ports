
$FreeBSD$

--- kcm/connect.c.orig
+++ kcm/connect.c
@@ -149,7 +149,7 @@
 	struct sockcred *sc;
 	
 	memset(&msg, 0, sizeof(msg));
-	crmsgsize = CMSG_SPACE(SOCKCREDSIZE(NGROUPS));
+	crmsgsize = CMSG_SPACE(SOCKCREDSIZE(CMGROUP_MAX));
 	if (crmsgsize == 0)
 	    return 1 ;
 
