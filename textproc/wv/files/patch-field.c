Index: field.c
===================================================================
RCS file: /cvsroot/wv/field.c,v
retrieving revision 1.19
retrieving revision 1.20
diff -u -r1.19 -r1.20
--- field.c	29 Dec 2002 16:37:00 -0000	1.19
+++ field.c	5 Jul 2004 18:10:03 -0000	1.20
@@ -98,18 +98,21 @@
 		  case 1:
 		      sprintf (temp, "%d", current->tm_mon+1);
 		      strcat (timestr, temp);
+		      consumed += strlen (temp);
 		      break;
 		  case 2:
 		      strcat (timestr, "%m");
+		      consumed += 2;
 		      break;
 		  case 3:
 		      strcat (timestr, "%b");
+		      consumed += 2;
 		      break;
 		  default:
 		      strcat (timestr, "%B");
+		      consumed += 2;
 		      break;
 		  }
-		consumed += 2;
 		break;
 	    case 's':
 	    case 'S':
@@ -139,6 +142,7 @@
 		  case 1:
 		      consumed += sprintf (temp, "%d", current->tm_wday);
 		      strcat (timestr, temp);
+		      consumed += strlen (temp);
 		      break;
 		  case 2:
 		      strcat (timestr, "%d");
@@ -182,12 +186,13 @@
 		  case 1:
 		      sprintf (temp, "%d", current->tm_hour % 12);
 		      strcat (timestr, temp);
+		      consumed += strlen (temp);
 		      break;
 		  default:
 		      strcat (timestr, "%I");
+		      consumed += 2;
 		      break;
 		  }
-		consumed += 2;
 		break;
 	    case 'H':
 		no = lookahead (token, 'H', 'H');
@@ -197,6 +202,7 @@
 		  case 1:
 		      consumed += sprintf (temp, "%d", current->tm_hour);
 		      strcat (timestr, temp);
+		      consumed += strlen (temp);
 		      break;
 		  default:
 		      strcat (timestr, "%H");
@@ -212,6 +218,7 @@
 		  case 1:
 		      consumed += sprintf (temp, "%d", current->tm_min);
 		      strcat (timestr, temp);
+		      consumed += strlen (temp);
 		      break;
 		  default:
 		      strcat (timestr, "%M");
