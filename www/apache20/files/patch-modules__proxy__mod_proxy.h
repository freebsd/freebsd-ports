--- ./modules/proxy/mod_proxy.h.orig	2008-01-03 13:42:06.000000000 +0000
+++ ./modules/proxy/mod_proxy.h	2010-10-21 05:40:53.658621114 +0000
@@ -90,12 +90,12 @@
 
 /* static information about a remote proxy */
 struct proxy_remote {
-    const char *scheme;		/* the schemes handled by this proxy, or '*' */
-    const char *protocol;	/* the scheme used to talk to this proxy */
-    const char *hostname;	/* the hostname of this proxy */
-    apr_port_t  port;		/* the port for this proxy */
-    regex_t *regexp;		/* compiled regex (if any) for the remote */
-    int use_regex;		/* simple boolean. True if we have a regex pattern */
+    const char *scheme;     /* the schemes handled by this proxy, or '*' */
+    const char *protocol;   /* the scheme used to talk to this proxy */
+    const char *hostname;   /* the hostname of this proxy */
+    apr_port_t  port;       /* the port for this proxy */
+    ap_regex_t *regexp;        /* compiled regex (if any) for the remote */
+    int use_regex;          /* simple boolean. True if we have a regex pattern */
 };
 
 struct proxy_alias {
@@ -165,7 +165,7 @@
 typedef struct {
     const char *p;            /* The path */
     int         p_is_fnmatch; /* Is this path an fnmatch candidate? */
-    regex_t    *r;            /* Is this a regex? */
+    ap_regex_t  *r;            /* Is this a regex? */
     const char *ftp_directory_charset;
 } proxy_dir_conf;
 
