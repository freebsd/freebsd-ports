--- cf/app/app.go.orig	2015-04-29 12:36:58.960111000 +0000
+++ cf/app/app.go	2015-04-29 12:37:20.199807000 +0000
@@ -98,7 +98,7 @@
    {{.Version}}
 
 {{.Title "` + T("BUILD TIME:") + `"}}
-   {{.Compiled}}
+   BUILT_AT_UNKNOWN_TIME
    {{range .Commands}}
 {{.SubTitle .Name}}{{range .CommandSubGroups}}
 {{range .}}   {{.Name}} {{.Description}}
