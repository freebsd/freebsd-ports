/* $Id: xio-socks.c,v 1.21 2004/07/10 15:21:38 gerhard Exp $ */
/* Copyright Gerhard Rieger 2001-2004 */
/* Published under the GNU General Public License V.2, see file COPYING */

/* this file contains the source for opening addresses of socks4 type */

#include "xiosysincludes.h"
#include "xioopen.h"
#include "xio-socket.h"
#include "xio-ipapp.h"

#include "xio-socks.h"


#if WITH_SOCKS4 || WITH_SOCKS4A
enum {
   SOCKS_CD_GRANTED = 90,
   SOCKS_CD_FAILED,
   SOCKS_CD_NOIDENT,
   SOCKS_CD_IDENTFAILED
} ;

#define SOCKSPORT "1080"
#define BUFF_LEN (SIZEOF_STRUCT_SOCKS4+512)

static int xioopen_socks4_connect(char *a1, int rw, xiofile_t *fd,
				  unsigned groups, int dummy1, int dummy2,
				  void *dummyp1);

const struct optdesc opt_socksport = { "socksport", NULL, OPT_SOCKSPORT, GROUP_IP_SOCKS4, PH_LATE, TYPE_STRING, OFUNC_SPEC };
const struct optdesc opt_socksuser = { "socksuser", NULL, OPT_SOCKSUSER, GROUP_IP_SOCKS4, PH_LATE, TYPE_NAME, OFUNC_SPEC };

const struct addrdesc addr_socks4_connect = { "socks4", 3, xioopen_socks4_connect, GROUP_FD|GROUP_SOCKET|GROUP_SOCK_IP4|GROUP_IP_TCP|GROUP_IP_SOCKS4|GROUP_CHILD|GROUP_RETRY, 0, 0, NULL HELP(":<socks-server>:<host>:<port>") };

const struct addrdesc addr_socks4a_connect = { "socks4a", 3, xioopen_socks4_connect, GROUP_FD|GROUP_SOCKET|GROUP_SOCK_IP4|GROUP_IP_TCP|GROUP_IP_SOCKS4|GROUP_CHILD|GROUP_RETRY, 1, 0, NULL HELP(":<socks-server>:<host>:<port>") };

static int xioopen_socks4_connect(char *a1, int rw, xiofile_t *xxfd,
				  unsigned groups, int socks4a, int dummy2,
				  void *dummyp1) {
   /* we expect the form: host:host:port */
   char *a2, *a3, *a4;
   struct single *xfd = &xxfd->stream;
   struct opt *opts = NULL, *opts0 = NULL;
   char *sockdname = a1, *socksport = NULL;
   const char *targetname;
   const char *protname = "tcp";
   bool dofork = false;
   struct sockaddr_in us_sa,  *us = &us_sa;
   struct sockaddr_in themsa, *them = &themsa;
   bool needbind = false;
   bool lowport = false;
   unsigned char buff[BUFF_LEN];
   struct socks4 *sockhead = (struct socks4 *)buff;
   size_t buflen = sizeof(buff);
   int socktype = SOCK_STREAM;
   int level;
   int result;

   a2 = strchr(a1, ':');
   if (!a2) {
      Error1("xioopen_socks4_connect(\"%s\",,): missing target address", a1);
      return STAT_NORETRY;
   }
   *a2 = '\0', ++a2;
   targetname = a2;

   if ((a3 = strchr(a2, ':')) == NULL) {
      Error2("xioopen_socks4_connect(\"%s:%s\",,): missing target port", a1, a2);
      return STAT_NORETRY;
   }
   *a3 = '\0', ++a3;

   a4 = strchr(a3, ',');
   if (a4)  *a4 = '\0', ++a4;

   if (parseopts(a4, groups, &opts) < 0) {
      return STAT_NORETRY;
   }

   socket_in_init(us);

   applyopts(-1, opts, PH_INIT);
   applyopts_single(xfd, opts, PH_INIT);

   retropt_int(opts, OPT_SO_TYPE, &socktype);

   retropt_bool(opts, OPT_FORK, &dofork);

   result = _xioopen_socks4_prepare(a3, opts, &socksport, sockhead, &buflen);
   if (result != STAT_OK)  return result;

   result = _xioopen_ip4app_prepare(opts, &opts0, sockdname, socksport,
				    protname, them, us,
				    &needbind, &lowport, &socktype);
   if (result != STAT_OK)  return result;

   Notice5("opening connection to %s:%u via socks4 server %s:%s as user \"%s\"",
	   a2,
	   ntohs(sockhead->port),
	   a1, socksport, sockhead->userid);

   do {	/* loop over failed connect and socks-request attempts */

#if WITH_RETRY
      if (xfd->forever || xfd->retry) {
	 level = E_INFO;
      } else
#endif /* WITH_RETRY */
	 level = E_ERROR;

      /* we try to resolve the target address _before_ connecting to the socks
	 server: this avoids unnecessary socks connects and timeouts */
      result =
	 _xioopen_socks4_connect0(xfd, targetname, socks4a, sockhead,
				  (ssize_t *)&buflen, level);
      switch (result) {
      case STAT_OK: break;
#if WITH_RETRY
      case STAT_RETRYLATER:
      case STAT_RETRYNOW:
	 if (xfd->forever || xfd->retry--) {
	    if (result == STAT_RETRYLATER)  Nanosleep(&xfd->intervall, NULL);
	    continue;
	 }
#endif /* WITH_RETRY */
      default:
	 return result;
      }

      /* this cannot fork because we retrieved fork option above */
      result =
	 _xioopen_connect (xfd,
			   needbind?(struct sockaddr *)us:NULL, sizeof(*us),
			   (struct sockaddr *)them, sizeof(struct sockaddr_in),
			   opts, PF_INET, socktype, IPPROTO_TCP, lowport, level);
      switch (result) {
      case STAT_OK: break;
#if WITH_RETRY
      case STAT_RETRYLATER:
      case STAT_RETRYNOW:
	 if (xfd->forever || xfd->retry--) {
	    if (result == STAT_RETRYLATER)  Nanosleep(&xfd->intervall, NULL);
	    continue;
	 }
#endif /* WITH_RETRY */
      default:
	 return result;
      }

      applyopts(xfd->fd, opts, PH_ALL);

      if ((result = _xio_openlate(xfd, opts)) < 0)
	 return result;

      result = _xioopen_socks4_connect(xfd, sockhead, buflen, level);
      switch (result) {
      case STAT_OK: break;
#if WITH_RETRY
      case STAT_RETRYLATER:
      case STAT_RETRYNOW:
	 if (xfd->forever || xfd->retry--) {
	    if (result == STAT_RETRYLATER)  Nanosleep(&xfd->intervall, NULL);
	    continue;
	 }
#endif /* WITH_RETRY */
      default:
	 return result;
      }

#if WITH_RETRY
      if (dofork) {
	 pid_t pid;
	 while ((pid = Fork()) < 0) {
	    int level = E_ERROR;
	    if (xfd->forever || xfd->retry) {
	       level = E_WARN;
	    }
	    Msg1(level, "fork(): %s", strerror(errno));
	    if (xfd->forever || xfd->retry--) {
	       Nanosleep(&xfd->intervall, NULL);
	       continue;
	    }
	    return STAT_RETRYLATER;
	 }
	 if (pid == 0) {	/* child process */
	    Info1("just born: socks client process "F_pid, Getpid());
	    xfd->forever = false;  xfd->retry = 0;
	    break;
	 }
	 /* parent process */
	 Notice1("forked off child process "F_pid, pid);
	 Close(xfd->fd);
	 Nanosleep(&xfd->intervall, NULL);
	 dropopts(opts, PH_ALL); opts = copyopts(opts0, GROUP_ALL);
	 continue;
      } else
#endif /* WITH_RETRY */
      {
	 break;
      }

   } while (true);	/* end of complete open loop - drop out on success */
   return 0;
}


int _xioopen_socks4_prepare(const char *targetport, struct opt *opts, char **socksport, struct socks4 *sockhead, size_t *headlen) {
   struct servent *se;
   char *userid;

   /* generate socks header - points to final target */
   sockhead->version = 4;
   sockhead->action  = 1;
   sockhead->port    = parseport(targetport, "tcp");

   if (retropt_string(opts, OPT_SOCKSPORT, socksport) < 0) {
      if ((se = getservbyname("socks", "tcp")) != NULL) {
	 Debug1("\"socks/tcp\" resolves to %u", ntohs(se->s_port));
	 if ((*socksport = Malloc(6)) == NULL) {
	    return -1;
	 }
	 sprintf(*socksport, "%u", ntohs(se->s_port));
      } else {
	 Debug1("cannot resolve service \"socks/tcp\", using %s", SOCKSPORT);
	 if ((*socksport = strdup(SOCKSPORT)) == NULL) {
	    errno = ENOMEM;  return -1;
	 }
      }
   }

   if (retropt_string(opts, OPT_SOCKSUSER, &userid) < 0) {
      if ((userid = getenv("LOGNAME")) == NULL) {
	 if ((userid = getenv("USER")) == NULL) {
	    userid = "anonymous";
	 }
      }
   }
   strncpy(sockhead->userid, userid, *headlen-SIZEOF_STRUCT_SOCKS4);
   *headlen = SIZEOF_STRUCT_SOCKS4+strlen(userid)+1;
   return STAT_OK;
}


/* called within retry/fork loop, before connect() */
int
   _xioopen_socks4_connect0(struct single *xfd,
			    const char *hostname,	/* socks target host */
			    int socks4a,
			    struct socks4 *sockhead,
			    ssize_t *headlen,		/* get available space,
							   return used length*/
			    int level) {
   struct hostent *host = NULL;
   int result;

   if (!socks4a) {
      if ((result = xioGethostbyname(hostname, &host, level)) != STAT_OK) {
	 return result;
      }
   }

   if (!socks4a || host != NULL) {
      memcpy(&sockhead->dest, host->h_addr_list[0], 4);
   }
#if WITH_SOCKS4A
   else {
      /*! noresolve */
      sockhead->dest = htonl(0x00000001);	/* three bytes zero */
   }
#endif /* WITH_SOCKS4A */
#if WITH_SOCKS4A
   if (host == NULL) {
      /* SOCKS4A requires us to append the host name to resolve
         after the user name's trailing 0 byte.  */
      char* insert_position = (char*) sockhead + *headlen;

      strncpy(insert_position, hostname, BUFF_LEN-*headlen);
      ((char *)sockhead)[BUFF_LEN-1] = 0; //insert_position[BUFF_LEN-1] = 0;
      *headlen += strlen(hostname) + 1;
      if (*headlen > BUFF_LEN) {
	 *headlen = BUFF_LEN;
      }
   }
#endif /* WITH_SOCKS4A */
   return STAT_OK;
}


/* perform socks4 client dialog on existing FD.
   Called within fork/retry loop, after connect() */
int _xioopen_socks4_connect(struct single *xfd,
			    struct socks4 *sockhead,
			    size_t headlen,
			    int level) {
   ssize_t bytes;
   int result;
   unsigned char buff[SIZEOF_STRUCT_SOCKS4];
   struct socks4 *replyhead = (struct socks4 *)buff;

   /* send socks header (target addr+port, +auth) */
   Info("sending socks request");
   do {
      result = Write(xfd->fd, sockhead, headlen);
   } while (result < 0 && errno == EINTR);
   if (result < 0) {
      Msg4(level, "write(%d, %p, "F_Zu"): %s",
	   xfd->fd, sockhead, headlen, strerror(errno));
      if (Close(xfd->fd) < 0) {
	 Warn2("close(%d): %s", xfd->fd, strerror(errno));
      }
      return STAT_RETRYLATER;	/* retry complete open cycle */
   }

   bytes = 0;
   Info("waiting for socks reply");
   while (bytes >= 0) {	/* loop over answer chunks until complete or error */
      /* receive socks answer */
      do {
	 result = Read(xfd->fd, buff+bytes, SIZEOF_STRUCT_SOCKS4-bytes);
      } while (result < 0 && errno == EINTR);
      if (result < 0) {
	 Msg4(level, "read(%d, %p, "F_Zu"): %s",
	      xfd->fd, buff+bytes, SIZEOF_STRUCT_SOCKS4-bytes,
	      strerror(errno));
	 if (Close(xfd->fd) < 0) {
	    Warn2("close(%d): %s", xfd->fd, strerror(errno));
	 }
      }
      if (result == 0) {
	 Msg(level, "read(): EOF during read of socks reply");
	 if (Close(xfd->fd) < 0) {
	    Warn2("close(%d): %s", xfd->fd, strerror(errno));
	 }
	 return STAT_RETRYLATER;
      }
      bytes += result;
      if (bytes == SIZEOF_STRUCT_SOCKS4) {
	 Debug1("received all "F_Zd" bytes", bytes);
	 break;
      }
      Debug2("received "F_Zd" bytes, waiting for "F_Zu" more bytes",
	     result, SIZEOF_STRUCT_SOCKS4-bytes);
   }
   if (result <= 0) {	/* we had a problem while reading socks answer */
      return STAT_RETRYLATER;	/* retry complete open cycle */
   }

   Info7("socks answer: {%u, %u, %u, %u.%u.%u.%u}",
	 replyhead->version, replyhead->action, ntohs(replyhead->port),
	 ((uint8_t *)&replyhead->dest)[0],
	 ((uint8_t *)&replyhead->dest)[1],
	 ((uint8_t *)&replyhead->dest)[2],
	 ((uint8_t *)&replyhead->dest)[3]);
   if (replyhead->version != 0) {
      Warn1("socks: reply code version is not 0 (%d)",
	    replyhead->version);
   }

   switch (replyhead->action) {
   case SOCKS_CD_GRANTED:
      /* Notice("socks: connect request succeeded"); */
#if 0
      if (Getsockname(xfd->fd, (struct sockaddr *)&us, &uslen) < 0) {
	 Warn4("getsockname(%d, %p, {%d}): %s",
		xfd->fd, &us, uslen, strerror(errno));
      }
      Notice1("successfully connected from %s via socks",
	      sockaddr_info((struct sockaddr *)&us, infobuff, sizeof(infobuff)));
#else
      Notice("successfully connected via socks");
#endif
      break;

   case SOCKS_CD_FAILED:
      Msg(level, "socks: connect request rejected or failed");
      return STAT_RETRYLATER;

   case SOCKS_CD_NOIDENT:
      Msg(level, "socks: ident refused by client");
      return STAT_RETRYLATER;

   case SOCKS_CD_IDENTFAILED:
      Msg(level, "socks: ident failed");
      return STAT_RETRYLATER;

   default:
      Msg1(level, "socks: undefined status %u", replyhead->action);
   }

   return STAT_OK;
}
#endif /* WITH_SOCKS4 || WITH_SOCKS4A */

