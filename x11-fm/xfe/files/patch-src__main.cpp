--- src/main.cpp.orig
+++ src/main.cpp
@@ -270,6 +270,7 @@
 	const char *vdrname = "Xfe";
 	int i;
 	FXbool loadicons;
+	FXString cmd;
 	FXString startfiledir1="";
 	FXString startdir2="";
 	FXbool iconic=false;
@@ -307,7 +308,7 @@
     //   - if dpkg exists then the system uses deb packages
     //   - else if rpm exists, then the system uses rpm packages
 	//   - else another (unsupported) package manager is used
-	FXString cmd, str;
+	FXString str;
 
 	cmd="dpkg --version";
 	str=getCommandOutput(cmd);
