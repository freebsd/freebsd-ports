/* chvt.c - change virtual terminal for [k]freebsd
   Copyright (C) 2009 Werner Koch

   This file is free software; as a special exception the author gives
   unlimited permission to copy and/or distribute it, with or without
   modifications, as long as this notice is preserved.

   This file is distributed in the hope that it will be useful, but
   WITHOUT ANY WARRANTY, to the extent permitted by law; without even
   the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
   PURPOSE.  */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <sys/consio.h>
#include <errno.h>


int 
main (int argc, char **argv)
{
  int fd, screen;
  
  if (argc < 1 || argc > 2)
    {
      fputs ("Usage: chvt [VTNO]\n", stderr);
      return 1;
    }
  if (argc == 2)
    {
      screen = atoi (argv[1]);
      
      if (screen < 1 || screen > 11)
        {
          fprintf (stderr, "chvt: invalid screen numver %d\n", screen);
          return 1;
        }
    }
  
  fd = open ("/dev/ttyv0", O_RDWR, 0);
  if (fd == -1) 
    {
      fprintf (stderr, "chvt: error opening terminal: %s\n", strerror (errno));
      return 1;
    }
  if (argc == 2)
    {
      if (ioctl (fd, VT_ACTIVATE, screen))
        {
          fprintf (stderr, "chvt: VT_ACTIVATE failed: %s\n", strerror (errno));
          return 1;
        }
    }
  else
    {
      if (ioctl (fd, VT_GETACTIVE, &screen))
        {
          fprintf (stderr, "chvt: VT_GETACTIVE failed: %s\n", strerror (errno));
          return 1;
        }
      printf ("%d\n", screen);
    }
  return 0;
}
