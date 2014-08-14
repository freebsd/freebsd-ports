--- build.sh.orig	2014-08-12 22:35:37.000000000 +0000
+++ build.sh	2014-08-14 15:44:43.884147180 +0000
@@ -5,11 +5,9 @@
 
 distFiles=(README.md LICENSE CONTRIBUTORS) # apart from the binary itself
 
-# replace "...-12-g123abc" with "...+12-g123abc" to remain semver compatible-ish
-version=$(git describe --always --dirty)
-version=$(echo "$version" | sed 's/-\([0-9]\{1,3\}-g[0-9a-f]\{5,10\}\)/+\1/')
+version=v%%PORTVERSION%%
 
-date=$(git show -s --format=%ct)
+date=$(date +%Y%m%d%H%M%S)
 user=$(whoami)
 host=$(hostname)
 host=${host%%.*}
@@ -169,7 +167,7 @@
 	"")
 		shift
 		export GOBIN=$(pwd)/bin
-		godep go install $* -ldflags "$ldflags" ./cmd/...
+		go install $* -ldflags "$ldflags" ./cmd/...
 		;;
 
 	clean)
