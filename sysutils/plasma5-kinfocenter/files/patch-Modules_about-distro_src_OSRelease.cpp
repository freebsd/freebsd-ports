Dirtily patch in FreeBSD Name/Information. This should be done
in a better way down the line.


--- Modules/about-distro/src/OSRelease.cpp.orig	2019-02-26 11:31:57 UTC
+++ Modules/about-distro/src/OSRelease.cpp
@@ -62,75 +62,12 @@ static void setVar(QStringList *var, const QString &va
 
 OSRelease::OSRelease(const QString &filePath)
 {
-    // Set default values for non-optional fields.
-    name = QStringLiteral("Linux");
-    id = QStringLiteral("linux");
-    prettyName = QStringLiteral("Linux");
-
-    if (filePath.isEmpty()) {
-        return;
-    }
-
-    QHash<QString, QString *> stringHash = {
-        { QStringLiteral("NAME"), &name },
-        { QStringLiteral("VERSION"), &version },
-        { QStringLiteral("ID"), &id },
-        // idLike is not a QString, special handling below!
-        { QStringLiteral("VERSION_CODENAME"), &versionCodename },
-        { QStringLiteral("VERSION_ID"), &versionId },
-        { QStringLiteral("PRETTY_NAME"), &prettyName },
-        { QStringLiteral("ANSI_COLOR"), &ansiColor },
-        { QStringLiteral("CPE_NAME"), &cpeName },
-        { QStringLiteral("HOME_URL"), &homeUrl },
-        { QStringLiteral("DOCUMENTATION_URL"), &documentationUrl },
-        { QStringLiteral("SUPPORT_URL"), &supportUrl },
-        { QStringLiteral("BUG_REPORT_URL"), &bugReportUrl },
-        { QStringLiteral("PRIVACY_POLICY_URL"), &privacyPolicyUrl },
-        { QStringLiteral("BUILD_ID"), &buildId },
-        { QStringLiteral("VARIANT"), &variant },
-        { QStringLiteral("VARIANT_ID"), &variantId },
-        { QStringLiteral("LOGO"), &logo }
-    };
-
-    QFile file(filePath);
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
-
-        if (QString *var = stringHash.value(key, nullptr)) {
-            setVar(var, value);
-        }
-
-        // ID_LIKE is a list and parsed as such (rather than a QString).
-        if (key == QLatin1String("ID_LIKE")) {
-            setVar(&idLike, value);
-        }
-
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
 
 QString OSRelease::defaultFilePath()
