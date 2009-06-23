--- bgpctl/parser.h.orig	2009-01-16 23:03:29.000000000 +0900
+++ bgpctl/parser.h	2009-06-22 14:54:34.000000000 +0900
@@ -63,5 +63,5 @@
 	sa_family_t		 af;
 };
 
-__dead void		 usage(void);
+void		 usage(void);
 struct parse_result	*parse(int, char *[]);
