--- libs/libnapi_tools.sh.orig	2022-01-17 07:45:13 UTC
+++ libs/libnapi_tools.sh
@@ -42,7 +42,7 @@ declare -a ___g_tools=( 'tr=1' 'printf=1' 'mktemp=1' '
     'wc=1' 'dd=1' 'grep=1' 'seq=1' 'sed=1' 'cut=1' \
     'base64=1' 'unlink=0' 'stat=1' 'basename=1' \
     'dirname=1' 'cat=1' 'cp=1' 'mv=1' 'awk=1' \
-    'file=0' 'iconv=0' '7z|7za=0' 'md5|md5sum=1' \
+    'file=0' 'iconv=0' '7z|7za|7zz=0' 'md5|md5sum=1' \
     'fps:mediainfo=0' 'fps:mplayer|mplayer2=0' 'fps:ffmpeg|ffprobe=0' )
 
 ########################################################################
