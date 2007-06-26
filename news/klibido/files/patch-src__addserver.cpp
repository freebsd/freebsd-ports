--- ./src/addserver.cpp.orig	2006-01-06 09:44:19.000000000 -0600
+++ ./src/addserver.cpp	2007-06-25 23:04:41.000000000 -0500
@@ -27,7 +27,7 @@
 	buttonOk->setIconSet(KGlobal::iconLoader()->loadIcon("button_ok", KIcon::Small, 0, false));
 	buttonCancel->setIconSet(KGlobal::iconLoader()->loadIcon("button_cancel", KIcon::Small, 0, false));
 	m_priorityInput->setRange(1,10,1,false);
-	m_threadInput->setRange(1,10,1,false);
+	m_threadInput->setRange(1,20,1,false);
 	m_timeoutInput->setRange(60,600,5,false);
 	m_threadTimeoutInput->setRange(1,30,1,false);
 	validator=new QIntValidator(1,65535,this);
@@ -90,7 +90,7 @@
 	buttonOk->setIconSet(KGlobal::iconLoader()->loadIcon("button_ok", KIcon::Small, 0, false));
 	buttonCancel->setIconSet(KGlobal::iconLoader()->loadIcon("button_cancel", KIcon::Small, 0, false));
 	m_priorityInput->setRange(1,10,1,false);
-	m_threadInput->setRange(1,10,1,false);
+	m_threadInput->setRange(1,20,1,false);
 	m_timeoutInput->setRange(60,600,5,false);
 	m_threadTimeoutInput->setRange(1,30,1,false);
 	validator=new QIntValidator(1,65535,this);
