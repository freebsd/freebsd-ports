/* -*-C++-*-

  mntentemu.c++

  Copyright (C) 2002 Alan Eldridge
  
  This program is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2, or (at your option)
  any later version.
  
  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  
  You should have received a copy of the GNU General Public License
  along with this program; if not, write to the Free Software Foundation,
  Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.  

  $Id: mntent_compat.cc,v 1.3 2002/09/08 18:42:20 alane Exp $

  2002/09/08 alane@geeksrus.net
*/

#ifndef HAVE_MNTENT_H

#include "config.h"
#include "mntent.h"

#include <string>

// globals (yuck, but easier for debugging)

mntent	G_mntent;
int	G_mntpos;
int	G_mntsize;
bool	G_mntfOpen = false;
struct statfs *G_pmntstat = 0;

// map option flags to names

struct optmap {
  int fl;
  std::string st;
};

static struct optmap omap[] = {
  { MNT_SYNCHRONOUS,	"sync"		},
  { MNT_NOEXEC,		"noexec"	},
  { MNT_NOSUID,		"nosuid"	},
  { MNT_NODEV,		"nodev"		},
  { MNT_UNION,		"union"		},
  { MNT_ASYNC,		"async"		},
  { MNT_NOATIME,	"noatime"	},
  { MNT_NOCLUSTERR,	"noclusterr"	},
  { MNT_NOCLUSTERW,	"noclusterw"	},
  { MNT_NOSYMFOLLOW,	"nosymfollow"	},
  { MNT_SUIDDIR,	"suiddir"	},
  { 0, "noop" }
};

// zap everything for clarity

void
mntent::clear()
{
  memset(mnt_fsname, 0, sizeof(mnt_fsname));
  memset(mnt_dir, 0, sizeof(mnt_dir));
  memset(mnt_type, 0, sizeof(mnt_type));
  memset(mnt_opts, 0, sizeof(mnt_opts));
  mnt_freq = mnt_passno = 0;
}

// fake it from a statfs struct

mntent *
mntent::from_statfs(struct statfs *pst)
{

  clear();
  strcpy(mnt_fsname, pst->f_mntfromname);
  strcpy(mnt_dir, pst->f_mntonname);
  strcpy(mnt_type, pst->f_fstypename);
  mnt_freq = mnt_passno = 0;

  std::string opts;
  int fl = pst->f_flags;

  opts += (fl & MNT_RDONLY) ? "ro" : "rw";
  for (optmap *pmp = omap; pmp->fl != 0; pmp++) {
    if ((fl & pmp->fl) != 0) {
      opts += (" " + pmp->st);
    }
  }
  strcpy(mnt_opts, opts.c_str());

  return this;
}

// "rewind" the mtab file 

FILE *
setmntent(const char *, char *)
{
  if (!G_mntfOpen) {
    G_mntfOpen = true;
  }

  G_mntpos = 0;
  G_mntsize = getmntinfo(&G_pmntstat, MNT_NOWAIT);

  return reinterpret_cast<FILE *>(1);
}

// return ptr to opt string if present

char *
hasmntopt(const mntent *pmnt, const char *szopt)
{
  std::string opt(szopt);
  std::string mntopts(pmnt->mnt_opts);

  std::string::size_type pos = mntopts.find(opt);
  const char *szret = (pos == std::string::npos) ? "" : pmnt->mnt_opts + pos;

  return const_cast<char *>(szret);
}

// get next mntent until all gone, then return 0

struct mntent *
getmntent(FILE *)
{
  if (!G_mntfOpen) {
    return 0;
  } else if (G_mntpos < G_mntsize) {
    return G_mntent.from_statfs(G_pmntstat + G_mntpos++);
  } else {
    G_mntfOpen = false;
    return 0;
  }
}

// "close" the mtab file

int 
endmntent(FILE *)
{
  G_mntfOpen = false;
  return 0;
}

#endif /* ifndef HAVE_MNTENT_H */
