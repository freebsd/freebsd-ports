https://invent.kde.org/plasma/libksysguard/-/merge_requests/445

--- processcore/cgroup_data_model.cpp.orig	2025-09-09 08:27:18 UTC
+++ processcore/cgroup_data_model.cpp
@@ -95,6 +95,7 @@ CGroupDataModel::CGroupDataModel(const QString &root, 
     , d(new CGroupDataModelPrivate)
 {
     d->m_updateTimer = new QTimer(this);
+    d->m_updateTimer->setInterval(2000);
     d->m_processes = ExtendedProcesses::instance();
 
     QList<ProcessAttribute *> attributes = d->m_processes->attributes();
@@ -113,7 +114,6 @@ CGroupDataModel::CGroupDataModel(const QString &root, 
     connect(d->m_updateTimer, &QTimer::timeout, this, [this]() {
         update();
     });
-    d->m_updateTimer->setInterval(2000);
     d->m_updateTimer->start();
 
     // updateAllProcesses will delete processes that no longer exist, a method that
