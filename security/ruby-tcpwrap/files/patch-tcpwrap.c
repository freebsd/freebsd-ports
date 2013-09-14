--- tcpwrap.c.orig	2003-08-20 03:30:10.000000000 +0000
+++ tcpwrap.c
@@ -25,7 +25,12 @@
  */
 
 #include "ruby.h"
+#ifdef HAVE_RUBY_IO_H		/* Ruby 1.9 and later */
+#include "ruby/io.h"
+#else				/* Ruby 1.8.x */
 #include "rubyio.h"
+#define rb_io_stdio_file(iot)	((iot)->f)
+#endif
 #include <sys/types.h>
 #include <sys/socket.h>
 #include <netinet/in.h>
@@ -101,7 +106,7 @@ static VALUE tcpd_accept(VALUE self)
     tcp_wrapper_t *tcpd;
     VALUE sock;
     int sockfd;
-    OpenFile *fptr;
+    rb_io_t *fptr;
     struct sockaddr_storage addr;
     char client_name[NI_MAXHOST] = STRING_UNKNOWN;
     char client_addr[NI_MAXHOST] = STRING_UNKNOWN;
@@ -113,7 +118,7 @@ static VALUE tcpd_accept(VALUE self)
  again:
     sock = rb_funcall(tcpd->server, rb_intern("accept"), 0);
     GetOpenFile(sock, fptr);
-    sockfd = fileno(fptr->f);
+    sockfd = fileno(rb_io_stdio_file(fptr));
     if (getpeername(sockfd, (struct sockaddr*) &addr, &len) < 0)
 	rb_sys_fail("getpeername(2)");
     error = getnameinfo((struct sockaddr*) &addr, len,
@@ -132,7 +137,7 @@ static VALUE tcpd_accept(VALUE self)
     if (tcpd->ident_lookup)
 	client_user = ident_id(sockfd, tcpd->ident_timeout);
 #endif
-    if (!hosts_ctl(RSTRING(tcpd->daemon)->ptr,
+    if (!hosts_ctl(RSTRING_PTR(tcpd->daemon),
 		   client_name,
 		   client_addr,
 		   (client_user == NULL) ? STRING_UNKNOWN : client_user)) {
@@ -156,8 +161,8 @@ tcpd_s_set_hosts_allow(VALUE self, VALUE
 {
     static char hosts_allow[MAXPATHLEN];
 
-    Check_SafeStr(s);
-    snprintf(hosts_allow, sizeof(hosts_allow), "%s", RSTRING(s)->ptr);
+    SafeStringValue(s);
+    snprintf(hosts_allow, sizeof(hosts_allow), "%s", RSTRING_PTR(s));
     if(access(hosts_allow, R_OK) < 0)
 	rb_warning("cannot read %s", hosts_allow);
     hosts_allow_table = hosts_allow;
@@ -176,8 +181,8 @@ tcpd_s_set_hosts_deny(VALUE self, VALUE 
 {
     static char hosts_deny[MAXPATHLEN];
 
-    Check_SafeStr(s);
-    snprintf(hosts_deny, sizeof(hosts_deny), "%s", RSTRING(s)->ptr);
+    SafeStringValue(s);
+    snprintf(hosts_deny, sizeof(hosts_deny), "%s", RSTRING_PTR(s));
     if(access(hosts_deny, R_OK) < 0)
 	rb_warning("cannot read %s", hosts_deny);
     hosts_deny_table = hosts_deny;
@@ -196,7 +201,7 @@ str_to_ctlstr(VALUE s)
 {
     if(NIL_P(s)) return STRING_UNKNOWN;
     Check_Type(s, T_STRING);
-    return RSTRING(s)->ptr;
+    return RSTRING_PTR(s);
 }
 
 static VALUE
