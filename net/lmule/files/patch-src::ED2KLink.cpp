--- src/ED2KLink.cpp.orig	Sun May 11 11:53:58 2003
+++ src/ED2KLink.cpp	Sun May 11 11:57:00 2003
@@ -216,6 +216,8 @@
 			pEnd = pCh;
 			while( *pEnd ) pEnd++; // make pEnd point to the terminating NULL
 			bAllowSources=true;
+// This code segment does not work with gcc 3.x. At least, under FreeBSD.
+#if defined(__FreeBSD__) && __FreeBSD_version >= 500035
 			// if there's an expiration date...
 			if( *pCh == _T('@') && (pEnd-pCh) > 7 )
 			{
@@ -230,6 +232,7 @@
 				bAllowSources = ( expirationDate.Set(nYear,(wxDateTime::Month)nMonth,nDay,0,0,0,0) == 0l);
 				if (bAllowSources) bAllowSources=(wxDateTime::UNow() < expirationDate);
 			}
+#endif
 
 			// increment pCh to point to the first "ip:port" and check for sources
 			if ( bAllowSources && ++pCh < pEnd ) {
