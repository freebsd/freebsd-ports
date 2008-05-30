--- com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterTransparent.java.orig	2008-05-29 14:05:20.000000000 -0400
+++ com/aelitis/azureus/core/networkmanager/impl/TransportHelperFilterTransparent.java	2008-05-29 14:08:25.000000000 -0400
@@ -60,7 +60,7 @@
 	public boolean 
 	hasBufferedRead() 
 	{
-		return( read_insert != null && read_insert.remaining() > 0 );
+		return( true );
 	}
 	
 	public long 
