--- src/moc.c.orig
+++ src/moc.c
@@ -133,7 +133,8 @@ static int run_moc_thread(double interval)
 	return 0;
 }
 
-void update_moc(void)
+int update_moc(void)
 {
 	run_moc_thread(info.music_player_interval * 100000);
+	return 0;
 }
