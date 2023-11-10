--- doc/General/Updating.md.orig	2023-10-27 13:55:36 UTC
+++ doc/General/Updating.md
@@ -22,7 +22,7 @@ you can do so by running the following commands:
 cd /opt/librenms
 git pull
 ./scripts/composer_wrapper.php install --no-dev
-./lnms migrate
+sudo lnms migrate
 ./validate.php
 ```
 
