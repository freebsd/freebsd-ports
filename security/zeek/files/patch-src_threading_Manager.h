--- src/threading/Manager.h.orig	2024-05-16 17:25:52 UTC
+++ src/threading/Manager.h
@@ -127,8 +127,9 @@ class Manager (protected)
 	 * MsgThread constructor makes sure to do so.
 	 *
 	 * @param thread The thread.
+	 * @param iosource The IO source of the thread.
 	 */
-	void AddMsgThread(MsgThread* thread);
+	void AddMsgThread(MsgThread* thread, iosource::IOSource* iosource);
 
 	void Flush();
 
@@ -148,6 +149,9 @@ class Manager (protected)
 
 	using msg_thread_list = std::list<MsgThread*>;
 	msg_thread_list msg_threads;
+
+	using io_source_list = std::list<iosource::IOSource*>;
+	io_source_list io_sources;
 
 	bool did_process; // True if the last Process() found some work to do.
 	double next_beat; // Timestamp when the next heartbeat will be sent.
