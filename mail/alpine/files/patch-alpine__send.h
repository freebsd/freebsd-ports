--- ./alpine/send.h.orig	2013-08-14 23:36:01.000000000 -0500
+++ ./alpine/send.h	2014-05-25 19:15:32.000000000 -0500
@@ -42,7 +42,6 @@
 void	    pine_send(ENVELOPE *, BODY **, char *, ACTION_S *, char *, REPLY_S *,
 		      REDRAFT_POS_S *, char *, PINEFIELD *, int);
 int	    upload_msg_to_pico(char *, size_t, long *);
-void	    phone_home(char *);
 void        create_message_body(BODY **, PATMT *, int);
 char	   *pine_send_status(int, char *, char *, size_t, int *);
 int	    confirm_daemon_send(void);
