--- src/interface.c.orig	2014-01-05 00:36:58.000000000 +0400
+++ src/interface.c	2014-01-05 00:45:10.000000000 +0400
@@ -212,20 +212,19 @@ static int interface_read (void)
 		return (-1);
 
 	for (if_ptr = if_list; if_ptr != NULL; if_ptr = if_ptr->ifa_next)
-	{
-		if ((if_data = (struct IFA_DATA *) if_ptr->ifa_data) == NULL)
-			continue;
-
-		if_submit (if_ptr->ifa_name, "if_octets",
-				if_data->IFA_RX_BYTES,
-				if_data->IFA_TX_BYTES);
-		if_submit (if_ptr->ifa_name, "if_packets",
-				if_data->IFA_RX_PACKT,
-				if_data->IFA_TX_PACKT);
-		if_submit (if_ptr->ifa_name, "if_errors",
-				if_data->IFA_RX_ERROR,
-				if_data->IFA_TX_ERROR);
-	}
+        if (if_ptr->ifa_addr != NULL && if_ptr->ifa_addr->sa_family == AF_LINK) {
+            if_data = (struct IFA_DATA *) if_ptr->ifa_data;
+            
+            if_submit (if_ptr->ifa_name, "if_octets",
+                       if_data->IFA_RX_BYTES,
+                       if_data->IFA_TX_BYTES);
+            if_submit (if_ptr->ifa_name, "if_packets",
+                       if_data->IFA_RX_PACKT,
+                       if_data->IFA_TX_PACKT);
+            if_submit (if_ptr->ifa_name, "if_errors",
+                       if_data->IFA_RX_ERROR,
+                       if_data->IFA_TX_ERROR);
+        }
 
 	freeifaddrs (if_list);
 /* #endif HAVE_GETIFADDRS */
