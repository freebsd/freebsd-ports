--- src/core/k3bprocess.cpp.orig	Thu Sep 25 13:34:51 2003
+++ src/core/k3bprocess.cpp	Fri Nov  7 12:35:44 2003
@@ -27,7 +27,60 @@
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
 
 
 class K3bProcess::Private
