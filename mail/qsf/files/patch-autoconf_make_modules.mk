--- autoconf/make/modules.mk~.orig	Wed Jun  1 00:19:04 2005
+++ autoconf/make/modules.mk~	Wed Jun  1 00:19:45 2005
@@ -3,21 +3,21 @@
 # Creation time: Sat Feb 19 12:25:32 GMT 2005
 
 src/db.o:  src/db/alloc.o src/db/cache.o src/db/delete.o src/db/error.o src/db/fetch.o src/db/gdbm.o src/db/io.o src/db/lock.o src/db/mysql.o src/db/organise.o src/db/signal.o src/db/sqlite.o src/db/store.o src/db/walk.o
-	$(LD) $(LDFLAGS) -o $@  src/db/alloc.o src/db/cache.o src/db/delete.o src/db/error.o src/db/fetch.o src/db/gdbm.o src/db/io.o src/db/lock.o src/db/mysql.o src/db/organise.o src/db/signal.o src/db/sqlite.o src/db/store.o src/db/walk.o
+	$(LD) -r $(LDFLAGS) -o $@  src/db/alloc.o src/db/cache.o src/db/delete.o src/db/error.o src/db/fetch.o src/db/gdbm.o src/db/io.o src/db/lock.o src/db/mysql.o src/db/organise.o src/db/signal.o src/db/sqlite.o src/db/store.o src/db/walk.o
 
 src/mailbox.o:  src/mailbox/alloc.o src/mailbox/count.o src/mailbox/scan.o src/mailbox/select.o
-	$(LD) $(LDFLAGS) -o $@  src/mailbox/alloc.o src/mailbox/count.o src/mailbox/scan.o src/mailbox/select.o
+	$(LD) -r $(LDFLAGS) -o $@  src/mailbox/alloc.o src/mailbox/count.o src/mailbox/scan.o src/mailbox/select.o
 
 src/main.o:  src/main/help.o src/main/license.o src/main/log.o src/main/main.o src/main/options.o src/main/tick.o src/main/version.o
-	$(LD) $(LDFLAGS) -o $@  src/main/help.o src/main/license.o src/main/log.o src/main/main.o src/main/options.o src/main/tick.o src/main/version.o
+	$(LD) -r $(LDFLAGS) -o $@  src/main/help.o src/main/license.o src/main/log.o src/main/main.o src/main/options.o src/main/tick.o src/main/version.o
 
 src/message.o:  src/message/alloc.o src/message/base64.o src/message/dump.o src/message/header.o src/message/parse.o src/message/qp.o src/message/read.o src/message/rfc2047.o
-	$(LD) $(LDFLAGS) -o $@  src/message/alloc.o src/message/base64.o src/message/dump.o src/message/header.o src/message/parse.o src/message/qp.o src/message/read.o src/message/rfc2047.o
+	$(LD) -r $(LDFLAGS) -o $@  src/message/alloc.o src/message/base64.o src/message/dump.o src/message/header.o src/message/parse.o src/message/qp.o src/message/read.o src/message/rfc2047.o
 
 src/spam.o:  src/spam/alloc.o src/spam/allowlist.o src/spam/benchmark.o src/spam/check.o src/spam/cksum.o src/spam/db.o src/spam/dump.o src/spam/merge.o src/spam/prune.o src/spam/token.o src/spam/train.o src/spam/update.o
-	$(LD) $(LDFLAGS) -o $@  src/spam/alloc.o src/spam/allowlist.o src/spam/benchmark.o src/spam/check.o src/spam/cksum.o src/spam/db.o src/spam/dump.o src/spam/merge.o src/spam/prune.o src/spam/token.o src/spam/train.o src/spam/update.o
+	$(LD) -r $(LDFLAGS) -o $@  src/spam/alloc.o src/spam/allowlist.o src/spam/benchmark.o src/spam/check.o src/spam/cksum.o src/spam/db.o src/spam/dump.o src/spam/merge.o src/spam/prune.o src/spam/token.o src/spam/train.o src/spam/update.o
 
 src/tests.o:  src/tests/attached_files.o src/tests/gibberish.o src/tests/gtube.o src/tests/html.o src/tests/imgcount.o src/tests/main.o src/tests/urls.o
-	$(LD) $(LDFLAGS) -o $@  src/tests/attached_files.o src/tests/gibberish.o src/tests/gtube.o src/tests/html.o src/tests/imgcount.o src/tests/main.o src/tests/urls.o
+	$(LD) -r $(LDFLAGS) -o $@  src/tests/attached_files.o src/tests/gibberish.o src/tests/gtube.o src/tests/html.o src/tests/imgcount.o src/tests/main.o src/tests/urls.o
 
 
