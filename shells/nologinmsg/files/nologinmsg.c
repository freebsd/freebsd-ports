/*
 * nologinmsg.c - A slightly improved nologin that will return a configurable
 * message, depending on how it is called.
 *
 * Copyright (c) 2002
 *  Richard Rose.  All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.  IN
 * NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 * TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 * PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 * LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * $Id: nologinmsg.c,v 1.1 2002/07/10 16:39:35 rik Exp $
 * 
 * rik
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sysexits.h>
#include <limits.h>
#include <err.h>
#include <fcntl.h>
#include <syslog.h>

#include "pathnames.h"

#define NOLOGINMSG_NAME "nologinmsg"
#define NOLOGINMSG_MSG "This account is currently not available.\n"

/* 
 * main - Program entry point.
 * Check how we are called. If it is not the way we expect, then search
 * the hard coded path for a file named with the name we are called with,
 * or, if that fails, the name of the user we are being run as, and print
 * that. After printing a message, quit.
 */
int main (void)
{
    char messagePath[PATH_MAX];
    char msgbuf[1024]; /* Arbitrary constant */
    char *user, *device;
    int fd, nbytes;
    struct stat buf;

    user = getlogin();
    if (user == NULL)
        user = "UNKNOWN";

    device = ttyname(0);
    if (device == NULL)
        device = "UNKNOWN";

    openlog( "nologinmsg", LOG_CONS, LOG_AUTH );
    syslog( LOG_WARNING, "%.35s on %.35s", user, device);
    closelog();

    strlcpy( messagePath, NOLOGINMSG_PATH, sizeof( messagePath ) );
    if (strcmp( getprogname(), NOLOGINMSG_NAME ) == 0){
        /*
         * Check for a user names message. If it exists and we can read it,
         * then print that, otherwise print the standard message
         */
        if (strlcat( messagePath, getlogin(), sizeof( messagePath ) ) >
                sizeof( messagePath ) )
            goto printStandard;
    } else {
        /*
         * We have been invoked by a different name. Check for a specific
         * message to print, and print it if we can, else print the standard
         * message
         */
        if (strlcat( messagePath, getprogname(), sizeof( messagePath ) ) >
                sizeof( messagePath ) )
            goto printStandard;
    }

    if (stat( messagePath, &buf ) != 0)
        goto printStandard;

    if ((buf.st_mode & S_IFREG) == 0)
        goto printStandard;

    fd = open( messagePath, O_RDONLY );
    if (fd == -1)
        goto printStandard;

    for (;;){
        nbytes = read( fd, msgbuf, sizeof( msgbuf ) );
        if (nbytes == -1)
            goto printStandard;

        write( STDERR_FILENO, msgbuf, nbytes );
        if (nbytes < sizeof( msgbuf ))
            exit( EX_UNAVAILABLE );
    }

printStandard:
    write( STDERR_FILENO, NOLOGINMSG_MSG, sizeof( NOLOGINMSG_MSG ) - 1 );
    exit( EX_UNAVAILABLE );
}

