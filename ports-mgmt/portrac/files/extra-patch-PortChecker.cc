--- PortChecker.cc.orig	2011-05-29 04:27:22.000000000 -0500
+++ PortChecker.cc	2014-02-22 14:26:23.633015152 -0600
@@ -88,7 +88,7 @@
 	{
 		index = (preferences->getPreference(INDEX_PREF).c_str());
 	}
-	execl("/usr/sbin/pkg_version", "pkg_version", "-I", index, (char *) 0);
+	execl("/usr/sbin/pkg", "pkg", "version", "-I", index, (char *) 0);
 	perror("execl");
 }
 

