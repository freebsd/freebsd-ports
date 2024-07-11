--- pkgconfig.py.orig	2024-03-04 22:10:19 UTC
+++ pkgconfig.py
@@ -117,7 +117,7 @@ if __name__ == "__main__":
 	# Fix search path
 	PKG_CONFIG_PATH = os.getenv("PKG_CONFIG_PATH", "").strip()
 	if not PKG_CONFIG_PATH:
-		PKG_CONFIG_PATH="/usr/local/lib/pkgconfig:/usr/lib/pkgconfig"
+		PKG_CONFIG_PATH="%%LOCALBASE%%/libdata/pkgconfig"
 	PKG_CONFIG_PATH = PKG_CONFIG_PATH.replace(";", ":")
 
 	# Parse files
