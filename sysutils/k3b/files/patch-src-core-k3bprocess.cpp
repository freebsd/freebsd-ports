--- src/core/k3bprocess.cpp.orig	Sun Feb  1 09:18:58 2004
+++ src/core/k3bprocess.cpp	Tue May 11 22:57:03 2004
@@ -28,6 +28,60 @@
 #include <unistd.h>
 #include <stdio.h>
 #include <fcntl.h>
+#include <ktempfile.h>
+#include <stdlib.h>
+#include <qfile.h>
+MyKProcess & MyKProcess::operator<<(const QString& arg)
+{
+    m_args += " " + arg;
+    return *this;
+}
+
+MyKProcess &MyKProcess::operator<<(const char * arg)
+{
+    m_args += " ";
+    m_args += arg;
+    return *this;
+}
+
+MyKProcess &MyKProcess::operator<<(const QCString & arg)
+{
+    m_args += " " + arg;
+    return *this;
+}
+
+bool MyKProcess::start(KProcess::RunMode  runmode, KProcess::Communication comm)
+{
+    // create temp file
+    KTempFile tmpfile;
+    tmpfile.setAutoDelete(true);
+
+    // create call
+    QString call = "/bin/sh -c \"" + m_args + " > " + tmpfile.name() + " 2>&1 \"";
+    printf("MyKProcess call: %s\n", call.latin1());
+
+    // execute it
+    system(call.latin1());
+
+    // read tmp file line by line
+    QFile tmp (tmpfile.name());
+    if ( tmp.open( IO_ReadOnly ) )
+     {
+        QTextStream stream( &tmp );
+        while ( !stream.eof() )
+	{
+	    QString s = stream.readLine() + "\n";
+            printf("MyKProcess reponse: %s", s.latin1());
+
+	    // send line to receivedStdout signal
+            receivedStdout(this, (char *)s.latin1(), strlen(s.latin1()));
+        }
+
+	// close and delete tmp file
+        tmp.close();
+    }
+    return true;
+}
 
 
 
