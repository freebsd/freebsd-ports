diff -urN src/msgstat.c.orig src/msgstat.c
--- src/msgstat.c.orig	1970-01-01 01:00:00.000000000 +0100
+++ src/msgstat.c	2008-06-29 16:17:48.000000000 +0100
@@ -0,0 +1,83 @@
+#include <stdio.h>
+#include <sys/types.h>
+#include <sys/ipc.h>
+#include <sys/msg.h>
+#include <errno.h>
+
+
+main()
+{
+	int uid, gid, mode, bytes;
+	int rtrn, msqid, command, choice;
+	struct msqid_ds msqid_ds, *buf;
+
+	buf = &msqid_ds;
+
+	printf("Enter the msqid: ");
+	scanf("%i", &msqid);
+
+	printf("\n1 = IPC_STAT\n2 = IPC_SET\n3 = IPC_RMID\n");
+	printf("Enter command number: ");
+	scanf("%i", &command);
+
+	printf("\n\nmsqid = %d, command = %d\n", msqid, command);
+
+	switch (command) {
+		case 1:
+			rtrn = msgctl(msqid, IPC_STAT, buf);
+			if (rtrn != -1) {
+				printf("User %d, group %d, perms 0%o\n",
+					buf->msg_perm.uid, buf->msg_perm.gid,
+					buf->msg_perm.mode);
+				printf("cbytes: %d, qnum: %d, qbytes %d\n",
+					buf->msg_cbytes, buf->msg_qnum, 
+					buf->msg_qbytes);
+			}
+			break;
+
+		case 2:
+			rtrn = msgctl(msqid, IPC_STAT, buf);
+			if (rtrn == -1)
+				break;
+			printf("\n1 = uid, 2 = gid, 3 = mode, 4 = qbytes\n");
+			printf("Number of field to change: ");
+			scanf("%i", &choice);
+			switch (choice) {
+				case 1:
+					printf("\nUser id: ");
+					scanf("%i", &uid);
+					buf->msg_perm.uid = uid;
+					printf("User = %d\n", buf->msg_perm.uid);
+					break;
+				case 2:
+					printf("\nGroup id: ");
+					scanf("%i", &gid);
+					buf->msg_perm.gid = gid;
+					printf("Group = %d\n", buf->msg_perm.gid);
+					break;
+				case 3:
+					printf("\nMode: ");
+					scanf("%i", &mode);
+					buf->msg_perm.mode = mode;
+					printf("Mode = 0%o\n", buf->msg_perm.mode);
+					break;
+				case 4:
+					printf("\nQbytes: ");
+					scanf("%i", &bytes);
+					buf->msg_qbytes = bytes;
+					printf("Qbytes = %d\n", buf->msg_qbytes);
+					break;
+			}
+			rtrn = msgctl(msqid, IPC_SET, buf);
+			break;
+
+		case 3:
+			rtrn = msgctl(msqid, IPC_RMID, NULL);
+			break;
+	}
+
+	if (rtrn == -1)
+		perror("msgctl");
+
+	exit(0);
+}

