/*
 * Copyright (c) 2000, 2001 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the Author nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE AUTHOR OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 * $Header: /home/ncvs/work/ports/mutt-devel/files/Attic/maildir_clean_dir.c,v 1.1.4.1 2002/05/16 11:44:06 ust Exp $
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <limits.h>
#include <stdio.h>
#include <time.h>

#include "config.h"
#include "mutt.h"
#include "mx.h"
/*
#include "init,h"
*/
#include "lib.h"

# ifndef HAVE_SNPRINTF
extern int snprintf (char *, size_t, const char *, ...);
# endif

time_t maildir_atime_entry(CONTEXT *ctx, const char *subdir, const char *fname, time_t *last_access)
{
  char buf[_POSIX_PATH_MAX];
  struct stat st;

  if(subdir)
    snprintf(buf, sizeof(buf), "%s/%s/%s", ctx->path, subdir, fname);
  else
    snprintf(buf, sizeof(buf), "%s/%s", ctx->path, fname);
   
  if (stat(buf, &st) == 0) {
    (*last_access) = st.st_atime;
    return 0;
  } else
    return -1;
}

int maildir_clean_dir(CONTEXT *ctx, const char *subdir, unsigned long time_limit)
{
  DIR *dirp;
  struct dirent *de;
  char buf[_POSIX_PATH_MAX];
  time_t rightnow, last_access, llast_access;
  
  if(!option (OPTCLEANMTMP))
    return 0;
  	  
  if(subdir)
    snprintf(buf, sizeof(buf), "%s/%s", ctx->path, subdir);
  else
    strfcpy(buf, ctx->path, sizeof(buf));
 
  if ((dirp = opendir(buf)) == NULL)
    return -1; /* is not there a dir ? */

  if ((rightnow = time(NULL)) == ((time_t) -1))
    return -1; /* can't get time ? */

  llast_access = rightnow;
  
  while ((de = readdir (dirp)) != NULL) {
  	/* I am not dealing with validity of messages, I'll remove any given visible messages */
/*
 * This is a concern to both new and cur, not tmp 
    if (ctx->magic == M_MAILDIR && *de->d_name == '.')
       continue;
*/
    
    dprint(2, (debugfile, "%s:%d: stating %s\n", __FILE__, __LINE__, de->d_name));
    if (!maildir_atime_entry(ctx, subdir, de->d_name, &last_access)) {
      if (difftime(last_access,rightnow) > 0)
        continue; /* I neither know how to handle this right now nor care for the time being */
    		
      if (difftime(rightnow,last_access) > time_limit) {
        if(subdir)
          snprintf(buf, sizeof(buf), "%s/%s/%s", ctx->path, subdir, de->d_name);
        else
          snprintf(buf, sizeof(buf), "%s/%s", ctx->path, de->d_name);
    		 
      mutt_unlink (buf);
    } else 
      (llast_access = (llast_access > last_access) ? last_access : llast_access);
    }
  }

  ctx->atime_tmp = (llast_access == rightnow) ? 0 : llast_access;

  closedir(dirp);
  return 0;
}
