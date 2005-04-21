--- krdc/rdp/krdpview.cpp.orig	Thu Feb  3 16:52:10 2005
+++ krdc/rdp/krdpview.cpp	Thu Apr 21 14:37:11 2005
@@ -210,8 +210,8 @@
 	if(!m_user.isEmpty())     { *m_process << "-u" << m_user; }
 	if(!m_password.isEmpty()) { *m_process << "-p" << m_password; }
 	*m_process << "-X" << ("0x" + QString::number(m_container->winId(), 16));
-	*m_process << (m_host + ":" + QString::number(m_port));
 	*m_process << "-a" << QString::number(hp->colorDepth());
+	*m_process << (m_host + ":" + QString::number(m_port));
 	connect(m_process, SIGNAL(processExited(KProcess *)), SLOT(processDied(KProcess *)));
 	connect(m_process, SIGNAL(receivedStderr(KProcess *, char *, int)), SLOT(receivedStderr(KProcess *, char *, int)));
 	connect(m_container, SIGNAL(embeddedWindowDestroyed()), SLOT(connectionClosed()));
