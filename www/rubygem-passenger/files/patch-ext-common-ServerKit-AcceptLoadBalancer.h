--- ext/common/ServerKit/AcceptLoadBalancer.h.orig	2015-03-13 02:38:22.000000000 +0300
+++ ext/common/ServerKit/AcceptLoadBalancer.h	2015-03-13 02:39:45.000000000 +0300
@@ -1,6 +1,6 @@
 /*
  *  Phusion Passenger - https://www.phusionpassenger.com/
- *  Copyright (c) 2014 Phusion
+ *  Copyright (c) 2014-2015 Phusion
  *
  *  "Phusion Passenger" is a trademark of Hongli Lai & Ninh Bui.
  *
@@ -26,9 +26,12 @@
 #define _PASSENGER_SERVER_KIT_ACCEPT_LOAD_BALANCER_H_
 
 #include <boost/bind.hpp>
+#include <boost/cstdint.hpp>
+#include <boost/config.hpp>
 #include <oxt/thread.hpp>
 #include <oxt/macros.hpp>
 #include <vector>
+#include <limits>
 #include <cassert>
 #include <cerrno>
 
@@ -41,6 +44,7 @@
 
 #include <Constants.h>
 #include <Logging.h>
+#include <Utils.h>
 #include <Utils/IOUtils.h>
 
 namespace Passenger {
@@ -50,6 +54,32 @@
 using namespace boost;
 
 
+/**
+ * Listens for client connections and load balances them to multiple
+ * Server objects in a round-robin manner.
+ *
+ * Normally, the Server class listens for client connections directly.
+ * But this is inefficient in multithreaded situations where you are
+ * running one Server and event loop per CPU core, that all happen to
+ * listen on the same server socket. This is because every time a client
+ * connects, all threads wake up, but only one thread will succeed in
+ * accept()ing the client.
+ *
+ * Furthermore, it can also be very easy for threads to become
+ * unbalanced. If a burst of clients connect to the server socket,
+ * then it is very likely that a single Server accepts all of
+ * those clients. This can result in situations where, for example,
+ * thread 1 has 40 clients and thread 2 has only 3.
+ *
+ * The AcceptLoadBalancer solves this problem by being the sole entity
+ * that listens on the server socket. All client sockets that it
+ * accepts are distributed to all registered Server objects, in a
+ * round-robin manner.
+ *
+ * Inside the "PassengerAgent server", we activate AcceptLoadBalancer
+ * only if `server_threads > 1`, which is often the case because
+ * `server_threads` defaults to the number of CPU cores.
+ */
 template<typename Server>
 class AcceptLoadBalancer {
 private:
@@ -59,15 +89,24 @@
 	struct pollfd pollers[1 + SERVER_KIT_MAX_SERVER_ENDPOINTS];
 	int newClients[ACCEPT_BURST_COUNT];
 
-	unsigned int nEndpoints: 2;
-	bool accept4Available: 1;
-	bool quit: 1;
-	unsigned int newClientCount: 4;
+	unsigned int nEndpoints;
+	boost::uint8_t newClientCount;
+	boost::uint8_t nextServer;
+	bool accept4Available;
+	bool quit;
 
-	unsigned int nextServer;
 	int exitPipe[2];
 	oxt::thread *thread;
 
+	#if __cplusplus >= 199711L && !defined(BOOST_NO_STATIC_ASSERT)
+		static_assert(std::numeric_limits<typeof(nEndpoints)>::max()
+			>= SERVER_KIT_MAX_SERVER_ENDPOINTS,
+			"nEndpoints's type is too small to accomodate for SERVER_KIT_MAX_SERVER_ENDPOINTS");
+		static_assert(std::numeric_limits<typeof(newClientCount)>::max()
+			>= ACCEPT_BURST_COUNT,
+			"newClientCount's type is too small to accomodate for ACCEPT_BURST_COUNT");
+	#endif
+
 	void pollAllEndpoints() {
 		pollers[0].fd = exitPipe[0];
 		pollers[0].events = POLLIN;
@@ -75,18 +114,28 @@
 			pollers[i + 1].fd = endpoints[i];
 			pollers[i + 1].events = POLLIN;
 		}
-		if (poll(pollers, nEndpoints + 1, -1) == -1) {
+
+		int ret;
+		do {
+			ret = poll(pollers, nEndpoints + 1, -1) == -1;
+		} while (ret == -1 && pollErrnoShouldRetry(errno));
+		if (ret == -1) {
 			int e = errno;
 			throw SystemException("poll() failed", e);
 		}
 	}
 
+	bool pollErrnoShouldRetry(int e) const {
+		return e == EAGAIN
+			|| e == EWOULDBLOCK
+			|| e == EINTR;
+	}
+
 	bool acceptNewClients(int endpoint) {
-		unsigned int i;
 		bool error = false;
 		int fd, errcode = 0;
 
-		for (i = 0; i < ACCEPT_BURST_COUNT; i++) {
+		while (newClientCount < ACCEPT_BURST_COUNT) {
 			fd = acceptNonBlockingSocket(endpoint);
 			if (fd == -1) {
 				error = true;
@@ -94,11 +143,11 @@
 				break;
 			}
 
-			newClients[i] = fd;
+			P_TRACE(2, "Accepted client file descriptor: " << fd);
+			newClients[newClientCount] = fd;
+			newClientCount++;
 		}
 
-		newClientCount = i;
-
 		if (error && errcode != EAGAIN && errcode != EWOULDBLOCK) {
 			P_ERROR("Cannot accept client: " << getErrorDesc(errcode) <<
 				" (errno=" << errcode << "). " <<
@@ -121,6 +170,8 @@
 
 		for (i = 0; i < newClientCount; i++) {
 			ServerKit::Context *ctx = servers[nextServer]->getContext();
+			P_TRACE(2, "Feeding client to server thread " << nextServer <<
+				": file descriptor " << newClients[i]);
 			ctx->libev->runLater(boost::bind(feedNewClient, servers[nextServer],
 				newClients[i]));
 			nextServer = (nextServer + 1) % servers.size();
@@ -182,13 +233,19 @@
 				quit = true;
 				break;
 			}
-			for (unsigned i = 0; i < nEndpoints; i++) {
+
+			unsigned int i = 0;
+			newClientCount = 0;
+
+			while (newClientCount < ACCEPT_BURST_COUNT && i < nEndpoints) {
 				if (pollers[i + 1].revents & POLLIN) {
 					if (!acceptNewClients(endpoints[i])) {
 						break;
 					}
 				}
+				i++;
 			}
+
 			distributeNewClients();
 		}
 	}
@@ -198,10 +255,10 @@
 
 	AcceptLoadBalancer()
 		: nEndpoints(0),
-		  accept4Available(true),
-		  quit(false),
 		  newClientCount(0),
 		  nextServer(0),
+		  accept4Available(true),
+		  quit(false),
 		  thread(NULL)
 	{
 		if (pipe(exitPipe) == -1) {
@@ -248,7 +305,8 @@
 	}
 
 	void start() {
-		thread = new oxt::thread(boost::bind(&AcceptLoadBalancer<Server>::mainLoop, this),
+		boost::function<void ()> func = boost::bind(&AcceptLoadBalancer<Server>::mainLoop, this);
+		thread = new oxt::thread(boost::bind(runAndPrintExceptions, func, true),
 			"Load balancer");
 	}
 
