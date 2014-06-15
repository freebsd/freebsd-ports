--- ./pith/filter.c.orig	2013-08-14 23:36:22.000000000 -0500
+++ ./pith/filter.c	2014-05-25 19:15:32.000000000 -0500
@@ -7522,8 +7522,6 @@
 		      HD(f)->bitbucket = 0;
 		    else if(!strucmp(s, "running"))
 		      HD(f)->bitbucket = 0;
-		    else if(!strucmp(s, "phone_home") && ps_global->phone_home)
-		      HD(f)->bitbucket = 0;
 #ifdef	_WINDOWS
 		    else if(!strucmp(s, "os_windows"))
 		      HD(f)->bitbucket = 0;
