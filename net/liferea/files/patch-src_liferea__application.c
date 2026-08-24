diff --git src/liferea_application.c src/liferea_application.c
index a6ad0dd3..25835f0c 100644
--- src/liferea_application.c
+++ src/liferea_application.c
@@ -143,6 +143,7 @@ on_app_startup (GApplication *gapp, gpointer user_data)
 	/* Configuration necessary for network options, so it
 	   has to be initialized before network_init() */
 	conf_init ();
+	network_init();
 
 	/* Setup update queue handling */
 	app->updateQueue = update_job_queue_get_instance ();
