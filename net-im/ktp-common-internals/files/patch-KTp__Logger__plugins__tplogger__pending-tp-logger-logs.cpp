commit 60452d2718f1b5a910dad64d6360d600d4107642
Author: Dan Vrátil <dvratil@redhat.com>
Date:   Thu Apr 10 21:08:59 2014 +0200

    Fix build (sorry!)

commit ccd4d133ba4becb7c8662eb3e57612e8aa9773e4
Author: Dan Vrátil <dvratil@redhat.com>
Date:   Thu Apr 10 20:58:47 2014 +0200

    Don't crash when TelepathyLoggerQt4 returns a null TextEvent

    Tpl::PendingEvents sometimes returns a list of events that includes a null
        event, which leads to a crash when we try to dereference it (either by
            hitting an assert in QtGlib, or by calling methods on a null pointer).

    BUG: 331104
        FIXED-IN: 0.8.1
--- KTp/Logger/plugins/tplogger/pending-tp-logger-logs.cpp
+++ KTp/Logger/plugins/tplogger/pending-tp-logger-logs.cpp
@@ -28,6 +28,8 @@
 
 #include <KTp/message-processor.h>
 
+#include <KDebug>
+
 PendingTpLoggerLogs::PendingTpLoggerLogs(const Tp::AccountPtr &account,
                                          const KTp::LogEntity &entity,
                                          const QDate &date,
@@ -60,6 +62,11 @@ void PendingTpLoggerLogs::logsRetrieved(Tpl::PendingOperation *op)
     QList<KTp::LogMessage> logs;
     Q_FOREACH (const Tpl::EventPtr &event, events) {
         const Tpl::TextEventPtr textEvent = event.dynamicCast<Tpl::TextEvent>();
+        if (textEvent.isNull()) {
+            kDebug() << "Received a null TextEvent!";
+            continue;
+        }
+
         logs << KTp::LogMessage(Utils::fromTplEntity(event->sender()),
                                 account(), event->timestamp(), textEvent->message(),
                                 textEvent->messageToken());
