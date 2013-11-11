--- salt/client/ssh/__init__.py.orig	2013-10-17 19:28:12.000000000 +0200
+++ salt/client/ssh/__init__.py	2013-11-07 23:22:40.228990613 +0100
@@ -80,7 +80,7 @@
          fi
          if [ -f /tmp/.salt/salt-thin.tgz ]
          then
-             [ $({{2}}sum /tmp/.salt/salt-thin.tgz | cut -f1 -d' ') = {{3}} ] && {{0}} tar xzvf /tmp/.salt/salt-thin.tgz -C /tmp/.salt
+             [ $({{2}} -q /tmp/.salt/salt-thin.tgz) = {{3}} ] && {{0}} tar xzvf /tmp/.salt/salt-thin.tgz -C /tmp/.salt
          else
              install -m 0700 -d /tmp/.salt
              echo "{1}"
