--- courier/submit2.C.orig	Tue Jan 15 17:44:37 2002
+++ courier/submit2.C	Mon Jan 21 15:38:40 2002
@@ -777,6 +777,8 @@
 {
 int	is8bit=0, dorewrite=0, rwmode=0;
 const	char *mime=getenv("MIME");
+const	char *q=getenv("BOFHACCEPT8BIT");
+const	int accept8bit=(q && *q == '1' ? 1 : 0);
 unsigned	n;
 struct	stat	stat_buf;
 const char *rfcerr=NULL;
@@ -800,12 +802,12 @@
 		return (1);
 	}
 
-	if (rwrfcptr->rfcviolation & RFC2045_ERR8BITHEADER)
+	if (!accept8bit && (rwrfcptr->rfcviolation & RFC2045_ERR8BITHEADER))
 	{
 		rfcerr= SYSCONFDIR "/rfcerr2047.txt";
 		dorewrite=1;
         }
-	else if (rwrfcptr->rfcviolation & RFC2045_ERR8BITCONTENT)
+	else if (!accept8bit && (rwrfcptr->rfcviolation & RFC2045_ERR8BITCONTENT))
 	{
 		rfcerr= SYSCONFDIR "/rfcerr2045.txt";
 		dorewrite=1;
