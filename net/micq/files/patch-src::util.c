*** src/util.c.orig	Sat May 11 03:01:05 2002
--- src/util.c	Sat May 11 20:10:23 2002
***************
*** 319,325 ****
  
      timeval = time (0);
      va_start (args, str);
!     sprintf (buf, "\n%-24.24s ", ctime (&timeval));
      vsprintf (&buf[strlen (buf)], str, args);
      va_end (args);
  
--- 319,325 ----
  
      timeval = time (0);
      va_start (args, str);
!     snprintf (buf, sizeof(buf), "\n%-24.24s ", ctime (&timeval));
      vsprintf (&buf[strlen (buf)], str, args);
      va_end (args);
  
***************
*** 332,343 ****
              else
                  return -1;
          }
!         sprintf (buffer, "%suin%ld.log", prG->logplace, uin);
  
  #if HAVE_SYMLINK
          if (ContactFindNick (uin))
          {
!             sprintf (symbuf, "%s%s.log", prG->logplace, ContactFindNick (uin));
              for (b = symbuf + strlen (prG->logplace); (b = strchr (b, '/')); )
                  *b = '_';
              symlink (buffer, symbuf);
--- 332,343 ----
              else
                  return -1;
          }
!         snprintf (buffer, sizeof (buffer), "%suin%ld.log", prG->logplace, uin);
  
  #if HAVE_SYMLINK
          if (ContactFindNick (uin))
          {
!             snprintf (symbuf, sizeof (symbuf), "%s%s.log", prG->logplace, ContactFindNick (uin));
              for (b = symbuf + strlen (prG->logplace); (b = strchr (b, '/')); )
                  *b = '_';
              symlink (buffer, symbuf);
