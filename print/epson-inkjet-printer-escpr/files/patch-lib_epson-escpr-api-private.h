--- lib/epson-escpr-api-private.h.orig	1970-01-01 00:00:00 UTC
+++ lib/epson-escpr-api-private.h
@@ -0,0 +1,3 @@
+EPS_ERR_CODE SetupJobAttrib(const EPS_JOB_ATTRIB*);
+EPS_ERR_CODE SendStartJob(EPS_BOOL);
+EPS_ERR_CODE PrintBand(const EPS_UINT8*, EPS_UINT32, EPS_UINT32*);
