--- libmpdemux/demuxer.h	9 Feb 2006 19:39:51 -0000	1.87
+++ libmpdemux/demuxer.h	12 Feb 2006 17:01:30 -0000	1.90
@@ -190,17 +190,19 @@
   dp->flags=0;
   dp->refcount=1;
   dp->master=NULL;
-  dp->buffer=len?(unsigned char*)malloc(len+8):NULL;
-  if(len) memset(dp->buffer+len,0,8);
+  dp->buffer=NULL;
+  if (len > 0 && (dp->buffer = (unsigned char *)malloc(len + 8)))
+    memset(dp->buffer + len, 0, 8);
+  else
+    dp->len = 0;
   return dp;
 }
 
 inline static void resize_demux_packet(demux_packet_t* dp, int len)
 {
-  if(len)
+  if(len > 0)
   {
      dp->buffer=(unsigned char *)realloc(dp->buffer,len+8);
-     memset(dp->buffer+len,0,8);
   }
   else
   {
@@ -208,6 +210,10 @@
      dp->buffer=NULL;
   }
   dp->len=len;
+  if (dp->buffer)
+     memset(dp->buffer + len, 0, 8);
+  else
+     dp->len = 0;
 }
 
 inline static demux_packet_t* clone_demux_packet(demux_packet_t* pack){
