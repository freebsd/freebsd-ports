--- libGutenSpell/MatchWordlists.c.orig	Mon Oct  7 15:30:33 2002
+++ libGutenSpell/MatchWordlists.c	Mon Oct  7 15:30:00 2002
@@ -430,11 +430,13 @@
 	  if (LogFile != NULL)
 	    fprintf (LogFile, "MatchWordlists:  GLOB_NOSPACE for \"%s\"\n", ss);
 	  break;
+#ifndef __FreeBSD__
 	case GLOB_ABEND:
           fprintf (stderr, "Possible disk-read error.\n");
 	  if (LogFile != NULL)
 	    fprintf (LogFile, "MatchWordlists:  GLOB_ABEND for \"%s\"\n", ss);
    	  break;
+#endif
 	default:
 	  fprintf (stderr, "Unknown globbing error.\n");
 	  if (LogFile != NULL)
