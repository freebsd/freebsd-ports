--- src/net/psammead/commonist/Main.java.orig	2007-11-28 16:35:58.000000000 +0100
+++ src/net/psammead/commonist/Main.java	2008-06-20 00:35:52.532632590 +0200
@@ -58,14 +58,14 @@
 	private ChangeDirectoryTask changeDirectoryTask;
 	private UploadFilesTask 	uploadFilesTask;
 	
-	public Main(Image programIcon, String programHeading) {
+	public Main(Image programIcon, String programHeading) throws ConfigException {
 		settingsDir	= new File(new File(System.getProperty("user.home")), ".commonist");
 		settingsDir.mkdirs();
 		
 		// HACK: running from webstart or load from the Filesystem
 //		boolean fromWebStart	= !(new File("etc/licenses.txt").exists());
 		
-		File	projectDir	= new File(new File(System.getProperty("user.dir")), "etc");
+		File	projectDir	= new File("%%ETCDIR%%");
 		
 		loader	= new Loader(settingsDir, projectDir, "/etc/");
 
