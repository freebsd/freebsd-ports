# $FreeBSD$

.PATH:	client common

PROG=	sixxs-heartbeatd
SRCS=	heartbeat-client.c hb.c common.c

DPADD=	${LIBMD}
LDADD=	-lmd

NOMAN=	yes

.include <bsd.prog.mk>
