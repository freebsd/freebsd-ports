--- Source/JavaScriptCore/offlineasm/config.rb.orig	2021-05-17 13:22:35 UTC
+++ Source/JavaScriptCore/offlineasm/config.rb
@@ -22,11 +22,11 @@ buildProductsDirectory = ENV['BUILT_PRODUCTS_DIR'];
 # THE POSSIBILITY OF SUCH DAMAGE.
 
 buildProductsDirectory = ENV['BUILT_PRODUCTS_DIR'];
-if buildProductsDirectory and File.exists?(buildProductsDirectory)
+if buildProductsDirectory and File.exist?(buildProductsDirectory)
     $: << "#{buildProductsDirectory}/usr/local/include/WebKitAdditions/Scripts"
 end
 sdkRootDirectory = ENV['SDKROOT'];
-if sdkRootDirectory and File.exists?(sdkRootDirectory)
+if sdkRootDirectory and File.exist?(sdkRootDirectory)
     $: << "#{sdkRootDirectory}/usr/local/include/WebKitAdditions/Scripts"
 end
 
