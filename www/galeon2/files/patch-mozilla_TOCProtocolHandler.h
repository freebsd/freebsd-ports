--- mozilla/TOCProtocolHandler.h.orig	Wed Nov 20 15:25:05 2002
+++ mozilla/TOCProtocolHandler.h	Wed Nov 20 15:25:10 2002
@@ -55,7 +55,7 @@
   	NS_METHOD CreateInfoPage (void);
   	NS_METHOD CreateManPage (void);
   	NS_METHOD CreateHelpPage (const char *type,
-  				  int (*select)(const struct dirent *));
+  				  int (*select)(struct dirent *));
   	nsCOMPtr<nsIURI> mURI;
 	nsCOMPtr<nsIChannel> mChannel;
 	nsCOMPtr<nsIStorageStream> mStream;
