*** src/icq_response.c.orig	Sat May 11 00:59:50 2002
--- src/icq_response.c	Sat May 11 20:05:32 2002
***************
*** 1,4 ****
! /* $Id: icq_response.c,v 1.53 2002/05/10 15:59:50 kuhlmann Exp $ */
  /* Copyright ? */
  
  #include "micq.h"
--- 1,4 ----
! /* $Id: icq_response.c,v 1.1 2002/04/05 10:00:08 root Exp root $ */
  /* Copyright ? */
  
  #include "micq.h"
***************
*** 482,494 ****
      {
          strcpy (buf, new);
          strcat (buf, " ");
!                       sprintf (buf + strlen (buf), "%d.%d", v1, v2);
!         if (v3 || v4) sprintf (buf + strlen (buf), ".%d", v3);
!         if (v4)       sprintf (buf + strlen (buf), " cvs %d", v4);
          if (ssl) strcat (buf, "/SSL");
      }
      else if (prG->verbose)
!         sprintf (buf, "%s %08x", i18n (1827, "Unknown client"), (unsigned int)tstamp);
      else
          buf[0] = '\0';
  
--- 482,494 ----
      {
          strcpy (buf, new);
          strcat (buf, " ");
!                       snprintf (buf + strlen (buf), sizeof (buf) - strlen (buf), "%d.%d", v1, v2);
!         if (v3 || v4) snprintf (buf + strlen (buf), sizeof (buf) - strlen (buf), ".%d", v3);
!         if (v4)       snprintf (buf + strlen (buf), sizeof (buf) - strlen (buf), " cvs %d", v4);
          if (ssl) strcat (buf, "/SSL");
      }
      else if (prG->verbose)
!         snprintf (buf, sizeof (buf), "%s %08x", i18n (1827, "Unknown client"), (unsigned int)tstamp);
      else
          buf[0] = '\0';
  
