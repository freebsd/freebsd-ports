--- gateway.cpp.orig	Sat May 18 05:11:23 2002
+++ gateway.cpp	Sat Aug  3 22:10:54 2002
@@ -49,6 +49,7 @@
 
 // The global GATE object
 Gate gate;
+char *ExtIf;
 
 // Callback Function wrapper.  This is needed because ISO forbids a pointer to a bound
 // member function.  This corrects the issue.
@@ -140,6 +141,7 @@
 		UpnpFinish();
 		exit(1);
 	}
+	ExtIf = argv[1];
 	gate.m_ipcon = new IPCon(argv[1]);
 	syslog(LOG_DEBUG, "Registering the root device\n");
 	if ((ret = UpnpRegisterRootDevice(desc_doc_url, GateDeviceCallbackEventHandler,
