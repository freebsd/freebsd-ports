--- Source/JavaScriptCore/offlineasm/parser.rb.orig	2024-05-21 17:03:42 UTC
+++ Source/JavaScriptCore/offlineasm/parser.rb
@@ -840,10 +840,10 @@ class Parser
                     additionsDirectoryName = "#{@buildProductsDirectory}#{@headersFolderPath}/WebKitAdditions/"
                 end
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 list << parse(fileName, @options, @sources) if fileExists
             else
@@ -876,10 +876,10 @@ class Parser
                     additionsDirectoryName = "#{@buildProductsDirectory}#{@headersFolderPath}/WebKitAdditions/"
                 end
                 fileName = IncludeFile.new(moduleName, additionsDirectoryName).fileName
-                if not File.exists?(fileName)
+                if not File.exist?(fileName)
                     fileName = IncludeFile.new(moduleName, @tokens[@idx].codeOrigin.fileName.dirname).fileName
                 end
-                fileExists = File.exists?(fileName)
+                fileExists = File.exist?(fileName)
                 raise "File not found: #{fileName}" if not fileExists and not isOptional
                 if fileExists
                     parser = Parser.new(readTextFile(fileName), SourceFile.new(fileName), options)
