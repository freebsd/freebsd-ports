--- main.cpp.orig	Fri Feb 14 13:38:07 2003
+++ main.cpp	Fri Feb 14 13:41:54 2003
@@ -28,6 +28,8 @@
 #include <qlineedit.h>
 #include <qmessagebox.h>
 
+#include <netinet/in.h>
+
 void load_protocol_list();
 void load_service_list();
 void load_interface_list();
@@ -192,7 +194,7 @@
 	char tmpstr[500];
 	QString rcfile_name = getpwuid(getuid())->pw_dir;
 	rcfile_name+="/.qtfwrc";
-	ifstream rcfile(rcfile_name,ios::nocreate);
+	ifstream rcfile(rcfile_name,ios::in);
 	app_rc.style = "Windows";
 	app_rc.browser = "netscape";
 	
