Index: include/ntp_config.h
===================================================================
--- include/ntp_config.h	(revision 359675)
+++ include/ntp_config.h	(revision 359676)
@@ -280,7 +280,7 @@
  * Poll Skew List
  */
 
-psl_item psl[17-3+1];		/* values for polls 3-17 */
+extern psl_item psl[17-3+1];	/* values for polls 3-17 */
 				/* To simplify the runtime code we */
 				/* don't want to have to special-case */
 				/* dealing with a default */
