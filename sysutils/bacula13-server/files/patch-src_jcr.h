--- src/jcr.h.orig	2023-05-02 09:50:49 UTC
+++ src/jcr.h
@@ -399,6 +399,7 @@ class JCR { (public)
    int32_t FDVersion;                 /* File daemon version number */
    int32_t SDVersion;                 /* Storage daemon version number */
    int64_t spool_size;                /* Spool size for this job */
+   uint64_t client_version;           /* Client version as a number */
    utime_t snapshot_retention;        /* Snapshot retention (from Client/Job resource) */
    volatile bool sd_msg_thread_done;  /* Set when Storage message thread done */
    bool wasVirtualFull;               /* set if job was VirtualFull */
