--- courier/submit2.C.orig	Sat Dec 15 16:19:01 2001
+++ courier/submit2.C	Mon Jan 14 20:32:21 2002
@@ -800,6 +800,7 @@
 		return (1);
 	}
 
+#if !defined(RFC2045_ERR8BITACCEPT)
 	if (rwrfcptr->rfcviolation & RFC2045_ERR8BITHEADER)
 	{
 		rfcerr= SYSCONFDIR "/rfcerr2047.txt";
@@ -810,6 +811,7 @@
 		rfcerr= SYSCONFDIR "/rfcerr2045.txt";
 		dorewrite=1;
         }
+#endif
 	else if (rwrfcptr->rfcviolation & RFC2045_ERRBADBOUNDARY)
 	{
 		rfcerr= SYSCONFDIR "/rfcerr2046.txt";
