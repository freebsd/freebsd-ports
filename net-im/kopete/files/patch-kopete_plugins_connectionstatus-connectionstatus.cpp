--- kopete/plugins/connectionstatus/connectionstatusplugin.cpp.orig	Fri Mar 31 22:12:59 2006
+++ kopete/plugins/connectionstatus/connectionstatusplugin.cpp	Fri Mar 31 22:14:53 2006
@@ -65,7 +65,7 @@
 	// netstat -rn in slotProcessStdout() to see if it mentions the
 	// default gateway. If so, we're connected, if not, we're offline
 	m_process = new KProcess;
-	*m_process << "netstat" << "-r";
+	*m_process << "netstat" << "-rfinet";
 
 	connect( m_process, SIGNAL( receivedStdout( KProcess *, char *, int ) ), this, SLOT( slotProcessStdout( KProcess *, char *, int ) ) );
 	connect( m_process, SIGNAL( processExited( KProcess * ) ), this, SLOT( slotProcessExited( KProcess * ) ) );
