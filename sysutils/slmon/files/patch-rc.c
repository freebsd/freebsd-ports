--- rc.c.orig	Tue Aug 17 13:38:31 2004
+++ rc.c	Tue Aug 17 13:39:32 2004
@@ -109,6 +109,7 @@
 			mode = MODE_H;
 			break;
 		    default:
+			break;
 		    }
 		    break;
 		case 'm':
@@ -139,6 +140,7 @@
 			conf.fs = 2;
 			break;
 		    default:
+			break;
 		    }
 		    break;
 		case 'n':
@@ -156,6 +158,7 @@
 			conf.net = 3;
 			break;
 		    default:
+			break;
 		    }
 		    break;
 		case 'v':
@@ -166,6 +169,7 @@
 		    update_time = (unsigned long) (atof(tmp + pos) * 1000000.0);
 		    update_time -= (unsigned long) 10000;
 		default:
+		    break;
 		}
 		free(key);
 	    }
