--- if.c.orig	1998-10-12 06:13:16.000000000 +0400
+++ if.c	2014-10-02 21:48:19.000000000 +0400
@@ -11,32 +11,28 @@
 #include <string.h>
 #include <unistd.h>
 #include <limits.h>
+#include <errno.h>
 #include <err.h>
 #include <sys/param.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
 #include <sys/socket.h>
 #include <net/if.h>
-#if (__FreeBSD_version >= 300003)
-#include <net/if_var.h>
 #include <net/if_types.h>
-#endif
 #include <fcntl.h>
-#include <kvm.h>
-#include <nlist.h>
 #include <assert.h>
+#include <ifaddrs.h>
 #include "wmnet.h"
 
 #define	IF_STEP	10
+#define	IFA_STAT(s)	(((struct if_data *)ifa->ifa_data)->ifi_ ## s)
 
 /*
 	Local data types...
 */
 typedef struct {
-	unsigned long ifNetAddr;
-
+	char name[IFNAMSIZ];
 	unsigned long flags;
-
 	unsigned current;
 	unsigned long xmt[G_WIDTH], xmtLast;
 	unsigned long rcv[G_WIDTH], rcvLast;
@@ -45,19 +41,15 @@
 /*
 	Local prototypes...
 */
-static int addIfData(unsigned long);
-static struct ifnet const* dereference(unsigned long);
-static void ifTerm(void);
+static int addIfData(struct ifaddrs *);
 
 /*
 	Local data...
 */
-static kvm_t* kd = 0;
-static unsigned long root = 0;
-
 static int total = 0;
 static int size = 0;
 static IfData* ifData = 0;
+static int sock;
 
 /*------------------------------------------------------------------------------
 	addIfData
@@ -66,134 +58,57 @@
 	out of space, more space is allocated. If the interface already
 	exists in the list, we don't do anything.
 ------------------------------------------------------------------------------*/
-static int addIfData(unsigned long theAddr)
+static int addIfData(struct ifaddrs *ifa)
 {
-	struct ifnet const* const theData = dereference(theAddr);
+	IfData* ptr = 0;
+	int ii;
 
 	assert(total <= size);
 
-	/* Now read in the data so we can get to some of its goodies. */
-
-	if (0 != theData) {
-		IfData* ptr = 0;
-		int ii;
-
-		/* First check to see if we have enough space in the list. If
-		   we don't, we'll have to add more space. */
-
-		if (total == size) {
-			IfData* const newData =
-				(IfData*) realloc(ifData,
-								  (size += IF_STEP) * sizeof(IfData));
-
-			if (!newData) {
-				size -= IF_STEP;
-				fprintf(stderr, "wmnet: Warning -- low memory; "
-						"ignoring %s interface\n", theData->if_name);
-				return 0;
-			}
-
-			/* Good. we got more space. */
-
-			ifData = newData;
+	/* First check to see if we have enough space in the list. If
+	   we don't, we'll have to add more space. */
+	if (total == size) {
+		IfData *newData;
+
+		newData = realloc(ifData, (size += IF_STEP) * sizeof(IfData));
+
+		if (!newData) {
+			size -= IF_STEP;
+			fprintf(stderr, "wmnet: Warning -- low memory; "
+			    "ignoring %s interface\n", ifa->ifa_name);
+			return ENOMEM;
 		}
 
-		assert(0 != ifData);
-		assert(total < size);
-
-		/* If we reached here, then 'total' points to the next
-		   bucket. Initialize the new bucket. XXX: This would be a
-		   good spot to insert-sort the new record. As it stands, the
-		   list builds up by the order that the interfaces were
-		   bootstrapped. */
-
-		ptr = ifData + total;
-
-		ptr->ifNetAddr = theAddr;
-		for (ii = 0; ii < G_WIDTH; ++ii)
-			ptr->rcv[ii] = ptr->xmt[ii] = 0;
-		ptr->rcvLast = theData->if_ibytes;
-		ptr->xmtLast = theData->if_obytes;
-		ptr->current = 0;
-		ptr->flags = 0;
-
-#ifndef NDEBUG
-		printf("Added '%.*s%d' to list.\n", IFNAMSIZ, theData->if_name,
-			   theData->if_unit);
-#endif
-
-		// Bump the total.
-
-		++total;
-	} else
-		fprintf(stderr, "Couldn't read interface information\n");
-	return 1;
-}
-
-/*------------------------------------------------------------------------------
-	dereference
-
-	Takes the kernel memory "pointer" and copies its pointed-to data
-	into a local buffer. The only type of "pointer" we're using is a
-	struct ifnet*, so this function only returns this type of data.
-
-	Passing in 0 will reset the address cache and force the function
-	to reload the data.
-------------------------------------------------------------------------------*/
-static struct ifnet const* dereference(unsigned long a)
-{
-	static unsigned long c = 0;
-	static struct ifnet d;
-	static char name[IFNAMSIZ];
-
-	/* If we are passed a NULL, the caller wants us to stop caching
-	   the current interface. */
-
-	if (!a) {
-		c = 0;
-		return 0;
+		/* Good. we got more space. */
+		ifData = newData;
 	}
 
-	/* If the requested address is the same that has been cached, just
-	   return the data. */
+	assert(0 != ifData);
+	assert(total < size);
 
-	else if (a == c)
-		return &d;
-	else if (sizeof(d) == kvm_read(kd, a, &d, sizeof(d))) {
-
-		/* We've read the structure's data, but the 'name' field still
-		   points to kernel memory. We transfer the name to a local
-		   buffer, and then modify the pointer to point to our
-		   buffer. */
-
-		ssize_t const n =  kvm_read(kd, (unsigned long) d.if_name, name,
-									sizeof(name));
-
-		if (sizeof(name) == n) {
-			name[IFNAMSIZ - 1] = '\0';
-			d.if_name = name;
-#ifndef NDEBUG
+	/* If we reached here, then 'total' points to the next
+	   bucket. Initialize the new bucket. XXX: This would be a
+	   good spot to insert-sort the new record. As it stands, the
+	   list builds up by the order that the interfaces were
+	   bootstrapped. */
+
+	ptr = ifData + total;
+
+	strncpy(ptr->name, ifa->ifa_name, IFNAMSIZ);
+	for (ii = 0; ii < G_WIDTH; ++ii)
+		ptr->rcv[ii] = ptr->xmt[ii] = 0;
+	ptr->rcvLast = IFA_STAT(ibytes);
+	ptr->xmtLast = IFA_STAT(obytes);
+	ptr->current = 0;
+	ptr->flags = 0;
 
-			/* These are other pointer fields that we shouldn't need
-			   to look at. While debugging, set these to NULL to trap
-			   any attempts. */
-
-			d.if_softc = 0;
-#if (__FreeBSD_version >= 300003)
-			d.if_addrhead.tqh_first = 0;
-#else
-			d.if_addrlist = 0;
-#endif
-			d.if_bpf = 0;
-			d.if_linkmib = 0;
-			d.if_poll_slowq = 0;
+#ifndef NDEBUG
+	printf("Added '%.*s' to list.\n", IFNAMSIZ, ifa->ifa_name);
 #endif
-			c = a;
-			return &d;
-		} else
-			return 0;
-	} else
-		return 0;
+	// Bump the total.
+	++total;
+
+	return 0;
 }
 
 /*------------------------------------------------------------------------------
@@ -222,56 +137,30 @@
 ------------------------------------------------------------------------------*/
 int ifInit(void)
 {
-	char errBuf[_POSIX2_LINE_MAX];
+	struct ifaddrs *ifap, *ifa;
 
-	/* First try to open the kernel image. If we can't, the rest of
-	   the program is essentially useless. */
+	sock = socket(AF_INET, SOCK_DGRAM, 0);
+	if (sock < 0)
+		fprintf(stderr, "socket(): %d\n", errno);
+
+	if (getifaddrs(&ifap) != 0) {
+		fprintf(stderr, "getifaddrs(): %d\n", errno);
+		return (errno);
+	}
 
-	if (0 != (kd = kvm_openfiles(0, 0, 0, O_RDONLY, errBuf))) {
-		static struct nlist nl[] = {
-			{ "_ifnet" },
-			{ "" }
-		};
-
-		/* Try to pull the address for the global kernel variable,
-		   ifnet. This variable is the root of the singly-linked list
-		   of network interfaces. */
-
-		if (0 == kvm_nlist(kd, nl)) {
-			ssize_t const n = kvm_read(kd, nl[0].n_value, &root, sizeof(root));
-
-			/* We'll go ahead and make one dereference. We never
-			   really want this variable. We want what it points to. */
-
-			if (sizeof(root) == n) {
-				unsigned long current = root;
-
-				while (current) {
-					addIfData(current);
-#if (__FreeBSD_version >= 300003)
-					current = (unsigned long) dereference(current)->if_link.tqe_next;
-#else
-					current = (unsigned long) dereference(current)->if_next;
-#endif
-				}
+	for (ifa = ifap; ifa; ifa = ifa->ifa_next) {
+		int error;
 
-				/* Try to register our termination function. If it
-				   returns an error, we essentially ignore it because
-				   the OS will clean up our resources. */
-
-				(void) atexit(ifTerm);
-				return 1;
-			}
+		if (ifa->ifa_addr->sa_family != AF_LINK)
+			continue;
+		if ((error = addIfData(ifa)) != 0) {
+			freeifaddrs(ifap);
+			return (error);
 		}
+	}
 
-		/* If we can't get a symbol list, close the kernel image and
-		   return an error. */
-
-		kvm_close(kd);
-		kd = 0;
-	} else
-		fprintf(stderr, "kvm_open: %s\n", errBuf);
-	return 0;
+	freeifaddrs(ifap);
+	return (0);
 }
 
 /*------------------------------------------------------------------------------
@@ -303,17 +192,7 @@
 ------------------------------------------------------------------------------*/
 char const* ifName(unsigned idx)
 {
-	if (idx < total) {
-		struct ifnet const* const ptr = dereference(ifData[idx].ifNetAddr);
-
-		if (ptr) {
-			static char buffer[IFNAMSIZ + 1];
-
-			sprintf(buffer, "%.*s%d", IFNAMSIZ - 1, ptr->if_name, ptr->if_unit);
-			return buffer;
-		}
-	}
-	return 0;
+	return ifData[idx].name;
 }
 
 /*------------------------------------------------------------------------------
@@ -324,68 +203,53 @@
 ------------------------------------------------------------------------------*/
 int ifSample(void)
 {
+	struct ifaddrs *ifap;
 	int ii;
 
-	/* Flush the kernel memory cache so that we're guaranteed to get
-	   new data during the next dereference(). */
-
-	dereference(0);
+	if (getifaddrs(&ifap) != 0) {
+		fprintf(stderr, "getifaddrs(): %d\n", errno);
+		return (errno);
+	}
 
 	/* Loop through all the network interfaces. Even though we display
 	   one interface's statistics, we keep track of all of them. */
-
 	for (ii = 0; ii < total; ++ii) {
-		IfData* const d = ifData + ii;
-		struct ifnet const* const ptr = dereference(d->ifNetAddr);
-
-		if (!ptr) {
-			fprintf(stderr, "couldn't sample interface.\n");
-			return 0;
-		}
-
-		d->flags = ptr->if_flags;
+		struct ifreq ifr;
+		struct ifaddrs *ifa;
+		IfData *d;
+
+		d = ifData + ii;
+
+		for (ifa = ifap; ifa; ifa = ifa->ifa_next)
+			if (ifa->ifa_addr->sa_family == AF_LINK &&
+			    strcmp(ifa->ifa_name, d->name) == 0)
+				break;
+
+		if (ifa == NULL)
+			/* Interface disappeared? */
+			continue;
 
 		/* Save the new delta for the transmit channel. */
-
-		d->xmt[d->current] = ptr->if_obytes - d->xmtLast;
-		d->xmtLast = ptr->if_obytes;
+		d->xmt[d->current] = IFA_STAT(obytes) - d->xmtLast;
+		d->xmtLast = IFA_STAT(obytes);
 
 		/* Save the new delta for the receive channel. */
-
-		d->rcv[d->current] = ptr->if_ibytes - d->rcvLast;
-		d->rcvLast = ptr->if_ibytes;
+		d->rcv[d->current] = IFA_STAT(ibytes) - d->rcvLast;
+		d->rcvLast = IFA_STAT(ibytes);
 
 		/* Prep the index for the next location to be written. */
-
 		d->current = (d->current + 1) % G_WIDTH;
-	}
-	return 1;
-}
-
-/*------------------------------------------------------------------------------
-	ifTerm
 
-	This function will be called once when the application is ready to exit
-------------------------------------------------------------------------------*/
-static void ifTerm(void)
-{
-#ifndef NDEBUG
-	printf("Cleaning up resources.\n");
-#endif
-
-	/* If the kernel image is open, close it. */
-
-	if (0 != kd) {
-		kvm_close(kd);
-		kd = 0;
+		memset(&ifr, 0, sizeof(ifr));
+		strncpy(ifr.ifr_name, ifa->ifa_name, sizeof(ifr.ifr_name));
+		if (ioctl(sock, SIOCGIFFLAGS, (caddr_t)&ifr) < 0)
+			continue;
+		d->flags = (ifr.ifr_flags & 0xffff) | (ifr.ifr_flagshigh << 16);
 	}
 
-	/* Now free up any memory we're using. */
+	freeifaddrs(ifap);
 
-	if (ifData) {
-		free(ifData);
-		ifData = 0;
-	}
+	return (0);
 }
 
 /*------------------------------------------------------------------------------
