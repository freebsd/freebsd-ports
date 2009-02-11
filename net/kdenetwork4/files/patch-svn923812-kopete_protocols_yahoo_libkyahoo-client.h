--- ../kopete/protocols/yahoo/libkyahoo/client.h	2009/02/06 02:57:20	921978
+++ ../kopete/protocols/yahoo/libkyahoo/client.h	2009/02/09 14:00:12	923817
@@ -705,6 +705,12 @@
 		 * Send a Yahoo Ping packet to the server
 		 */
 		void sendPing();
+
+		/**
+		 * Send all queued buddy icon requests
+		 */
+		void processPictureQueue();
+
 	private:
 		void distribute( Transfer *transfer );
 		
