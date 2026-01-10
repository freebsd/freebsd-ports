--- src/metadata.cc.orig	2026-01-09 23:18:18 UTC
+++ src/metadata.cc
@@ -1,5 +1,6 @@
 #include "metadata.hh"
 #include "toml++/toml.hpp"
+#include <sstream>
 #include <QDebug>
 #include <QSaveFile>
 #include <QFile>
