--- common.h.orig	2007-03-21 09:52:57 UTC
+++ common.h
@@ -155,7 +155,7 @@ extern char *in6addr2str __P((struct in6
 extern int in6_addrscopebyif __P((struct in6_addr *, char *));
 extern int in6_scope __P((struct in6_addr *));
 extern void setloglevel __P((int));
-extern void dprintf __P((int, const char *, const char *, ...));
+extern void d_printf __P((int, const char *, const char *, ...));
 extern int get_duid __P((char *, struct duid *));
 extern void dhcp6_init_options __P((struct dhcp6_optinfo *));
 extern void dhcp6_clear_options __P((struct dhcp6_optinfo *));
