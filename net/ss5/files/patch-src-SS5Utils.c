*** src/SS5Utils.c.orig	Tue Jun 12 17:16:55 2007
--- src/SS5Utils.c	Tue Feb 19 11:49:50 2008
***************
*** 130,135 ****
--- 130,140 ----
      case ALONE:
        snprintf(logString,256 - 1,"[VERB] Role is ALONE.");
      break;
+ 
+     default:
+ 	fprintf (stderr, "[WARN] - Don't know Role %s\n", logString);
+ 	return ERR;
+ 	break;
    }
    LOGUPDATE()
  
***************
*** 152,157 ****
--- 157,163 ----
     * Open ss5.ha file
     */
    if( (S5PeerFile = fopen(S5PeersFile,"r")) == NULL ) {
+     fprintf (stderr, "[ERR] Cannot Load %s file!\n", S5PeersFile);
      return ERR;
    }
  
