--- kopete/protocols/oscar/liboscar/client.cpp	2006/08/17 13:37:13
+++ kopete/protocols/oscar/liboscar/client.cpp	2006/10/31 18:48:12
@@ -340,6 +340,7 @@
 		//we've finished logging in. start the services setup
 		kdDebug(OSCAR_RAW_DEBUG) << k_funcinfo << "stage two done. setting up services" << endl;
 		initializeStaticTasks();
+		d->ownStatusTask->go();
 		ServiceSetupTask* ssTask = new ServiceSetupTask( d->connections.defaultConnection()->rootTask() );
 		connect( ssTask, SIGNAL( finished() ), this, SLOT( serviceSetupFinished() ) );
 		ssTask->go( true ); //fire and forget
