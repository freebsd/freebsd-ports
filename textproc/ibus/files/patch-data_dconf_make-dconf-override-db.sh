--- data/dconf/make-dconf-override-db.sh.orig	2019-08-07 03:33:23 UTC
+++ data/dconf/make-dconf-override-db.sh
@@ -6,7 +6,7 @@ set -e
 # breaks dbus-launch.  There's dbus-run-session which is
 # better, but not everyone has it yet.
 export DBUS_FATAL_WARNINGS=0
-export TMPDIR=$(mktemp -d --tmpdir="$PWD")
+export TMPDIR=$(TMPDIR="${PWD}" mktemp -d)
 export XDG_CONFIG_HOME="$TMPDIR/config"
 export XDG_CACHE_HOME="$TMPDIR/cache"
 export GSETTINGS_SCHEMA_DIR="$TMPDIR/schemas"
