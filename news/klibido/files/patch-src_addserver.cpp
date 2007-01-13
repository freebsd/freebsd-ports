--- src/addserver.cpp.orig	Tue Dec 12 20:12:32 2006
+++ src/addserver.cpp	Tue Dec 12 20:13:17 2006
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
