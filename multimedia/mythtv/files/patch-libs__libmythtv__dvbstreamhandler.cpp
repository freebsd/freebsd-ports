--- libs/libmythtv/dvbstreamhandler.cpp.orig	2010-03-07 04:11:52.000000000 +0100
+++ libs/libmythtv/dvbstreamhandler.cpp	2010-04-26 23:28:18.000000000 +0200
@@ -881,7 +881,7 @@
     {
         struct dmx_pes_filter_params pesFilterParams;
         bzero(&pesFilterParams, sizeof(struct dmx_pes_filter_params));
-        pesFilterParams.pid      = (__u16) _pid;
+        pesFilterParams.pid      = (uint16_t) _pid;
         pesFilterParams.input    = DMX_IN_FRONTEND;
         pesFilterParams.output   = DMX_OUT_TS_TAP;
         pesFilterParams.flags    = DMX_IMMEDIATE_START;
@@ -901,7 +901,7 @@
     {
         struct dmx_sct_filter_params sctFilterParams;
         bzero(&sctFilterParams, sizeof(struct dmx_sct_filter_params));
-        switch ( (__u16) _pid )
+        switch ( (uint16_t) _pid )
         {
             case 0x0: // PAT
                 sctFilterParams.filter.filter[0] = 0;
@@ -937,7 +937,7 @@
                 sctFilterParams.filter.mask[0]   = 0x00;
                 break;
         }
-        sctFilterParams.pid            = (__u16) _pid;
+        sctFilterParams.pid            = (uint16_t) _pid;
         sctFilterParams.timeout        = 0;
         sctFilterParams.flags          = DMX_IMMEDIATE_START;
 
