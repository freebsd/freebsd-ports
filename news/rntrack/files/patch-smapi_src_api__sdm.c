src//api_sdm.c:1183:41: warning: shift count >= width of type [-Wshift-count-overflow]
 1183 |             if(mh->num_msg == (dword)(1 << (sizeof(mh->num_msg) * 8 - 1)))
      |                                         ^  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
2 warnings generated.

--- smapi/src/api_sdm.c.orig	2023-02-11 19:53:26 UTC
+++ smapi/src/api_sdm.c
@@ -430,7 +430,7 @@ static MSGH * _XPENTRY SdmOpenMsg(MSGA * mh, word mode
 
     if(mode == MOPEN_CREATE)
     {
-        if(mh->num_msg == (dword)(1 << (sizeof(mh->num_msg) * 8 - 1)))
+        if(mh->num_msg == ((dword)1 << (sizeof(mh->num_msg) * 8 - 1)))
         {
             /* Messagebase implementaion (size) limit (messages counter is full)*/
             pfree(msgh);
@@ -1180,7 +1180,7 @@ static sword near _SdmRescanArea(MSGA * mh)
 
 #endif
 
-            if(mh->num_msg == (dword)(1 << (sizeof(mh->num_msg) * 8 - 1)))
+            if(mh->num_msg == ((dword)1 << (sizeof(mh->num_msg) * 8 - 1)))
             {
                 /* Messagebase implementaion (size) limit (messages counter is full)*/
                 msgapierr = MERR_LIMIT;
