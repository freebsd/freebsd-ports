--- src/MainWindow.cs.orig	Mon Oct  8 11:55:37 2007
+++ src/MainWindow.cs	Mon Oct  8 11:55:53 2007
@@ -500,7 +500,7 @@
 	        			return;
         		}
         		
-				if (Configuration.Activate(this.SelectedEntry, new ActivateDelegate(RequestPassword)))
+				if (Configuration.Activate(this.SelectedEntry, new ConnectionActivateDelegate(RequestPassword)))
 				{
 					this.activeConnections = this.activeConnections + 1;
 					this.RefreshCurrentEntry();
