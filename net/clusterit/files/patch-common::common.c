Index: common/common.c
===================================================================
RCS file: /cvsroot/src/common/common.c,v
retrieving revision 1.5
retrieving revision 1.6
diff -u -r1.5 -r1.6
--- common/common.c	2001/08/13 21:04:22	1.5
+++ common/common.c	2001/08/16 19:08:17	1.6
@@ -1,4 +1,4 @@
-/* $Id: common.c,v 1.5 2001/08/13 21:04:22 garbled Exp $ */
+/* $Id: common.c,v 1.6 2001/08/16 19:08:17 garbled Exp $ */
 /*
  * Copyright (c) 1998, 1999, 2000
  *	Tim Rightnour.  All rights reserved.
@@ -42,7 +42,7 @@
 __COPYRIGHT(
 "@(#) Copyright (c) 1998, 1999, 2000\n\
         Tim Rightnour.  All rights reserved\n");
-__RCSID("$Id: common.c,v 1.5 2001/08/13 21:04:22 garbled Exp $");
+__RCSID("$Id: common.c,v 1.6 2001/08/16 19:08:17 garbled Exp $");
 #endif
 
 
@@ -91,8 +91,8 @@
 		for (i=0; (i < fanout && nodeptr != NULL); i++) {
 			l++;
 			group = NULL;
-			if (nodeptr->group >= 0)
-					group = strdup(grouplist[nodeptr->group].name);
+			if (nodeptr->group >= 0 && grouplist[nodeptr->group].name)
+				group = strdup(grouplist[nodeptr->group].name);
 			if (group == NULL)
 				(void)printf("Node: %3d  Fangroup: %3d  Rungroup: None"
 					"             Host: %-15s\n", l, n + 1, nodeptr->name);
