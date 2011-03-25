--- gstreamer/mediaobject.cpp
+++ gstreamer/mediaobject.cpp
@@ -31,6 +31,7 @@
 #include <QtCore/QEvent>
 #include <QtCore/QFile>
 #include <QtCore/QLibrary>
+#include <QtCore/QPointer>
 #include <QtCore/QStringList>
 #include <QtCore/QTimer>
 #include <QtCore/QVector>
@@ -244,10 +245,11 @@ void MediaObject::pluginInstallationResult(GstInstallPluginsReturn result)
 
 void MediaObject::pluginInstallationDone(GstInstallPluginsReturn result, gpointer userData)
 {
-    MediaObject *mediaObject = static_cast<MediaObject*>(userData);
-    Q_ASSERT(mediaObject);
-    qRegisterMetaType<GstInstallPluginsReturn>("GstInstallPluginsReturn");
-    QMetaObject::invokeMethod(mediaObject, "pluginInstallationResult", Qt::QueuedConnection, Q_ARG(GstInstallPluginsReturn, result));
+    QPointer<MediaObject> *that = static_cast<QPointer<MediaObject>*>(userData);
+    if (*that) {
+        qRegisterMetaType<GstInstallPluginsReturn>("GstInstallPluginsReturn");
+        QMetaObject::invokeMethod(*that, "pluginInstallationResult", Qt::QueuedConnection, Q_ARG(GstInstallPluginsReturn, result));
+    }
 }
 #endif // PLUGIN_INSTALL_API
 
@@ -268,7 +270,7 @@ void MediaObject::installMissingCodecs()
         details[1] = NULL;
         GstInstallPluginsReturn status;
 
-        status = gst_install_plugins_async(details, ctx, pluginInstallationDone, this);
+        status = gst_install_plugins_async(details, ctx, pluginInstallationDone, new QPointer<MediaObject>(this));
         gst_install_plugins_context_free(ctx);
 
         if (status != GST_INSTALL_PLUGINS_STARTED_OK) {
