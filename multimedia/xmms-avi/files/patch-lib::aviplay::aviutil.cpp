--- lib/aviplay/aviutil.cpp.orig	Wed Nov 29 22:16:09 2000
+++ lib/aviplay/aviutil.cpp	Sun Dec  7 02:30:26 2003
@@ -6,6 +6,7 @@
 #include <wine/winreg.h>
 #include <stdio.h>
 #include <string.h>
+#include <string>
 #include <ctype.h>
 #include <default.h>
 
@@ -139,7 +140,7 @@
 		continue;
 		
 	}
-        cout<<"Available CPU flags: "<<flags<<endl;	
+	fprintf(stdout, "Available CPU flags: %s\n", flags);	
 	if(strstr(flags, "tsc")==0)
 	    have_tsc=0;
 	else
@@ -162,30 +163,30 @@
 	
 	if(freq<0)freq=old_freq();
 	if(have_tsc)
-	    cout<<freq/1000.<<" MHz "<<model<<" processor detected"<<endl; 
+	  fprintf(stdout, "%f MHz %s processor detected", freq/1000, model);
 	fclose(f);
 }
 
 CPU_Info freq;
 
-int Registry::WriteInt(string appname, string valname, int value)
+int Registry::WriteInt(std::string appname, std::string valname, int value)
 {
-    return WriteData(appname, valname, &value, 4);
+  return WriteData(appname, valname, &value, 4);
 }
 
-int Registry::ReadInt(string appname, string valname, int def_value)
+int Registry::ReadInt(std::string appname, std::string valname, int def_value)
 {
-    int res=def_value;
-    if(ReadData(appname, valname, &res, 4)!=0)
-	WriteInt(appname, valname, def_value);
-    return res;
+  int res=def_value;
+  if(ReadData(appname, valname, &res, 4)!=0)
+    WriteInt(appname, valname, def_value);
+  return res;
 }
-int Registry::WriteFloat(string appname, string valname, float value)
+int Registry::WriteFloat(std::string appname, std::string valname, float value)
 {
     return WriteData(appname, valname, &value, 4);
 }
 
-float Registry::ReadFloat(string appname, string valname, float def_value)
+float Registry::ReadFloat(std::string appname, std::string valname, float def_value)
 {
     float res=def_value;
     if(ReadData(appname, valname, &res, 4)!=0)
@@ -193,12 +194,12 @@
     return res;
 }
 
-int Registry::WriteString(string appname, string valname, string value)
+int Registry::WriteString(std::string appname, std::string valname, std::string value)
 {
     return WriteData(appname, valname, value.c_str(), value.length()+1);
 }
 
-string Registry::ReadString(string appname, string valname, string def_value)
+std::string Registry::ReadString(std::string appname, std::string valname, std::string def_value)
 {
     char name[256];
     int result=ReadData(appname, valname, name, 256);
@@ -208,14 +209,14 @@
 	return def_value;
     }	
     name[255]=0;
-    return string(name);
+    return std::string(name);
 }
 
-int Registry::WriteData(string appname, string valname, const void* data, int size)
+int Registry::WriteData(std::string appname, std::string valname, const void* data, int size)
 {
     int result, status, newkey;
 //    cerr<<appname<<" "<<valname<<endl;
-    string fullname=string("Software\\Registry\\")+appname;
+    std::string fullname=std::string("Software\\Registry\\")+appname;
 //    cerr<<fullname<<" qqq"<<endl;
     result=RegCreateKeyExA(HKEY_CURRENT_USER, fullname.c_str(), 0, 0, 0, 0, 0,
 	&newkey, &status);
@@ -226,12 +227,12 @@
     return 0;
 }
 
-int Registry::ReadData(string appname, string valname, void* data, int size)
+int Registry::ReadData(std::string appname, std::string valname, void* data, int size)
 {
     int result, status, newkey;
     if(!data)return -1;
 //    cerr<<appname<<" "<<valname<<endl;
-    string fullname=string("Software\\Registry\\");
+    std::string fullname=std::string("Software\\Registry\\");
 //    cerr<<fullname<<" zzz"<<endl;
     fullname+=appname;
 //    cerr<<fullname<<" zzz"<<endl;
