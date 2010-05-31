--- relayctl/relayctl.c.orig	2010-05-31 09:31:42.351734730 +0200
+++ relayctl/relayctl.c	2010-05-31 09:31:34.629284461 +0200
@@ -86,6 +86,7 @@
 };
 
 struct imsgbuf	*ibuf;
+int error = 0;
 
 __dead void
 usage(void)
@@ -104,7 +105,7 @@
 	struct imsg		 imsg;
 	int			 ctl_sock;
 	int			 done = 0;
-	int			 n;
+	int			 n, verbose = 0;
 
 	/* parse options */
 	if ((res = parse(argc - 1, argv + 1)) == NULL)
@@ -185,6 +186,15 @@
 	case MONITOR:
 		imsg_compose(ibuf, IMSG_CTL_NOTIFY, 0, 0, -1, NULL, 0);
 		break;
+	case LOG_VERBOSE:
+		verbose = 2;
+		/* FALLTHROUGH */
+	case LOG_BRIEF:
+		imsg_compose(ibuf, IMSG_CTL_LOG_VERBOSE, 0, 0, -1,
+		    &verbose, sizeof(verbose));
+		printf("logging request sent.\n");
+		done = 1;
+		break;
 	}
 
 	while (ibuf->w.queued)
@@ -224,6 +234,8 @@
 				done = show_command_output(&imsg);
 				break;
 			case NONE:
+			case LOG_VERBOSE:
+			case LOG_BRIEF:
 				break;
 			case MONITOR:
 				done = monitor(&imsg);
@@ -235,7 +247,7 @@
 	close(ctl_sock);
 	free(ibuf);
 
-	return (0);
+	return (error ? 1 : 0);
 }
 
 struct imsgname *
@@ -431,6 +443,7 @@
 		break;
 	case IMSG_CTL_FAIL:
 		printf("command failed\n");
+		error++;
 		break;
 	default:
 		errx(1, "wrong message in summary: %u", imsg->hdr.type);
