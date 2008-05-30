--- com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java.orig	2007-03-01 23:39:40.000000000 -0500
+++ com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java	2008-05-29 13:45:17.000000000 -0400
@@ -57,7 +57,7 @@
 	public boolean 
 	hasBufferedRead() 
 	{
-		return false;
+		return true;
 	}
 	
 	public TransportHelper
