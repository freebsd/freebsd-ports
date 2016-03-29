--- src/uogetopt.c.orig	2003-05-13 05:06:57 UTC
+++ src/uogetopt.c
@@ -116,7 +116,8 @@ uogetopt_outn (uogetopt_env_t * env,
 #define SETEXITVOID() do { SETEXIT(); return; } while(0)
 #define SETEXITRET(x) do { SETEXIT(); return x; } while(0)
 
-static void outplus(void (*out)(int, const char *),
+static attribute_regparm(2) void
+outplus(void (*out)(int, const char *),
 	const char *s)
 {
 	unsigned int l;
@@ -140,7 +141,7 @@ uogetopt_num(uogetopt_env_t *env, int is
 #define uogetopt_hlong(e,s,o) uogetopt_num(e,1,s,o)
 
 
-static unsigned int 
+static attribute_regparm(2) unsigned int 
 outandcount(void (*out)(int iserr,const char *), const char *s)
 {
 	if (!s) return 0;
@@ -231,7 +232,7 @@ for, but i suppose someone will need the
 	} while (EXPECT(*p,1) && EXPECT(p[1],1));
 }
 
-static void	
+static attribute_regparm(2) void	
 uogetopt_printver(uogetopt_env_t *env, int maxlen)
 {
 	int l;
@@ -249,7 +250,7 @@ uogetopt_printver(uogetopt_env_t *env, i
 	env->out(0,env->version);
 }
 
-static void 
+static attribute_regparm(3) void 
 handle_argopt(uogetopt_env_t *env, uogetopt_t *o, char *arg)
 {
 	int at=o->argtype;
@@ -274,7 +275,7 @@ handle_argopt(uogetopt_env_t *env, uoget
 #define PRINTHELP_MODE_SHORT 0
 #define PRINTHELP_MODE_NORM  1
 #define PRINTHELP_MODE_LONG  2
-static void 
+static attribute_regparm(2) void 
 uogetopt_printhelp(uogetopt_env_t *env, int mode)
 {
 	uogetopt_t *opts=env->opts;
