
mkdir /usr/ports/net/dcgui/files
Save the patch bellow in a file named patch-main.cpp in the new files 
directory.
cd /usr/ports/net/dcgui/ && make deinstall reinstall clean

--- patch-main.cpp begins here ---
--- dcgui/main.cpp.orig	Thu Aug 21 11:55:16 2003
+++ dcgui/main.cpp	Tue Oct 14 14:02:01 2003
@@ -182,6 +182,8 @@
 		arg_0 = CString("/usr/bin/") + argv[0];
 	else if ( d.IsFile( CString("/usr/local/bin/") + argv[0], FALSE ) )
 		arg_0 = CString("/usr/local/bin/") + argv[0];
+	else if ( d.IsFile( CString("/usr/X11R6/bin/") + argv[0], FALSE ) )
+		arg_0 = CString("/usr/X11R6/bin/") + argv[0];
 	else
 		printf("Can't resolve path for '%s'\n",argv[0]);
 #endif
--- patch-main.cpp ends here ---


