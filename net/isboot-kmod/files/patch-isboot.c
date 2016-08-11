--- isboot.c.orig	2015-11-05 16:50:51 UTC
+++ isboot.c
@@ -347,9 +347,9 @@ isboot_set_v4gw(struct sockaddr_in *gate
 	netmask.sin_addr.s_addr = htonl(0);
 
 	/* delete gateway if exists */
-	error = rtrequest(RTM_DELETE, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_DELETE, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    0, NULL);
+	    0, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		if (error != ESRCH) {
 			printf("rtrequest RTM_DELETE error %d\n",
@@ -359,9 +359,9 @@ isboot_set_v4gw(struct sockaddr_in *gate
 	}
 
 	/* set new default gateway */
-	error = rtrequest(RTM_ADD, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_ADD, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    RTF_GATEWAY | RTF_STATIC, NULL);
+	    RTF_GATEWAY | RTF_STATIC, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		printf("rtrequest RTM_ADD error %d\n", error);
 		return (error);
@@ -391,9 +391,9 @@ isboot_set_v6gw(struct sockaddr_in6 *gat
 	memset(&netmask.sin6_addr, 0, 16);
 
 	/* delete gateway if exists */
-	error = rtrequest(RTM_DELETE, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_DELETE, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    0, NULL);
+	    0, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		if (error != ESRCH) {
 			printf("rtrequest RTM_DELETE error %d\n",
@@ -403,9 +403,9 @@ isboot_set_v6gw(struct sockaddr_in6 *gat
 	}
 
 	/* set new default gateway */
-	error = rtrequest(RTM_ADD, (struct sockaddr *)&dst,
+	error = rtrequest_fib(RTM_ADD, (struct sockaddr *)&dst,
 	    (struct sockaddr *)gateway, (struct sockaddr *)&netmask,
-	    RTF_GATEWAY | RTF_STATIC, NULL);
+	    RTF_GATEWAY | RTF_STATIC, NULL, RT_DEFAULT_FIB);
 	if (error) {
 		printf("rtrequest RTM_ADD error %d\n", error);
 		return (error);
