--- src/libspf2/spf_compile.c	2008-11-03 15:37:33.000000000 -0500
+++ src/libspf2/spf_compile.c	2009-09-07 23:46:02.000000000 -0400
@@ -778,7 +778,7 @@
 	const char			*end;
 	const char			*p;
 
-	char				 buf[ INET_ADDRSTRLEN ];
+	char				 buf[ INET6_ADDRSTRLEN ];
 	size_t				 len;
 	int					 err;
 
