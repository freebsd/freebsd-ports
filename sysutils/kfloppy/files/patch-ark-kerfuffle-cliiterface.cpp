SVN commit 1240907 by rkcosta:

cliinterface: Do not assume a process does not exist in runProcess().

The Q_ASSERT(!m_process) in the beginning of runProcess() was wrong, as when
one is adding files to an archive (or creating an archive) processFinished()
calls list(), which in turn calls runProcess() as well, thus making the assert
fail.

The best thing to do is just wait for the existing process to finish before
launching the new one.

Backport of r1240907, in case the 4.6 ever gets packaged again.

CCBUG: 277393

http://websvn.kde.org/?view=revision&revision=1240908
-- ark/kerfuffle/cliinterface.cpp	2011/06/01 20:35:06	1234597
+++ ark/kerfuffle/cliinterface.cpp	2011/07/11 03:23:39	1240908
@@ -325,10 +325,13 @@
         return false;
     }
 
-    Q_ASSERT(!m_process);
-
     kDebug() << "Executing" << programPath << arguments;
 
+    if (m_process) {
+        m_process->waitForFinished();
+        delete m_process;
+    }
+
 #ifdef Q_OS_WIN
     m_process = new KProcess();
 #else
