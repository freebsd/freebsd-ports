--- driver.c	2003-10-16 00:52:31 +0530
+++ driver.c	2003-10-17 11:24:27 +0530
@@ -429,8 +429,11 @@
 	/* for POP3, we can get the size of one mail only! Unfortunately, this
 	 * protocol specific test cannot be done elsewhere as the protocol
 	 * could be "auto". */
-	if (ctl->server.protocol == P_POP3)
+	switch (ctl->server.protocol)
+	{
+	    case P_POP3: case P_APOP: case P_RPOP:
 	    fetchsizelimit = 1;
+	}
 
 	/* Time to allocate memory to store the sizes */
 	xalloca(msgsizes, int *, sizeof(int) * fetchsizelimit);
