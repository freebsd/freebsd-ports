--- src/threading/MsgThread.h.orig	2024-05-16 17:25:52 UTC
+++ src/threading/MsgThread.h
@@ -30,6 +30,8 @@ class KillMeMessage;
 class FinishedMessage;
 class KillMeMessage;
 
+class MsgThread_IOSource;
+
 	}
 
 /**
@@ -43,7 +45,7 @@ class KillMeMessage;
  * that happens, the thread stops accepting any new messages, finishes
  * processes all remaining ones still in the queue, and then exits.
  */
-class MsgThread : public BasicThread, public iosource::IOSource
+class MsgThread : public BasicThread
 	{
 public:
 	/**
@@ -213,19 +215,13 @@ class MsgThread : public BasicThread, public iosource:
 	 */
 	void GetStats(Stats* stats);
 
-	/**
-	 * Overridden from iosource::IOSource.
-	 */
-	void Process() override;
-	const char* Tag() override { return Name(); }
-	double GetNextTimeout() override { return -1; }
-
 protected:
 	friend class Manager;
 	friend class detail::HeartbeatMessage;
 	friend class detail::FinishMessage;
 	friend class detail::FinishedMessage;
 	friend class detail::KillMeMessage;
+	friend class detail::MsgThread_IOSource;
 
 	/**
 	 * Pops a message sent by the child from the child-to-main queue.
@@ -291,6 +287,11 @@ class MsgThread : public BasicThread, public iosource:
 	 */
 	virtual const zeek::detail::Location* GetLocationInfo() const { return nullptr; }
 
+	/**
+	 * Process() forwarded by MsgThread_IOSource.
+	 */
+	void Process();
+
 private:
 	/**
 	 * Pops a message sent by the main thread from the main-to-chold
@@ -367,7 +368,7 @@ class MsgThread : public BasicThread, public iosource:
 	bool child_sent_finish; // Child thread asked to be finished.
 	bool failed; // Set to true when a command failed.
 
-	zeek::detail::Flare flare;
+	detail::MsgThread_IOSource* io_source = nullptr; // IO source registered with the IO manager.
 	};
 
 /**
