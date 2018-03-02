--- libs/libmythtv/recorders/dvbstreamhandler.cpp.orig	2015-06-16 16:03:30 UTC
+++ libs/libmythtv/recorders/dvbstreamhandler.cpp
@@ -620,7 +620,7 @@ bool DVBPIDInfo::Open(const QString &dvb_dev, bool use
     {
         struct dmx_pes_filter_params pesFilterParams;
         memset(&pesFilterParams, 0, sizeof(struct dmx_pes_filter_params));
-        pesFilterParams.pid      = (__u16) _pid;
+        pesFilterParams.pid      = (uint16_t) _pid;
         pesFilterParams.input    = DMX_IN_FRONTEND;
         pesFilterParams.output   = DMX_OUT_TS_TAP;
         pesFilterParams.flags    = DMX_IMMEDIATE_START;
@@ -640,7 +640,7 @@ bool DVBPIDInfo::Open(const QString &dvb_dev, bool use
     {
         struct dmx_sct_filter_params sctFilterParams;
         memset(&sctFilterParams, 0, sizeof(struct dmx_sct_filter_params));
-        switch ( (__u16) _pid )
+        switch ( (uint16_t) _pid )
         {
             case 0x0: // PAT
                 sctFilterParams.filter.filter[0] = 0;
@@ -676,7 +676,7 @@ bool DVBPIDInfo::Open(const QString &dvb_dev, bool use
                 sctFilterParams.filter.mask[0]   = 0x00;
                 break;
         }
-        sctFilterParams.pid            = (__u16) _pid;
+        sctFilterParams.pid            = (uint16_t) _pid;
         sctFilterParams.timeout        = 0;
         sctFilterParams.flags          = DMX_IMMEDIATE_START;
 
