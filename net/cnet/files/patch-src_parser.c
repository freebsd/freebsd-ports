--- src/parser.c.orig	Wed May 12 18:13:44 2004
+++ src/parser.c	Sun Jun 12 17:04:02 2005
@@ -26,6 +26,8 @@
     59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
  */
 
+extern void	init_reboot_args(NODEATTR *na, int argc, char **argv);
+
 #define expect(t,msg)	if(token == t) gettoken(); \
 			else compile_error("%s expected\n", msg)
 
@@ -224,8 +226,6 @@
 	check_string(&(na->outputfile));
 	break;
     case T_ATTR_NODE_REBOOTARGS : {
-	extern	void init_reboot_args(NODEATTR *na, int argc, char **argv);
-
 	int	argc;
 	char	**argv;
 	char	*str, *s, *t, ch;
@@ -420,7 +420,6 @@
 static int node_defn(CnetNodetype nodetype)
 {
     extern int	add_node(CnetNodetype, char *, int, int *);
-    extern void	init_reboot_args(int n, int argc, char **argv);
 
     int		thisnode, wasnew;
 
