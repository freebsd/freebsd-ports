From 0aead8cb868003a5dff2e81d6a7ffd7579652610 Mon Sep 17 00:00:00 2001
From: Fabian Keil <fk@fabiankeil.de>
Date: Sun, 17 Jan 2021 11:21:59 +0100
Subject: [PATCH] wolfSSL_CertManagerFree(): free refMutex

Fixes memory leaks like:
       ==323== 96 bytes in 1 blocks are definitely lost in loss record 3 of 4
       ==323==    at 0x4C291E1: calloc (in /usr/local/lib/valgrind/vgpreload_memcheck-amd64-freebsd.so)
       ==323==    by 0x585495F: pthread_mutex_init (in /lib/libthr.so.3)
       ==323==    by 0x4E7B5E8: wc_InitMutex (wc_port.c:1071)
       ==323==    by 0x4F09540: wolfSSL_CertManagerNew_ex (ssl.c:3596)
       ==323==    by 0x4EC6A81: InitSSL_Ctx (internal.c:1752)
       ==323==    by 0x4F0441E: wolfSSL_CTX_new_ex (ssl.c:394)
       ==323==    by 0x4F04658: wolfSSL_CTX_new (ssl.c:436)
       ==323==    by 0x400AA2: main (wolfssl-ctx-leak.c:9)

This is a partial cherry-pick of upstream commit
9598c037168b73ce2f by Tesfa Mael.
--- src/ssl.c.orig	2020-12-23 02:15:20 UTC
+++ src/ssl.c
@@ -3663,7 +3663,9 @@ void wolfSSL_CertManagerFree(WOLFSSL_CERT_MANAGER* cm)
             FreeTrustedPeerTable(cm->tpTable, TP_TABLE_SIZE, cm->heap);
             wc_FreeMutex(&cm->tpLock);
             #endif
-
+            if (wc_FreeMutex(&cm->refMutex) != 0) {
+                WOLFSSL_MSG("Couldn't free refMutex mutex");
+            }
             XFREE(cm, cm->heap, DYNAMIC_TYPE_CERT_MANAGER);
         }
     }
