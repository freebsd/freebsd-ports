--- firetalk/toc.c.orig	Sun Jul 18 21:10:04 2004
+++ firetalk/toc.c	Fri Aug 26 13:09:16 2005
@@ -1415,28 +1415,28 @@
 	} else if (strcmp(arg0, "PAUSE") == 0) {
 		c->connectstate = 1;
 		firetalk_internal_set_connectstate(c, FCS_WAITING_SIGNON);
-	} else if (strcmp(arg0, "IM_IN") == 0) {
-		args = toc_parse_args(data, 4);
+	} else if (strcmp(arg0, "IM_IN2") == 0) {
+		args = toc_parse_args(data, 5);
 		if ((args[1] == NULL) || (args[2] == NULL) || (args[3] == NULL)) {
 			(void)toc_internal_disconnect(c, FE_INVALIDFORMAT);
 			return FE_INVALIDFORMAT;
 		}
-		(void)aim_handle_ect(c, args[1], args[3], args[2][0] == 'T'?1:0);
-		if (strlen(args[3]) > 0) {
+		(void)aim_handle_ect(c, args[1], args[4], args[2][0] == 'T'?1:0);
+		if (strlen(args[4]) > 0) {
 			char *mestart;
 
-			if (strncasecmp(args[3],"/me ",4) == 0)
-				firetalk_callback_im_getaction(c, args[1], args[2][0] == 'T'?1:0, &args[3][4]);
-			else if ((mestart = strstr(args[3],">/me ")) != NULL)
+			if (strncasecmp(args[4],"/me ",4) == 0)
+				firetalk_callback_im_getaction(c, args[1], args[2][0] == 'T'?1:0, &args[4][4]);
+			else if ((mestart = strstr(args[4],">/me ")) != NULL)
 				firetalk_callback_im_getaction(c, args[1], args[2][0] == 'T'?1:0, &mestart[5]);
 			else {
 				if (args[2][0] == 'T') /* interpolate only auto-messages */
-					firetalk_callback_im_getmessage(c, args[1], 1, aim_interpolate_variables(args[3], c->nickname));
+					firetalk_callback_im_getmessage(c, args[1], 1, aim_interpolate_variables(args[4], c->nickname));
 				else
-					firetalk_callback_im_getmessage(c, args[1], 0, args[3]);
+					firetalk_callback_im_getmessage(c, args[1], 0, args[4]);
 			}
 		}
-	} else if (strcmp(arg0, "UPDATE_BUDDY") == 0) {
+	} else if (strcmp(arg0, "UPDATE_BUDDY2") == 0) {
 		args = toc_parse_args(data,7);
 		if (!args[1] || !args[2] || !args[3] || !args[4] || !args[5] || !args[6]) {
 			(void)toc_internal_disconnect(c, FE_INVALIDFORMAT);
@@ -1609,6 +1609,7 @@
 	char *tempchr2;
 	int permit_mode;
 	firetalk_t fchandle;
+	int magicnum;
 
   got_data_connecting_start:
 	r = toc_find_packet(c,buffer,bufferpos,data,c->connectstate == 0 ? SFLAP_FRAME_SIGNON : SFLAP_FRAME_DATA,&length);
@@ -1641,7 +1642,23 @@
 			firetalk_callback_needpass(c,password,128);
 
 			c->connectstate = 1;
-			r = toc_send_printf(c,"toc_signon login.oscar.aol.com 5190 %s %s english \"" PACKAGE_NAME ":" PACKAGE_VERSION ":contact " PACKAGE_BUGREPORT "\"",c->nickname,toc_hash_password(password));
+
+			magicnum = 0;
+			{
+				/* see www.snaphat.com/toc2.txt */
+				int a, b, cnum, sn, pw;
+
+				sn = c->nickname[0] - 96;
+				pw = (int)(password[0]) - 96;
+
+				a = sn * 7696 + 738816;
+				b = sn * 746512;
+				cnum = pw * a;
+
+				magicnum = cnum - a + b + 71665152;
+			}
+
+			r = toc_send_printf(c,"toc2_signon login.oscar.aol.com 5190 %s %s english \"TIC:naim\" 160 %d",c->nickname,toc_hash_password(password), magicnum);
 			if (r != FE_SUCCESS) {
 				firetalk_callback_connectfailed(c,r,"Error sending login string");
 				return r;
@@ -1701,7 +1718,7 @@
 						abort();
 				}
 				c->connectstate = 3;
-			} else if (strcmp(arg0,"CONFIG") == 0) {
+			} else if (strcmp(arg0,"CONFIG2") == 0) {
 				char	*group;
 
 				group = strdup("Saved buddy");
@@ -1711,7 +1728,7 @@
 				fchandle = firetalk_find_handle(c);
 				args = toc_parse_args(data,2);
 				if (!args[1]) {
-					firetalk_callback_connectfailed(c,FE_INVALIDFORMAT,"CONFIG");
+					firetalk_callback_connectfailed(c,FE_INVALIDFORMAT,"CONFIG2");
 					return FE_INVALIDFORMAT;
 				}
 				tempchr1 = args[1];
