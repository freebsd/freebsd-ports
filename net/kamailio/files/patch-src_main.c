--- src/main.c.orig	(revision 43f764cae870b15a96b8ca88f1eb195d4ceb8455)
+++ src/main.c
@@ -2446,7 +2446,7 @@
 						fprintf(stderr, "bad load module parameter\n");
 						goto error;
 					}
-					if (load_module(optarg)!=0) {
+					if (ksr_load_module(optarg, NULL)!=0) {
 						LM_ERR("failed to load the module: %s\n", optarg);
 						goto error;
 					}
