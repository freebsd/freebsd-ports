--- src/core/k3bprocess.h.orig	Fri Aug 29 17:32:44 2003
+++ src/core/k3bprocess.h	Fri Nov  7 12:35:44 2003
@@ -126,5 +126,22 @@
   bool m_suppressEmptyLines;
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
