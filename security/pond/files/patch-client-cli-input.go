--- client/cli-input.go.orig	2014-01-20 16:38:38.000000000 +0000
+++ client/cli-input.go	2014-01-24 23:58:07.000000000 +0000
@@ -350,12 +350,6 @@
 		i.commands.Insert(command.name)
 	}
 
-	autoCompleteCallback := func(line string, pos int, key rune) (string, int, bool) {
-		return i.AutoComplete(line, pos, key)
-	}
-
-	i.term.AutoCompleteCallback = autoCompleteCallback
-
 	var ackChan chan struct{}
 
 	for {
