Starting with Qt 6.10, QFile::open() is automatically marked with
[[nodiscard]] [1]; check return value before proceeding.

[1] https://code.qt.io/cgit/qt/qtbase.git/commit/?h=6.10&id=7466831509fe163f3fd1e3a6bbf38f6f5a32ef00

--- Source/dooble_settings.cc.orig	2025-07-19 00:27:24 UTC
+++ Source/dooble_settings.cc
@@ -2095,8 +2095,8 @@ void dooble_settings::restore(bool read_database)
       file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
     else
       {
-	file.open(QIODevice::Truncate | QIODevice::WriteOnly);
-	file.setPermissions(QFileDevice::ReadOwner);
+       if(file.open(QIODevice::Truncate | QIODevice::WriteOnly))
+         file.setPermissions(QFileDevice::ReadOwner);
       }
   }
 
@@ -2914,8 +2914,8 @@ void dooble_settings::slot_apply(void)
       file.setPermissions(QFileDevice::ReadOwner | QFileDevice::WriteOwner);
     else
       {
-	file.open(QIODevice::Truncate | QIODevice::WriteOnly);
-	file.setPermissions(QFileDevice::ReadOwner);
+	if(file.open(QIODevice::Truncate | QIODevice::WriteOnly))
+	  file.setPermissions(QFileDevice::ReadOwner);
       }
   }
 
