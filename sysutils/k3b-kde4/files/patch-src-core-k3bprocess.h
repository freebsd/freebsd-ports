--- src/core/k3bprocess.h.orig	Tue Jan 27 09:19:13 2004
+++ src/core/k3bprocess.h	Tue May 11 22:57:03 2004
@@ -194,4 +194,21 @@
   KProcess* m_process;
 };
 
+/** This is a KProcess fake class. It uses system() to call the process
+ * and waits for its return. It redirects all output into a file and
+ * reads this file after the system() call. The redirected output
+ * (out and err!) is sent to the receivedStdout signal. This eliminates
+ * the problem reported as bug
+ * http://www.FreeBSD.org/cgi/query-pr.cgi?pr=ports/51651
+ */
+class MyKProcess : public KProcess
+{
+  Q_OBJECT
+  QString m_args;
+public:
+  MyKProcess &operator<<(const QString& arg);
+ MyKProcess &operator<<(const char * arg);
+ MyKProcess &operator<<(const QCString & arg);
+ bool start(RunMode  runmode = NotifyOnExit, Communication comm = NoCommunication);
+};
 #endif
