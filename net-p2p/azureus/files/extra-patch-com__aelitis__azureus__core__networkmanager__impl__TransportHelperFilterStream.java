--- com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java.orig	Sat Feb  3 18:34:39 2007
+++ com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterStream.java	Sat Feb  3 18:37:03 2007
@@ -55,7 +55,7 @@
 	public boolean 
 	hasBufferedRead() 
 	{
-		return false;
+		return true;
 	}
 	
 	public TransportHelper
