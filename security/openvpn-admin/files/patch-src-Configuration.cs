--- src/Configuration.cs.orig	Mon Oct  8 11:57:02 2007
+++ src/Configuration.cs	Mon Oct  8 11:57:30 2007
@@ -33,7 +33,7 @@
 
 namespace OpenVPN.Admin
 {
-	public delegate void ActivateDelegate(System.IO.StreamWriter input, bool askname);
+	public delegate void ConnectionActivateDelegate(System.IO.StreamWriter input, bool askname);
 	
 	public class Configuration
 	{
@@ -409,7 +409,7 @@
 				throw new Exception(Catalog.GetString("Invalid passphrase"));
 		}
 
-		public static bool Activate(string entry, ActivateDelegate input)
+		public static bool Activate(string entry, ConnectionActivateDelegate input)
 		{
 			string contents;
 			string filename = Configuration.FileFromEntry(entry);
