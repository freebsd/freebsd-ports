--- src/threading/MsgThread.cc.orig	2024-05-16 17:25:52 UTC
+++ src/threading/MsgThread.cc
@@ -213,7 +213,77 @@ bool ReporterMessage::Process()
 
 	return true;
 	}
+//
+// The lifetime of the IO source is decoupled from
+// the thread. The thread may be terminated prior
+// to the IO source being properly unregistered and
+// forgotten by the IO manager. Specifically the
+// threading manager would delete an IO source which
+// the IO manager still believed to be ready.
+//
+// See issue #3682 for more details.
+class MsgThread_IOSource : public iosource::IOSource
+	{
+public:
+	explicit MsgThread_IOSource(MsgThread* thread) : thread(thread)
+		{
+		if ( ! iosource_mgr->RegisterFd(flare.FD(), this) )
+			reporter->FatalError("Failed to register MsgThread fd with iosource_mgr");
 
+		SetClosed(false);
+		}
+
+	~MsgThread_IOSource()
+		{
+		if ( IsOpen() )
+			{
+			if ( thread )
+				reporter->Warning("Have thread %s set in MsgThread_IOSource", thread->Name());
+
+			if ( ! iosource_mgr->UnregisterFd(flare.FD(), this) )
+				reporter->FatalError("Failed to unregister MsgThread fd from iosource_mgr");
+			}
+		}
+
+	void Process() override
+		{
+		flare.Extinguish();
+
+		if ( thread )
+			thread->Process();
+		else
+			{
+			// When there's no thread anymore, unregister
+			// this source from the IO manager and mark
+			// it as closed. The threading manager will then
+			// reap it during heartbeat processing or shutdown.
+			if ( ! iosource_mgr->UnregisterFd(flare.FD(), this) )
+				reporter->FatalError("Failed to unregister MsgThread fd from iosource_mgr");
+
+			SetClosed(true);
+			}
+		}
+
+	const char* Tag() override { return thread ? thread->Name() : "<MsgThread_IOSource orphan>"; }
+
+	double GetNextTimeout() override { return -1; }
+
+	void Fire() { flare.Fire(); };
+
+	// Fire the flare one more time so that
+	// the IO manager will call Process() and
+	// SetClosed(true).
+	void Close()
+		{
+		thread = nullptr;
+		flare.Fire();
+		}
+
+private:
+	MsgThread* thread = nullptr;
+	zeek::detail::Flare flare;
+	};
+
 	} // namespace detail
 
 ////// Methods.
@@ -232,19 +302,22 @@ MsgThread::MsgThread() : BasicThread(), queue_in(this,
 	child_finished = false;
 	child_sent_finish = false;
 	failed = false;
-	thread_mgr->AddMsgThread(this);
 
-	if ( ! iosource_mgr->RegisterFd(flare.FD(), this) )
-		reporter->FatalError("Failed to register MsgThread fd with iosource_mgr");
-
-	SetClosed(false);
+	io_source = new detail::MsgThread_IOSource(this);
+	thread_mgr->AddMsgThread(this, io_source);
 	}
 
 MsgThread::~MsgThread()
 	{
-	// Unregister this thread from the iosource manager so it doesn't wake
-	// up the main poll anymore.
-	iosource_mgr->UnregisterFd(flare.FD(), this);
+	// Unregister this thread from the IO source so we don't
+	// get Process() callbacks anymore. The IO source is
+	// freed by separately by the threading manager after its
+	// last Process() invocation.
+	if ( io_source )
+		{
+		io_source->Close();
+		io_source = nullptr;
+		}
 	}
 
 void MsgThread::OnSignalStop()
@@ -319,7 +392,14 @@ void MsgThread::OnKill()
 
 void MsgThread::OnKill()
 	{
-	SetClosed(true);
+	// Ensure the IO source is closed and won't call Process() on this
+	// thread anymore. The thread got killed, so the threading manager will
+	// remove it forcefully soon.
+	if ( io_source )
+		{
+		io_source->Close();
+		io_source = nullptr;
+		}
 
 	// Send a message to unblock the reader if its currently waiting for
 	// input. This is just an optimization to make it terminate more
@@ -432,7 +512,8 @@ void MsgThread::SendOut(BasicOutputMessage* msg, bool 
 
 	++cnt_sent_out;
 
-	flare.Fire();
+	if ( io_source )
+		io_source->Fire();
 	}
 
 void MsgThread::SendEvent(const char* name, const int num_vals, Value** vals)
@@ -514,8 +595,6 @@ void MsgThread::Process()
 
 void MsgThread::Process()
 	{
-	flare.Extinguish();
-
 	while ( HasOut() )
 		{
 		Message* msg = RetrieveOut();
