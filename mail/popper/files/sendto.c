#ifdef YOUBIN
/*
 * Program:     $RCSfile: sendto.c,v $  $Revision: 1.1 $
 *
 * Purpose:     Send a message with UDP packet.
 *              Invoked from mh-inc-folder-hook.
 *
 * Usage:       sendto <host> <service> <message>
 *
 * Author:      K.Agusa     agusa@nuie.nagoya-u.ac.jp
 *              S.Yamamoto  yamamoto@nuie.nagoya-u.ac.jp
 *
 * Modified:    K.Makimura  macky@agusa.nuie.nagoya-u.ac.jp
 *
 * Date:        1993/07/24
 * Modified:    $Date: 1998/08/04 22:41:00 $
 *
 * Copyright:   K.Agusa and S.Yamamoto  1993 - 94
 *
 * The X Consortium, and any party obtaining a copy of these files from
 * the X Consortium, directly or indirectly, is granted, free of charge,
 * a full and unrestricted irrevocable, world-wide, paid up, royalty-free,
 * nonexclusive right and license to deal in this software and documentation
 * files (the "Software"), including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or sell copies
 * of the Software, and to permit persons who receive copies from any such
 * party to do so. This license includes without limitation a license to do
 * the foregoing actions under any patents of the party supplying this
 * software to the X Consortium.
 */

#ifndef lint
static char rcsid[] =
  "$FreeBSD$";
#endif /* not lint */

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/param.h>
#include <netinet/in.h>
#include <netdb.h>
#include <stdio.h>

/* 
 *                  Platform definitions.
 */

#if defined(SVR4) && !defined(SYSV)
#define SYSV
#endif /* defined(SVR4) && !defined(SYSV) */

/*
 *                  For compatibility.
 */

#ifdef SYSV
#include <string.h>                         /* For strchr(). */
#else /* not SYSV */
#include <strings.h>
#if !defined(strchr) && !defined(strrchr)
#define strchr(str, c)          index((str), (c))
#define strrchr(str, c)         rindex((str), (c))
#endif /* !defined(strchr) && !defined(strrchr) */
#endif /* not SYSV */

#ifdef SYSV
#define bzero(dst, len)         memset((dst), '\0', (len))
#define bcopy(src, dst, len)    memcpy((dst), (src), (len))
#endif

static struct sockaddr_in  sa;              /* Server address. */
static int                 sockid;          /* Socket Id. */
static char                err_msg[256];

static char *
udp_init(host, service)
char    *host;
char    *service;
{
    struct hostent *hp;                     /* Result of host name lookup. */
    struct servent *sp;                     /* Result of service lookup. */
    
    if ((hp = gethostbyname(host)) == NULL) {
        sprintf(err_msg, "No such host: %s", host);
        return (err_msg);
    }
    if ((sp = getservbyname(service, "udp")) == NULL) {
        sprintf(err_msg, "No such service: %s", service);
        return (err_msg);
    }
    if ((sockid = socket(hp->h_addrtype, SOCK_DGRAM, 0)) < 0) {
        sprintf(err_msg, "Error in getting socket");
        return (err_msg);
    }
    
    bzero((char *)&sa, sizeof(sa));
    sa.sin_family = hp->h_addrtype;
    bcopy((char *)hp->h_addr, (char *)&sa.sin_addr, hp->h_length);
    sa.sin_port = sp->s_port;
    
    return ((char *)NULL);
}

static char *
udp_send(message)
char    *message;
{
    int   len;
    
    len = strlen(message);
    if (sendto(sockid, message, len, 0, (struct sockaddr *)&sa, sizeof(sa)) != len) {
        sprintf(err_msg, "Error in sending packet");
        return (err_msg);
    }
    return ((char *)NULL);
}

#ifndef CALLED_FROM_POPD

void
main(argc, argv)
int     argc;
char    **argv;
{
    char    *msg;
    char    *prog_name;
    
    if ((prog_name = strrchr(argv[0], '/')) != NULL) {
        prog_name++;
    } else {
        prog_name = argv[0];
    }

    if (argc != 4) {
        fprintf(stderr, "%s: Usage: sendto <host> <service> <message>\n",
                prog_name);
        exit(1);
    }
    if ((msg = udp_init(argv[1], argv[2])) != NULL) {
        fprintf(stderr, "%s: %s\n", prog_name, msg);
        exit(1);
    }
    if ((msg = udp_send(argv[3])) != NULL) {
        fprintf(stderr, "%s: %s\n", prog_name, msg);
        exit(1);
    }
    exit(0);
}

#else /* CALLED_FROM_POPD */

#ifndef YOUBINSERVICE
#define YOUBINSERVICE       "biff"          /* For patch to popd. */
#endif /* not YOUBINSERVICE */

void
sendto_youbin(username)
char    *username;
{
    char  msg[256];
    
    if (udp_init("localhost", YOUBINSERVICE) != NULL) {
        return;
    }
    sprintf(msg, "U %s", username);
    udp_send(msg);
}

#endif /* CALLED_FROM_POPD */
#endif /* YOUBIN */
