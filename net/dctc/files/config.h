#ifndef ___CONFIG_H___
#define ___CONFIG_H___

/* To enable detecting of BSD systems */
#if (defined(__unix__) || defined(unix)) && !defined(USG)
#include <sys/param.h>
#endif

#include <sys/types.h>
#include <sys/socket.h>

/* For BSD */
#if (defined(BSD) && (BSD >= 199103))
# include <sys/ipc.h>
# include <sys/sem.h>
#else
/* For linux */
# include <linux/sem.h>     /* for the value of SEMVMX */
#endif

#ifndef MSG_NOSIGNAL
#define MSG_NOSIGNAL 0
#endif

#ifndef SEMVMX
/* this value comes from linux/sem.h */
#define SEMVMX 32767
#endif

#endif /* ___CONFIG_H___ */
