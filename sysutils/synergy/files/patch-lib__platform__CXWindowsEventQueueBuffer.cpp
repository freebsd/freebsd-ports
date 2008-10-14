--- ./lib/platform/CXWindowsEventQueueBuffer.cpp	2005-04-24 12:32:16.000000000 +0930
+++ ./lib/platform/CXWindowsEventQueueBuffer.cpp	2008-10-02 11:14:18.112098206 +0930
@@ -84,6 +73,8 @@
 	pfds[0].events = POLLIN;
 	int timeout    = (dtimeout < 0.0) ? -1 :
 						static_cast<int>(1000.0 * dtimeout);
+	int remaining  =  timeout;
+	int retval     =  0;
 #else
 	struct timeval timeout;
 	struct timeval* timeoutPtr;
@@ -102,19 +93,31 @@
 	FD_ZERO(&rfds);
 	FD_SET(ConnectionNumber(m_display), &rfds);
 #endif
+	// It's possible that the X server has queued events locally
+	// in xlib's event buffer and not pushed on to the fd. Hence we
+	// can't simply monitor the fd as we may never be woken up.
+	// ie addEvent calls flush, XFlush may not send via the fd hence
+	// there is an event waiting to be sent but we must exit the poll
+	// before it can.
+	// Instead we poll for a brief period of time (so if events
+	// queued locally in the xlib buffer can be processed)
+	// and continue doing this until timeout is reached.
+	// The human eye can notice 60hz (ansi) which is 16ms, however
+	// we want to give the cpu a chance s owe up this to 25ms
+#define TIMEOUT_DELAY 25
 
-	// wait for message from X server or for timeout.  also check
-	// if the thread has been cancelled.  poll() should return -1
-	// with EINTR when the thread is cancelled.
+	while( remaining > 0 && QLength(m_display)==0 && retval==0){
 #if HAVE_POLL
-	poll(pfds, 1, timeout);
+	retval = poll(pfds, 1, TIMEOUT_DELAY); //16ms = 60hz, but we make it > to play nicely with the cpu
 #else
-	select(ConnectionNumber(m_display) + 1,
+	retval = select(ConnectionNumber(m_display) + 1,
 						SELECT_TYPE_ARG234 &rfds,
 						SELECT_TYPE_ARG234 NULL,
 						SELECT_TYPE_ARG234 NULL,
-						SELECT_TYPE_ARG5   timeoutPtr);
+						SELECT_TYPE_ARG5   TIMEOUT_DELAY);
 #endif
+	    remaining-=TIMEOUT_DELAY;
+	}
 
 	{
 		// we're no longer waiting for events
@@ -179,7 +184,7 @@
 CXWindowsEventQueueBuffer::isEmpty() const
 {
 	CLock lock(&m_mutex);
-	return (XPending(m_display) == 0);
+	return (QLength(m_display) == 0 );
 }
 
 CEventQueueTimer*
