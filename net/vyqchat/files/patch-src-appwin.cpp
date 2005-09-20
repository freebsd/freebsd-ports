--- src/appwin.cpp	Tue Jul 19 18:54:11 2005
+++ src/appwin.cpp	Sun Sep 18 21:22:23 2005
@@ -1265,7 +1265,7 @@
 	chattab->write(MAIN_CHANNEL, tmp, special_color);
 	if (settings->getScriptEnabled(EventInfo))
 		Scripting::executeInfoRequest(settings->getScriptFileName(EventInfo), QDateTime::currentDateTime(), from);
-	vc->vc_inforeqack(userslist->getIP(from), from, nick, settings->getHostname(), nick, settings->getIP().toString(), settings->getHideChannels() ? MAIN_CHANNEL: chattab->channelsList(), (status!=STATUS_NORMAL) ? autoanswer : QString(""));
+	vc->vc_inforeqack(userslist->getIP(from), from, nick, settings->getHostname(), nick, settings->getIP().toString(), settings->getHideChannels() ? QString(MAIN_CHANNEL): chattab->channelsList(), (status!=STATUS_NORMAL) ? autoanswer : QString(""));
 }/*}}}*/
 
 void MainWindow::on_vc_inforeqack(const QHostAddress &source, const QString &to, const QString &from, const QString &host, const QString &name, const QString &ip, const QString &channels, const QString &answer, const QString &computer, const QString &software, bool utf)/*{{{*/
