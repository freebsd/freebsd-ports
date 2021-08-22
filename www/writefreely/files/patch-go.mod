--- go.mod.orig	2021-06-30 17:17:02 UTC
+++ go.mod
@@ -1,6 +1,7 @@
 module github.com/writefreely/writefreely
 
 require (
+	git.mills.io/prologic/go-gopher v0.0.0-20210712135410-b7ebb55feece
 	github.com/clbanning/mxj v1.8.4 // indirect
 	github.com/dustin/go-humanize v1.0.0
 	github.com/fatih/color v1.10.0
@@ -23,7 +24,6 @@ require (
 	github.com/microcosm-cc/bluemonday v1.0.5
 	github.com/mitchellh/go-wordwrap v1.0.1
 	github.com/nu7hatch/gouuid v0.0.0-20131221200532-179d4d0c4d8d
-	github.com/prologic/go-gopher v0.0.0-20200721020712-3e11dcff0469
 	github.com/rainycape/unidecode v0.0.0-20150907023854-cb7f23ec59be // indirect
 	github.com/smartystreets/assertions v0.0.0-20190116191733-b6c0e53d7304 // indirect
 	github.com/smartystreets/goconvey v0.0.0-20181108003508-044398e4856c // indirect
@@ -42,7 +42,7 @@ require (
 	github.com/writeas/web-core v1.3.1-0.20210330164422-95a3a717ed8f
 	github.com/writefreely/go-nodeinfo v1.2.0
 	golang.org/x/crypto v0.0.0-20200622213623-75b288015ac9
-	golang.org/x/net v0.0.0-20200707034311-ab3426394381
+	golang.org/x/net v0.0.0-20210614182718-04defd469f4e
 	gopkg.in/ini.v1 v1.62.0
 )
 
