
$FreeBSD$

--- common/mgenApp.cpp.orig
+++ common/mgenApp.cpp
@@ -221,7 +221,7 @@
         nextCmd++;
     }
     return type; 
-};  // end MgenApp::GetCmdType()
+}  // end MgenApp::GetCmdType()
 
 bool MgenApp::ProcessCommands(int argc, const char*const* argv)
 {
@@ -1388,6 +1388,6 @@
 }  // end MgenStreamSource::Read()
 
 // This macro instantiates our MgenApp instance
-PROTO_INSTANTIATE_APP(MgenApp);
+PROTO_INSTANTIATE_APP(MgenApp)
 
 
