--- di.c.orig	2007-12-06 16:30:00 UTC
+++ di.c
@@ -61,6 +61,8 @@
 /* Written by: Ralf Hager Oktober 1992                                 */
 /*---------------------------------------------------------------------*/
 /*                                                                     */
+/* Patch from SageMath                                                 */
+/*                                                                     */
 /***********************************************************************/
 /***********************************************************************/
 
@@ -1355,7 +1357,7 @@ INT get_orb_rep(G,m,n,L,len,konstr)
 				m_il_nv(0L,weight_watcher);
 				m_il_nv(0L,perm_vec);
 				copy(S_V_I(FP,0L),fix);
-				sort(fix);
+				sym_sort(fix);
 
 				get_perm(hweight,p,b,S_I_I(n),S_I_I(m),0L,
 						 perm_vec,weight_watcher,fix);
@@ -1502,7 +1504,7 @@ INT get_perm(w,p,b,n,m,ind,perm_vec,ww,fix)
 	if(ind == m)
 	{
 		mult_perm_fix(p,fix,hfix);
-		sort(hfix);
+		sym_sort(hfix);
 		if(!hfix_in_ww(hfix,ww))
 		{
 			inc(ww);
