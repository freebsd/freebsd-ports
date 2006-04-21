
$FreeBSD$

--- modules/mysql/my_con.c
+++ modules/mysql/my_con.c
@@ -70,6 +70,9 @@
 		goto err;
 	}
 
+	/* Enable reconnection explictly */
+	ptr->con->reconnect = 1;
+
 	ptr->timestamp = time(0);
 
 	ptr->id = id;
