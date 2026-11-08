-- Allow overriding the BINDIR directory via the environment.
-- This is needed because FreeBSD ports builds the binaries out-of-source
-- in ${BUILD_WRKSRC}/bin rather than ${WRKSRC}/bin, where the test script
-- expects them by default.

--- test/runtests.sh.orig	2023-08-16 17:12:53 UTC
+++ test/runtests.sh
@@ -1,7 +1,7 @@ readonly SCRIPTDIR=$(dirname "$(readlink -f $0)")
 #!/bin/sh
 
 readonly SCRIPTDIR=$(dirname "$(readlink -f $0)")
-readonly BINDIR=$SCRIPTDIR/../bin
+readonly BINDIR=${BINDIR:-$SCRIPTDIR/../bin}
 
 readonly GREEN='\033[0;32m'
 readonly RED='\033[0;31m'
