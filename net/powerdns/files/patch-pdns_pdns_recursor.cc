--- pdns/pdns_recursor.cc.orig	Thu Jul  3 10:30:03 2003
+++ pdns/pdns_recursor.cc	Thu Jul 10 16:45:27 2003
@@ -35,6 +35,10 @@
 #include "statbag.hh"
 #include "arguments.hh"
 #include "syncres.hh"
+#include <fcntl.h>
+#include <fstream>
+
+string s_programname="pdns_recursor";
 
 #ifndef WIN32
 extern "C" {
@@ -129,6 +133,17 @@
   cache[toLower(qname)+"|"+qt.getName()]=content;
 }
 
+static void writePid(void)
+{
+  string fname=arg()["socket-dir"]+"/"+s_programname+".pid";
+  ofstream of(fname.c_str());
+  if(of)
+    of<<getpid()<<endl;
+  else
+    L<<Logger::Error<<"Requested to write pid for "<<getpid()<<" to "<<fname<<"
+failed: "<<strerror(errno)<<endl;
+}
+
 void init(void)
 {
   // prime root cache
@@ -394,6 +409,7 @@
     arg().set("daemon","Operate as a daemon")="yes";
     arg().set("quiet","Suppress logging of questions and answers")="off";
     arg().set("config-dir","Location of configuration directory (recursor.conf)")=SYSCONFDIR;
+    arg().set("socket-dir","Where the controlsocket will live")=LOCALSTATEDIR;
     arg().setCmd("help","Provide a helpful message");
     L.toConsole(Logger::Warning);
     arg().laxParse(argc,argv); // do a lax parse
@@ -433,6 +449,8 @@
       daemonize();
     }
     signal(SIGUSR1,usr1Handler);
+
+    writePid();
 #endif
 
     vector<TCPConnection> tcpconnections;
