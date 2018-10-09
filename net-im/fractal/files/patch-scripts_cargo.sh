--- scripts/cargo.sh.orig	2018-09-12 12:22:27 UTC
+++ scripts/cargo.sh
@@ -7,7 +7,7 @@ export FRACTAL_NAME_SUFFIX="$5"
 export FRACTAL_VERSION="$6"
 export FRACTAL_PROFILE="$7"
 
-if [[ "$FRACTAL_PROFILE" == "Devel" ]]
+if [ "$FRACTAL_PROFILE" = "Devel" ]
 then
     echo "DEBUG MODE"
     cargo build --manifest-path $1/Cargo.toml -p fractal-gtk && cp $1/target/debug/fractal-gtk $2
