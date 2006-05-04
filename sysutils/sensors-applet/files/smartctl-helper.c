/*
 * Copyright (C) 2006 Jean-Yves Lefort <jylefort@FreeBSD.org>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

static void
smartctl_helper_usage (void)
{
  fprintf(stderr, "Usage: smartctl-helper enable|attributes DEVICE\n");
  exit(1);
}

int
main (int argc, char **argv)
{
  if (argc != 3)
    smartctl_helper_usage();

  if (! strcmp(argv[1], "enable"))
    {
      char *smartctl_argv[] = { "smartctl", "-s", "on", argv[2], NULL };
      execve(SMARTCTL, smartctl_argv, NULL);
    }
  else if (! strcmp(argv[1], "attributes"))
    {
      char *smartctl_argv[] = { "smartctl", "-A", argv[2], NULL };
      execve(SMARTCTL, smartctl_argv, NULL);
    }
  else
    smartctl_helper_usage();

  /* execve failed */
  fprintf(stderr, "Unable to execute %s\n", SMARTCTL);
  return 1;
}
