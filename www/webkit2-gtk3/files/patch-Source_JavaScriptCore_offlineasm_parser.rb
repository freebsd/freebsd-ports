--- Source/JavaScriptCore/offlineasm/parser.rb.orig	2021-10-21 08:52:07 UTC
+++ Source/JavaScriptCore/offlineasm/parser.rb
@@ -832,10 +832,10 @@ class Parser
                 @idx += 1
                 additionsDirectoryName = "#{@buildProductsDirectory}/usr/local/include/WebKitAdditions/"
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 list << parse(fileName) if fileExists
             else
@@ -864,10 +864,10 @@ class Parser
                 @idx += 1
                 additionsDirectoryName = "#{@buildProductsDirectory}/usr/local/include/WebKitAdditions/"
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 fileList << fileName if fileExists
             else
