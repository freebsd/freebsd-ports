$FreeBSD$

A workaround for a bug in qt-3.0.3. This patch file should be removed
if we ever upgrade to qt-3.0.5

--- src/chatdlg.cpp.orig	Tue Jul 23 21:08:25 2002
+++ src/chatdlg.cpp	Tue Jul 23 21:09:59 2002
@@ -384,13 +384,13 @@
 
 	//t->setUpdatesEnabled(FALSE);
 	if(emote) {
-		t->append(QString("<font color=\"%1\">").arg(color) + QString("[%1]").arg(timestr) + QString(" *%1 ").arg(expandEntities(who)) + txt + "</font>");
+		t->append(QString("<BR><font color=\"%1\">").arg(color) + QString("[%1]").arg(timestr) + QString(" *%1 ").arg(expandEntities(who)) + txt + "</font>");
 	}
 	else {
 		if(option.chatSays)
-			t->append(QString("<font color=\"%1\">").arg(color) + QString("[%1] ").arg(timestr) + expandEntities(who) + QString(" says:</font><br>") + txt);
+			t->append(QString("<BR><font color=\"%1\">").arg(color) + QString("[%1] ").arg(timestr) + expandEntities(who) + QString(" says:</font><br>") + txt);
 		else
-			t->append(QString("<font color=\"%1\">").arg(color) + QString("[%1] &lt;").arg(timestr) + expandEntities(who) + QString("&gt;</font> ") + txt);
+			t->append(QString("<BR><font color=\"%1\">").arg(color) + QString("[%1] &lt;").arg(timestr) + expandEntities(who) + QString("&gt;</font> ") + txt);
 	}
 	if(!msg.subject.isEmpty()) {
 		t->append(QString("<b>") + tr("Subject:") + "</b> " + QString("%1").arg(expandEntities(msg.subject)));
