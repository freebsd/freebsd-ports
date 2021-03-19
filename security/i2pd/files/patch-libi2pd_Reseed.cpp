Static files belong to datadir, not vardir.

--- libi2pd/Reseed.cpp.orig	2021-02-15 13:21:30 UTC
+++ libi2pd/Reseed.cpp
@@ -497,7 +497,7 @@ namespace data
 
 	void Reseeder::LoadCertificates ()
 	{
-		std::string certDir = i2p::fs::DataDirPath("certificates", "reseed");
+		std::string certDir = "%%DATADIR%%/certificates/reseed";
 		std::vector<std::string> files;
 		int numCertificates = 0;
 
