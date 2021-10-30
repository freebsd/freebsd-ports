--- src/prefgeneral.cpp
+++ src/prefgeneral.cpp
@@ -324,6 +324,7 @@
 	filesettings_method_changed = false;
 
 	QString player_path = mplayerPath();
+#ifdef MPLAYER_MPV_SELECTION
 	#ifdef OS_UNIX_NOT_MAC
 	if (player_path == PLAYER_COMBO_MPLAYER_PATH || player_path == PLAYER_COMBO_MPV_PATH || !QFile::exists(player_path)) {
 		QString player_name = QFileInfo(player_path).fileName();
@@ -331,6 +332,7 @@
 		if (!found_player.isEmpty()) player_path = found_player;
 	}
 	#endif
+#endif
 	qDebug() << "PrefGeneral::getData: player_path:" << player_path;
 
 	if (pref->mplayer_bin != player_path) {
