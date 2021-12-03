--- src/librssguard/miscellaneous/notification.cpp.orig	2021-10-15 11:13:56 UTC
+++ src/librssguard/miscellaneous/notification.cpp
@@ -7,7 +7,7 @@
 #include <QDir>
 
 #if !defined(Q_OS_OS2)
-#include <QMediaPlayer>
+#include <QSoundEffect>
 #endif
 
 Notification::Notification(Notification::Event event, bool balloon, const QString& sound_path, int volume)
@@ -32,25 +32,25 @@ void Notification::setSoundPath(const QString& sound_p
 void Notification::playSound(Application* app) const {
   if (!m_soundPath.isEmpty()) {
 #if !defined(Q_OS_OS2)
-    QMediaPlayer* play = new QMediaPlayer(app);
+    QSoundEffect* play = new QSoundEffect(app);
 
-    QObject::connect(play, &QMediaPlayer::stateChanged, play, [play](QMediaPlayer::State state) {
-      if (state == QMediaPlayer::State::StoppedState) {
+    QObject::connect(play, &QSoundEffect::playingChanged, play, [play]() {
+      if (!play->isPlaying()) {
         play->deleteLater();
       }
     });
 
     if (m_soundPath.startsWith(QSL(":"))) {
-      play->setMedia(QMediaContent(QUrl(QSL("qrc") + m_soundPath)));
+      play->setSource(QUrl(QSL("qrc") + m_soundPath));
 
     }
     else {
-      play->setMedia(QMediaContent(
+      play->setSource(
                        QUrl::fromLocalFile(
-                         QDir::toNativeSeparators(app->replaceDataUserDataFolderPlaceholder(m_soundPath)))));
+                         QDir::toNativeSeparators(app->replaceDataUserDataFolderPlaceholder(m_soundPath))));
     }
 
-    play->setVolume(m_volume);
+    play->setVolume(static_cast<qreal>(m_volume) / 100);
     play->play();
 #endif
   }
