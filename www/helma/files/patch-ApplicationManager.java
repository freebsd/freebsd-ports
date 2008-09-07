--- ../src/helma/main/ApplicationManager.java.orig	2008-04-07 14:45:30.000000000 +0200
+++ ../src/helma/main/ApplicationManager.java	2008-07-12 16:16:14.000000000 +0200
@@ -369,6 +369,9 @@
                             repositoryImpl = "helma.framework.repository.FileRepository";
                         }
                     }
+                    
+                    if(!new File(repositoryArgs).isAbsolute())
+                    	repositoryArgs = server.getHopHome() + "/" + repositoryArgs;
 
                     try {
                         Repository newRepository = (Repository) Class.forName(repositoryImpl)
