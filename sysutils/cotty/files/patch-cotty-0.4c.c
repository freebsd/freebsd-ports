
$FreeBSD$

--- cotty-0.4c.c.orig	Sun Aug 22 21:39:06 2004
+++ cotty-0.4c.c	Sun Aug 22 21:40:01 2004
@@ -748,6 +748,7 @@
 		return 1;
 	case normal:
 	case keep_current:
+	break;
 	}
 	return 2;
 }
@@ -762,7 +763,8 @@
 	case normal:
 	case keep_current:
 	case direct:
-	}
+	break;
+	}	
 	return 2;
 }
 
@@ -989,8 +991,8 @@
 		strcpy(tty_name[1],pty_name[0]);
 		strcpy(pty_name[1],tty_name[0]);
 		break;
-	case normal:
-	case keep_current:
+	case normal: break;
+	case keep_current: break;
 	}
 	/* we don't need those null fds anymore */
 	for (j=0;j<3;j++) {
