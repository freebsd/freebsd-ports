--- libs/libmythtv/recorders/dvbstreamhandler.cpp.orig	2012-03-05 03:31:31.000000000 +0100
+++ libs/libmythtv/recorders/dvbstreamhandler.cpp	2012-03-18 11:24:44.309770699 +0100
@@ -614,7 +614,7 @@
     {
         struct dmx_pes_filter_params pesFilterParams;
         memset(&pesFilterParams, 0, sizeof(struct dmx_pes_filter_params));
-        pesFilterParams.pid      = (__u16) _pid;
+        pesFilterParams.pid      = (uint16_t) _pid;
         pesFilterParams.input    = DMX_IN_FRONTEND;
         pesFilterParams.output   = DMX_OUT_TS_TAP;
         pesFilterParams.flags    = DMX_IMMEDIATE_START;
@@ -634,7 +634,7 @@
     {
         struct dmx_sct_filter_params sctFilterParams;
         memset(&sctFilterParams, 0, sizeof(struct dmx_sct_filter_params));
-        switch ( (__u16) _pid )
+        switch ( (uint16_t) _pid )
         {
             case 0x0: // PAT
                 sctFilterParams.filter.filter[0] = 0;
@@ -670,7 +670,7 @@
                 sctFilterParams.filter.mask[0]   = 0x00;
                 break;
         }
-        sctFilterParams.pid            = (__u16) _pid;
+        sctFilterParams.pid            = (uint16_t) _pid;
         sctFilterParams.timeout        = 0;
         sctFilterParams.flags          = DMX_IMMEDIATE_START;
 
