--- src/java/org/agnitas/emm/extension/listener/ExtensionSystemInitializationContextListener.java.orig	2015-10-11 16:41:55 UTC
+++ src/java/org/agnitas/emm/extension/listener/ExtensionSystemInitializationContextListener.java
@@ -53,7 +53,8 @@ public class ExtensionSystemInitializati
 	
 	protected void setBuilderProperties( ExtensionSystemBuilder extensionSystemBuilder, ServletContext servletContext, WebApplicationContext springContext) throws Exception {
 		// Directories
-		extensionSystemBuilder.setJspBaseDirectory( servletContext.getRealPath( "plugins"));
+		logger.info("builder properties: servletcontext.realpath: <" + servletContext.getRealPath( "plugins") + "> corrected to <" + servletContext.getRealPath( "/plugins") + ">");
+		extensionSystemBuilder.setJspBaseDirectory( servletContext.getRealPath( "/plugins"));
 		extensionSystemBuilder.setPluginBaseDirectory( AgnUtils.getDefaultValue( "plugins.home"));
 		extensionSystemBuilder.setSystemPluginBaseDirectory( servletContext.getRealPath( "/WEB-INF/system-plugins"));
 		
