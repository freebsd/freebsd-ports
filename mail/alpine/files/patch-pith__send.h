--- ./pith/send.h.orig	2013-08-14 23:36:50.000000000 -0500
+++ ./pith/send.h	2014-05-25 19:15:32.000000000 -0500
@@ -225,8 +225,6 @@
 void	    pine_free_env(METAENV **);
 int	    check_addresses(METAENV *);
 void	    update_answered_flags(REPLY_S *);
-ADDRESS	   *phone_home_from(void);
-unsigned int phone_home_hash(char *);
 int         call_mailer(METAENV *, BODY *, char **, int, void (*)(char *, int),
 			void (*)(PIPE_S *, int, void *));
 int         write_postponed(METAENV *, BODY *);
