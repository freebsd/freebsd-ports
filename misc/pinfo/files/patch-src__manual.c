--- src/manual.c.orig	Thu Mar 16 23:14:30 2006
+++ src/manual.c	Fri Mar 17 16:00:02 2006
@@ -797,7 +797,7 @@
 				if ((!strchr(p_t1, '(')) &&(!is_in_manlinks(manlinks, p_t1)))
 				{
 					char tempchar;
-					int breakpos;
+					int breakpos, cols_before_link;
 					i = mylink - tmp - 1;
 					if (i < 0)
 						i++;
@@ -830,7 +830,7 @@
 					 */
 
 					/* calculate the number of columns in front of the link */
-					int cols_before_link = width_of_string(tmp, i-1);
+					cols_before_link = width_of_string(tmp, i-1);
 
 					/* a small check */
 					if (!((use_apropos) &&(manualhistorylength == 0)))
