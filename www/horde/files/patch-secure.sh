--- secure.sh.orig	Sun May 28 05:09:52 2000
+++ secure.sh	Sun Jul  7 11:37:19 2002
@@ -1,17 +1,17 @@
 #!/bin/sh
 
 # Horde Items
-chmod 444 config/horde.php3         > /dev/null 2> /dev/null
-chmod 444 lib/horde.lib                > /dev/null 2> /dev/null
-chmod 444 lib/mime.lib                 > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/config/horde.php3            > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/lib/horde.lib                > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/lib/mime.lib                 > /dev/null 2> /dev/null
 
 # IMP Items
-chmod 444 imp/config/defaults.php3     > /dev/null 2> /dev/null
-chmod 444 imp/lib/imp.lib              > /dev/null 2> /dev/null
-chmod 444 imp/lib/mimetypes.lib        > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/imp/config/defaults.php3     > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/imp/lib/imp.lib              > /dev/null 2> /dev/null
+chmod 444 %%HORDEDIR%%/imp/lib/mimetypes.lib        > /dev/null 2> /dev/null
 
-chmod 000 setup.php3                   > /dev/null 2> /dev/null
-chmod 000 test.php3                    > /dev/null 2> /dev/null
+chmod 000 %%HORDEDIR%%/setup.php3                   > /dev/null 2> /dev/null
+chmod 000 %%HORDEDIR%%/test.php3                    > /dev/null 2> /dev/null
 
 echo 
 echo I have made your configuration files, and libraries mode 0444
