--- if.c.orig	Sun Oct 11 19:13:16 1998
+++ if.c	Fri May 21 01:11:19 2004
@@ -88,8 +88,13 @@
 
 			if (!newData) {
 				size -= IF_STEP;
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 				fprintf(stderr, "wmnet: Warning -- low memory; "
 						"ignoring %s interface\n", theData->if_name);
+#else
+				fprintf(stderr, "wmnet: Warning -- low memory; "
+						"ignoring %s interface\n", theData->if_xname);
+#endif
 				return 0;
 			}
 
@@ -118,10 +123,13 @@
 		ptr->flags = 0;
 
 #ifndef NDEBUG
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 		printf("Added '%.*s%d' to list.\n", IFNAMSIZ, theData->if_name,
 			   theData->if_unit);
+#else
+		printf("Added '%.*s' to list.\n", IFNAMSIZ, theData->if_xname);
+#endif
 #endif
-
 		// Bump the total.
 
 		++total;
@@ -144,7 +152,9 @@
 {
 	static unsigned long c = 0;
 	static struct ifnet d;
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 	static char name[IFNAMSIZ];
+#endif
 
 	/* If we are passed a NULL, the caller wants us to stop caching
 	   the current interface. */
@@ -161,6 +171,7 @@
 		return &d;
 	else if (sizeof(d) == kvm_read(kd, a, &d, sizeof(d))) {
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 		/* We've read the structure's data, but the 'name' field still
 		   points to kernel memory. We transfer the name to a local
 		   buffer, and then modify the pointer to point to our
@@ -172,6 +183,7 @@
 		if (sizeof(name) == n) {
 			name[IFNAMSIZ - 1] = '\0';
 			d.if_name = name;
+#endif
 #ifndef NDEBUG
 
 			/* These are other pointer fields that we shouldn't need
@@ -186,12 +198,13 @@
 #endif
 			d.if_bpf = 0;
 			d.if_linkmib = 0;
-			d.if_poll_slowq = 0;
 #endif
 			c = a;
 			return &d;
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 		} else
 			return 0;
+#endif
 	} else
 		return 0;
 }
@@ -306,12 +319,16 @@
 	if (idx < total) {
 		struct ifnet const* const ptr = dereference(ifData[idx].ifNetAddr);
 
+#if defined(__FreeBSD__) && __FreeBSD_version < 501113
 		if (ptr) {
 			static char buffer[IFNAMSIZ + 1];
 
 			sprintf(buffer, "%.*s%d", IFNAMSIZ - 1, ptr->if_name, ptr->if_unit);
 			return buffer;
 		}
+#else
+		return ptr->if_xname;
+#endif
 	}
 	return 0;
 }
