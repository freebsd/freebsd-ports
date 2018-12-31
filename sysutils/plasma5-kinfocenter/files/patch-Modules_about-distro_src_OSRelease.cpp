Dirtily patch in FreeBSD Name/Information. This should be done
in a better way down the line.


--- Modules/about-distro/src/OSRelease.cpp.orig	2018-09-13 16:46:31 UTC
+++ Modules/about-distro/src/OSRelease.cpp
@@ -63,73 +63,10 @@ static void setVar(QStringList *var, const QString &va
 
 OSRelease::OSRelease()
 {
-    // Set default values for non-optional fields.
-    name = QStringLiteral("Linux");
-    id = QStringLiteral("linux");
-    prettyName = QStringLiteral("Linux");
-
-    QString fileName;
-
-    if (QFile::exists(QStringLiteral("/etc/os-release"))) {
-        fileName = QStringLiteral("/etc/os-release");
-    } else if (QFile::exists(QStringLiteral("/usr/lib/os-release"))) {
-        fileName = QStringLiteral("/usr/lib/os-release");
-    } else {
-        return;
-    }
-
-
-    QFile file(fileName);
-    // NOTE: The os-release specification defines default values for specific
-    //       fields which means that even if we can not read the os-release file
-    //       we have sort of expected default values to use.
-    // TODO: it might still be handy to indicate to the outside whether
-    //       fallback values are being used or not.
-    file.open(QIODevice::ReadOnly | QIODevice::Text);
-    QString line;
-    QStringList comps;
-    while (!file.atEnd()) {
-        line = QString::fromLatin1(file.readLine());
-
-        if (line.startsWith(QLatin1Char('#'))) {
-            // Comment line
-            continue;
-        }
-
-        comps = line.split(QLatin1Char('='));
-
-        if (comps.size() != 2) {
-            // Invalid line.
-            continue;
-        }
-
-        QString key = comps.at(0);
-        QString value = comps.at(1).trimmed();
-        if (key == QLatin1String("NAME"))
-            setVar(&name, value);
-        else if (key == QLatin1String("VERSION"))
-            setVar(&version, value);
-        else if (key == QLatin1String("ID"))
-            setVar(&id, value);
-        else if (key == QLatin1String("ID_LIKE"))
-            setVar(&idLike, value);
-        else if (key == QLatin1String("VERSION_ID"))
-            setVar(&versionId, value);
-        else if (key == QLatin1String("PRETTY_NAME"))
-            setVar(&prettyName, value);
-        else if (key == QLatin1String("ANSI_COLOR"))
-            setVar(&ansiColor, value);
-        else if (key == QLatin1String("CPE_NAME"))
-            setVar(&cpeName, value);
-        else if (key == QLatin1String("HOME_URL"))
-            setVar(&homeUrl, value);
-        else if (key == QLatin1String("SUPPORT_URL"))
-            setVar(&supportUrl, value);
-        else if (key == QLatin1String("BUG_REPORT_URL"))
-            setVar(&bugReportUrl, value);
-        else if (key == QLatin1String("BUILD_ID"))
-            setVar(&buildId, value);
-        // os-release explicitly allows for vendor specific aditions. We have no
-        // interest in those right now.
-    }
+    name = QLatin1String("FreeBSD");
+    id = QLatin1String("FreeBSD");
+    prettyName = QLatin1String("FreeBSD");
+    homeUrl = QLatin1String("https://freebsd.org");
+    supportUrl = QLatin1String("https://www.freebsd.org/support.html");
+    bugReportUrl = QLatin1String("https://bugs.freebsd.org/bugzilla");
 }
