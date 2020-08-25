--- conf.c.orig	2014-01-14 22:51:19 UTC
+++ conf.c
@@ -54,6 +54,7 @@ extern int	 yyparse(void);
 bsm_set_head_t	 bsm_set_head;
 int		 lineno = 1;
 char		*conffile;
+struct g_conf opts;
 
 /*
  * Return BSM set named str, or NULL if the set was not found in the BSM set
