--- modules/yahoo2/libyahoo2/libyahoo2.c.orig	Fri Jan 16 14:39:19 2004
+++ modules/yahoo2/libyahoo2/libyahoo2.c	Sun Feb  8 00:33:04 2004
@@ -813,9 +813,9 @@
 	inputs = y_list_remove(inputs, yid);
 
 	LOG(("yahoo_input_close(read)")); 
-	YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->read_tag);
+	YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->yd->client_id, yid->read_tag);
 	LOG(("yahoo_input_close(write)")); 
-	YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->write_tag);
+	YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->yd->client_id, yid->write_tag);
 	yid->read_tag = yid->write_tag = 0;
 	if(yid->fd)
 		close(yid->fd);
@@ -1768,9 +1768,10 @@
 
 		/* Bad.  Abort.
 		 */
-		if ((magic_cnt + 1 > magic_len) || 
-				(magic_cnt > magic_len))
+		if (magic_cnt >= magic_len) {
+			WARNING(("magic_cnt(%d)  magic_len(%d)", magic_cnt, magic_len))
 			break;
+		}
 
 		byte1 = magic[magic_cnt];
 		byte2 = magic[magic_cnt+1];
@@ -2972,7 +2973,7 @@
 			y_list_free_1(l);
 		}
 		LOG(("yahoo_write_ready(%d, %d) len < 0", id, fd));
-		YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->write_tag);
+		YAHOO_CALLBACK(ext_yahoo_remove_handler)(id, yid->write_tag);
 		yid->write_tag = 0;
 		errno=e;
 		return 0;
@@ -2996,7 +2997,7 @@
 		*/
 		if(!yid->txqueues) {
 			LOG(("yahoo_write_ready(%d, %d) !yxqueues", id, fd));
-			YAHOO_CALLBACK(ext_yahoo_remove_handler)(yid->write_tag);
+			YAHOO_CALLBACK(ext_yahoo_remove_handler)(id, yid->write_tag);
 			yid->write_tag = 0;
 		}
 	}
