--- src/threading/Manager.cc.orig	2024-05-16 17:25:52 UTC
+++ src/threading/Manager.cc
@@ -65,8 +65,12 @@ void Manager::Terminate()
 			delete *i;
 			}
 
+		for ( auto* iosource : io_sources )
+			delete iosource;
+
 		all_threads.clear();
 		msg_threads.clear();
+		io_sources.clear();
 		terminating = false;
 	}
 
@@ -79,10 +83,11 @@ void Manager::AddThread(BasicThread* thread)
 		StartHeartbeatTimer();
 	}
 
-void Manager::AddMsgThread(MsgThread* thread)
+void Manager::AddMsgThread(MsgThread* thread, iosource::IOSource* iosource)
 	{
 	DBG_LOG(DBG_THREADING, "%s is a MsgThread ...", thread->Name());
 	msg_threads.push_back(thread);
+	io_sources.push_back(iosource);
 	}
 
 void Manager::KillThreads()
@@ -129,6 +134,18 @@ void Manager::SendHeartbeats()
 
 		t->Join();
 		delete t;
+		}
+
+	for ( auto it = io_sources.begin(); it != io_sources.end(); /**/ )
+		{
+		auto* src = *it;
+		if ( ! src->IsOpen() )
+			{
+			delete src;
+			it = io_sources.erase(it);
+			}
+		else
+			++it;
 		}
 	}
 
