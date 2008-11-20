--- src/resolver.h.orig	2005-10-15 18:10:01.000000000 +0200
+++ src/resolver.h	2008-11-20 16:14:31.000000000 +0100
@@ -10,8 +10,8 @@
 class Resolver
 {
 	public:
-	Resolver::Resolver(void);
-	Resolver::~Resolver(void);
+	Resolver(void);
+	~Resolver(void);
 	int add_request(char *request, enum resolver_action act);
 
 
