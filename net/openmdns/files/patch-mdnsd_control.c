--- mdnsd/control.c.orig	2017-03-10 09:24:12 UTC
+++ mdnsd/control.c
@@ -53,6 +53,8 @@ void		 control_group_add_service(struct ctl_conn *, st
 
 extern struct mdnsd_conf *conf;
 
+struct control_state control_state;
+
 void
 control_lookup(struct ctl_conn *c, struct imsg *imsg)
 {
