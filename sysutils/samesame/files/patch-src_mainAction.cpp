--- src/mainAction.cpp.orig	2011-09-15 22:31:49 UTC
+++ src/mainAction.cpp
@@ -181,7 +181,7 @@ int actionProcessOptions(int argc, char 
 //				strcpy(p, optarg);
 				pipeLeafs = popen(optarg, "w");
 				setlinebuf(pipeLeafs);
-				if (pipeLeafs < 0)
+				if (pipeLeafs == NULL)
 					warn("coudn't open pipe to: %s\n", optarg);
 				else if (outputLeafs)
 				{
@@ -194,7 +194,7 @@ int actionProcessOptions(int argc, char 
 					fclose(outputLeafs);
 				outputLeafs = fopen(optarg, "w");
 				setlinebuf(outputLeafs);
-				if (outputLeafs < 0)
+				if (outputLeafs == NULL)
 					warn("open file: %s\n", optarg);
 				else if (pipeLeafs)
 				{
