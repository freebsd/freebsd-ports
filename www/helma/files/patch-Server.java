--- ../src/helma/main/Server.java.orig	2008-04-07 14:45:30.000000000 +0200
+++ ../src/helma/main/Server.java	2008-07-13 21:36:06.000000000 +0200
@@ -444,14 +444,21 @@
 
 
         // read db.properties file in helma home directory
+	String dbPropfile = sysProps.getProperty("dbPropFile");
+	File file;
+	if ((dbPropfile != null) && !"".equals(dbPropfile.trim())) {
+	    file = new File(dbPropfile);
+	} else {
+	    file = new File(hopHome, "db.properties");
+	}
+
         dbProps = new ResourceProperties();
         dbProps.setIgnoreCase(false);
-        dbProps.addResource(new FileResource(new File(hopHome, "db.properties")));
+        dbProps.addResource(new FileResource(file));
         DbSource.setDefaultProps(dbProps);
 
         // read apps.properties file
         String appsPropfile = sysProps.getProperty("appsPropFile");
-        File file;
         if ((appsPropfile != null) && !"".equals(appsPropfile.trim())) {
             file = new File(appsPropfile);
         } else {
