--- window.h.orig	2025-05-15 15:31:27 UTC
+++ window.h
@@ -79,7 +79,7 @@ struct pseudowin {
 	char	p_cmd[MAXSTR];
 	char	p_tty[MAXSTR];
 	char	p_inbuf[IOSIZE];	/* buffered writing to p_ptyfd */
-	size_t	p_inlen;
+	int	p_inlen;
 };
 
 /* bits for fdpat: */
@@ -157,9 +157,9 @@ struct Window {
 	int	 w_poll_zombie_timeout;
 	int	 w_ptyfd;		/* fd of the master pty */
 	char	 w_inbuf[IOSIZE];
-	size_t	 w_inlen;
+	int	 w_inlen;
 	char	 w_outbuf[IOSIZE];
-	size_t	 w_outlen;
+	int	 w_outlen;
 	bool	 w_aflag;		/* (-a option) */
 	bool	 w_dynamicaka;		/* should we change name */
 	char	*w_title;		/* name of the window */
