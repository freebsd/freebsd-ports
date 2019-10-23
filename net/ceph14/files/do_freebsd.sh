diff --git a/do_freebsd.sh b/do_freebsd.sh
index b0f0f5dab3..6fff34d829 100755
--- a/do_freebsd.sh
+++ b/do_freebsd.sh
@@ -22,18 +22,21 @@ CMAKE_C_FLAGS_DEBUG="$C_FLAGS_DEBUG $COMPILE_FLAGS"
 #
 #   On FreeBSD we need to preinstall all the tools that are required for building
 #   dashboard, because versions fetched are not working on FreeBSD.
- 
 
+echo Keeping the old build
+if [ -d build.old ]; then
+    sudo mv build.old build.del
+    sudo rm -rf build.del &
+fi
 if [ -d build ]; then
-    mv build build.remove
-    rm -f build.remove &
+    sudo mv build build.old
 fi
 
 ./do_cmake.sh "$*" \
 	-D WITH_CCACHE=ON \
 	-D CMAKE_BUILD_TYPE=Debug \
-	-D CMAKE_CXX_FLAGS_DEBUG="$CXX_FLAGS_DEBUG" \
-	-D CMAKE_C_FLAGS_DEBUG="$C_FLAGS_DEBUG" \
+	-D CMAKE_CXX_FLAGS_DEBUG="$CMAKE_CXX_FLAGS_DEBUG" \
+	-D CMAKE_C_FLAGS_DEBUG="$CMAKE_C_FLAGS_DEBUG" \
 	-D ENABLE_GIT_VERSION=OFF \
 	-D WITH_RADOSGW_AMQP_ENDPOINT=OFF \
 	-D WITH_SYSTEM_BOOST=ON \
@@ -52,11 +55,12 @@ fi
 	-D WITH_MGR=YES \
 	-D WITH_RDMA=OFF \
 	-D WITH_SPDK=OFF \
+	-D WITH_RADOSGW_BEAST_FRONTEND=OFF \
 	2>&1 | tee cmake.log
 
 echo start building 
 date
-(cd build; gmake -j$NPROC $BUILDOPTS )
+(cd build; gmake -j$NPROC $BUILDOPTS VERBOSE=1)
 
 echo start testing 
 date
