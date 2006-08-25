--- lib/pkgtools.rb.orig	Fri Aug 25 16:38:16 2006
+++ lib/pkgtools.rb	Fri Aug 25 16:38:48 2006
@@ -1022,7 +1022,7 @@
 
     case OS_PLATFORM
     when 'i386', 'sparc64', 'amd64', 'ia64'
-      sprintf('http://pointyhat.FreeBSD.org/errorlogs/%s-%s-%s/',
+      sprintf('http://pointyhat.FreeBSD.org/errorlogs/%s-%s-packages-%s/',
 	      OS_PLATFORM, OS_MAJOR, run)
     else
       raise sprintf('There is no official package builder site yet for the %s platform.',
