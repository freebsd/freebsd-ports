--- sid-filter/sid-filter.c.orig	Wed Apr 27 00:16:26 2005
+++ sid-filter/sid-filter.c	Sat Jun 11 09:22:24 2005
@@ -1140,8 +1140,6 @@
 					}
 					break;
 
-				  default:
-					/* NOTREACHED */
 				}
 			}
 
@@ -1865,7 +1863,7 @@
 		}
 
 		sid_msgcleanup(ctx);
-		return SMFIS_TEMPFAIL;
+		return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 	}
 
 	/* construct the status header's content */
@@ -1895,7 +1893,7 @@
 			}
 
 			sid_msgcleanup(ctx);
-			return SMFIS_TEMPFAIL;
+			return (testmode ? SMFIS_ACCEPT : SMFIS_TEMPFAIL);
 		}
 
 		sm_strlcat(stathdr, "; spf=", sizeof stathdr);
