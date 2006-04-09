--- src/wwwoffles.c~	Tue Feb 21 04:27:48 2006
+++ src/wwwoffles.c	Fri Apr  7 14:11:43 2006
@@ -3026,7 +3026,7 @@
   This function is used as a callback from gifmodify.c and htmlmodify.l
   ++++++++++++++++++++++++++++++++++++++*/
 
-int wwwoffles_read_data(char *data,size_t len)
+ssize_t wwwoffles_read_data(char *data,size_t len)
 {
  if(modify_err==-1)
     return(0);
