--- lib/Cm/CmMain.h.orig	2013-06-16 10:53:42.000000000 +0900
+++ lib/Cm/CmMain.h	2013-06-16 10:54:05.000000000 +0900
@@ -100,7 +100,7 @@
 // 起動時刻 プログラム名 STARTED by 起動ユーザ@起動マシン on
 // ttyname:ログインユーザ名 from リモートマシン名
 //----------------------------------------------------------------------
-struct CmMain {
+class CmMain {
 private:
 static	STR applicationName_;		// 起動コマンド名
 static	char catchStart_[256];		// 障害解析情報
