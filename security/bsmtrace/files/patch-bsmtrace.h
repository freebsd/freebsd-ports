--- bsmtrace.h.orig	2014-02-05 02:34:38 UTC
+++ bsmtrace.h
@@ -43,6 +43,6 @@ int	audit_pipe_fd;	/* XXX not happy abou
 
 void	bsmtrace_error(int, char *, ...);
 void	bsmtrace_exit(int);
-void	dprintf(char *, ...);
+void	d_printf(char *, ...);
 void	usage(char *);
 #endif	/* BSM_TRACE_H_ */
