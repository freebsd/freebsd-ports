--- bsmtrace.h.orig	2014-02-05 02:34:38 UTC
+++ bsmtrace.h
@@ -38,11 +38,11 @@ int	audit_pipe_fd;	/* XXX not happy abou
 	char	*pflag;
 };
 
-struct g_conf opts;
-int	audit_pipe_fd;	/* XXX not happy about this global */
+extern struct g_conf opts;
+extern int	audit_pipe_fd;	/* XXX not happy about this global */
 
 void	bsmtrace_error(int, char *, ...);
 void	bsmtrace_exit(int);
-void	dprintf(char *, ...);
+void	d_printf(char *, ...);
 void	usage(char *);
 #endif	/* BSM_TRACE_H_ */
