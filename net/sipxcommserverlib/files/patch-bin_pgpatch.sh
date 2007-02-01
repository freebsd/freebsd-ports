--- bin/pgpatch.sh.orig	Wed Jan  3 14:07:38 2007
+++ bin/pgpatch.sh	Mon Jan  8 16:11:32 2007
@@ -8,7 +8,7 @@
 
 Action=RUN
 
-: ${ServiceDir:=/etc/init.d}
+: ${ServiceDir:=@PREFIX@/etc/rc.d}
 : ${Chown:=chown}
 
 # This function determines the correct service name for Postgres.
@@ -37,19 +37,12 @@
   Service=`postgresService`
 
   # May not by running, so eat up error (ENG-314)
-  ${ServiceDir}/${Service} stop 2>&1 1> /dev/null
+  ${ServiceDir}/postgresql stop 2>&1 1> /dev/null
 
   # Custom
   if test -z $PGDATA
   then
-      # Debian/Gentoo
-      if test -d /var/lib/postgresql/data
-      then
-          PGDATA=/var/lib/postgresql/data
-      else
-          # Redhat
-          PGDATA=/var/lib/pgsql/data
-      fi
+      PGDATA=~pgsql/data
   fi
 
   # Postgres db is initialized on startup on Redhat, but not on other
@@ -84,16 +77,16 @@
   fi
 
   # Open up TCP/IP connections
-  sed -i-sipx.bak -e 's/\#tcpip_socket\s=\sfalse/tcpip_socket = true/g' \
+  gsed -i-sipx.bak -e 's/\#tcpip_socket\s=\sfalse/tcpip_socket = true/g' \
           $PGDATA/postgresql.conf
-  ${Chown} postgres:postgres $PGDATA/postgresql.conf
+  ${Chown} pgsql:pgsql $PGDATA/postgresql.conf
 
   # Postmaster to allow connections
   echo "-i" > $PGDATA/postmaster.opts.default
   chmod 664 $PGDATA/postmaster.opts.default
-  ${Chown} postgres:postgres $PGDATA/postmaster.opts.default
+  ${Chown} pgsql:pgsql $PGDATA/postmaster.opts.default
 
-  ${ServiceDir}/$Service start
+  ${ServiceDir}/postgresql start
 }
 
 # Have postgres start automatically with system reboot
@@ -129,7 +122,6 @@
 if [ ${Action} = RUN ]
 then
   postgresSetup
-  setPostgresRunlevels
 elif [ ${Action} = HELP ]
 then
 cat <<USAGE
