This patch won't be necessary anymore in further versions.
See https://github.com/GoogleCloudPlatform/compute-image-packages/pull/440

--- google_compute_engine/accounts/accounts_daemon.py.orig	2017-07-18 16:43:14 UTC
+++ google_compute_engine/accounts/accounts_daemon.py
@@ -27,7 +27,7 @@ from google_compute_engine import logger
 from google_compute_engine import metadata_watcher
 from google_compute_engine.accounts import accounts_utils
 
-LOCKFILE = '/var/lock/google_accounts.lock'
+LOCKFILE = '/var/spool/lock/google_accounts.lock'
 
 
 class AccountsDaemon(object):
