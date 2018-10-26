--- yank.c.orig	2018-09-09 07:45:36 UTC
+++ yank.c
@@ -430,7 +430,8 @@ main(int argc, char *argv[])
 			break;
 		case 'g':
 			free(pat);
-			pat = optarg;
+			if ((pat = strdup(optarg)) == NULL)
+				err(1, NULL);
 			rflags |= REG_NEWLINE;
 			break;
 		case 'i':
