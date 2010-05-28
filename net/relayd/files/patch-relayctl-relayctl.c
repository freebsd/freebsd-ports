--- relayctl/relayctl.c.orig	2010-05-27 11:10:01.111140304 +0200
+++ relayctl/relayctl.c	2010-05-27 11:10:16.855173170 +0200
@@ -86,6 +86,7 @@
 };
 
 struct imsgbuf	*ibuf;
+int error = 0;
 
 __dead void
 usage(void)
@@ -235,7 +236,7 @@
 	close(ctl_sock);
 	free(ibuf);
 
-	return (0);
+	return (error ? 1 : 0);
 }
 
 struct imsgname *
@@ -431,6 +432,7 @@
 		break;
 	case IMSG_CTL_FAIL:
 		printf("command failed\n");
+		error++;
 		break;
 	default:
 		errx(1, "wrong message in summary: %u", imsg->hdr.type);
