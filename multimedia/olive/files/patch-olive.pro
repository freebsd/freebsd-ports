--- olive.pro.orig	2019-11-11 06:05:02 UTC
+++ olive.pro
@@ -28,23 +28,23 @@ DEFINES += QT_DEPRECATED_WARNINGS
 #DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
 
 # Tries to get the current Git short hash
-system("which git") {
-    GITPATH = $$PWD
-
-    win32 {
-        GITPATH = $$system(cygpath $$PWD)
-    }
-
-    GITHASHVAR = $$system(git --git-dir=\"$$GITPATH/.git\" --work-tree=\"$$GITPATH\" log -1 --format=%h)
-
-    # Fallback for Ubuntu/Launchpad (extracts Git hash from debian/changelog rather than Git repo)
-    # (see https://answers.launchpad.net/launchpad/+question/678556)
-    isEmpty(GITHASHVAR) {
-        GITHASHVAR = $$system(sh $$PWD/debian/gitfromlog.sh $$PWD/debian/changelog)
-    }
-
-    DEFINES += GITHASH=\\"\"$$GITHASHVAR\\"\"
-}
+#system("which git") {
+#    GITPATH = $$PWD
+#
+#    win32 {
+#        GITPATH = $$system(cygpath $$PWD)
+#    }
+#
+#    GITHASHVAR = $$system(git --git-dir=\"$$GITPATH/.git\" --work-tree=\"$$GITPATH\" log -1 --format=%h)
+#
+#    # Fallback for Ubuntu/Launchpad (extracts Git hash from debian/changelog rather than Git repo)
+#    # (see https://answers.launchpad.net/launchpad/+question/678556)
+#    isEmpty(GITHASHVAR) {
+#        GITHASHVAR = $$system(sh $$PWD/debian/gitfromlog.sh $$PWD/debian/changelog)
+#    }
+#
+#    DEFINES += GITHASH=\\"\"$$GITHASHVAR\\"\"
+#}
 
 CONFIG += c++11
 
