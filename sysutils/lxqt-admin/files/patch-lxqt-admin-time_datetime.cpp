--- lxqt-admin-time/datetime.cpp.orig	2021-11-05 10:21:27 UTC
+++ lxqt-admin-time/datetime.cpp
@@ -70,7 +70,7 @@ void DateTimePage::reload()
     ui->edit_time->setTime(QTime::currentTime());
 
     ui->localRTC->setChecked(mLocalRtc);
-#ifndef NO_SYSTEMD
+#if !defined(NO_SYSTEMD) || defined(__FreeBSD__)
     ui->ntp->setChecked(mUseNtp);
 #else
     ui->ntp->setChecked(false);
