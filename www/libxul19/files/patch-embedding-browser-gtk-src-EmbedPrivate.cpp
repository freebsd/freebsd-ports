--- embedding/browser/gtk/src/EmbedPrivate.cpp.orig	2012-03-06 15:45:28.000000000 +0100
+++ embedding/browser/gtk/src/EmbedPrivate.cpp	2012-10-28 12:09:45.000000000 +0100
@@ -104,6 +104,7 @@ nsIDirectoryServiceProvider *EmbedPrivat
 class GTKEmbedDirectoryProvider : public nsIDirectoryServiceProvider2
 {
 public:
+  GTKEmbedDirectoryProvider() {}
   NS_DECL_ISUPPORTS_INHERITED
   NS_DECL_NSIDIRECTORYSERVICEPROVIDER
   NS_DECL_NSIDIRECTORYSERVICEPROVIDER2
