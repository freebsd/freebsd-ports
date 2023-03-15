--- go.mod.orig	2023-03-15 01:06:55 UTC
+++ go.mod
@@ -1,17 +1,21 @@
 module github.com/muesli/duf
 
-go 1.15
+go 1.17
 
 require (
 	github.com/IGLOU-EU/go-wildcard v1.0.3
 	github.com/jedib0t/go-pretty/v6 v6.2.5
-	github.com/kr/pretty v0.2.0 // indirect
 	github.com/mattn/go-runewidth v0.0.13
 	github.com/muesli/mango v0.1.0
 	github.com/muesli/roff v0.1.0
 	github.com/muesli/termenv v0.11.0
-	golang.org/x/sys v0.0.0-20220114195835-da31bd327af9
+	golang.org/x/sys v0.6.0
 	golang.org/x/term v0.0.0-20210406210042-72f3dc4e9b72
-	gopkg.in/check.v1 v1.0.0-20190902080502-41f04d3bba15 // indirect
+)
+
+require (
+	github.com/lucasb-eyer/go-colorful v1.2.0 // indirect
+	github.com/mattn/go-isatty v0.0.14 // indirect
+	github.com/rivo/uniseg v0.2.0 // indirect
 	gopkg.in/yaml.v3 v3.0.0-20210107192922-496545a6307b // indirect
 )
